#library "NARAKA"
#include "zcommon.acs"
#include "commonFuncs.h"

#include "naraka_auto.h"
#include "naraka_admin.h"
#include "narakaDefs.h"

global int 61:SerpentArmor[];  // These two need to be
global int 62:SerpentHealth[]; // remembered between levels.

int DSparilHealth[PLAYERMAX];
int DSparilChasecam[PLAYERMAX];
int playerOnFoot[PLAYERMAX];

#include "narakaFuncs.h"

script 465 (void)
{
    int newTID = unusedTID(23000, 27000);
    int myTID  = defaultTID(-1);

    Spawn("TranslationHolder", GetActorX(0), GetActorY(0), GetActorZ(0)+8.0, newTID);
    Thing_SetTranslation(newTID, -1);

    ACS_ExecuteAlways(NARAKA_CAMERA, 0, PlayerNumber(), 0);
    MorphActor(0, "DSparilOnFootPlayer", "", 0x7FFFFFFF, 194, "NoTeleportFog", "NoTeleportFog");
    Thing_ChangeTID(0, myTID);
    SetActivator(newTID);

    if (GameType() == GAME_NET_COOPERATIVE)
    { SetActorProperty(0,APROP_Species,"Player"); }
    Thing_SetTranslation(myTID, -1);
    //GiveInventory("Megasphere", 1);

    SetActivator(myTID);
    Thing_Remove(newTID);

}

script 466 (int toggle)
{
    SetPlayerProperty(0, toggle, 4);
    ACS_ExecuteAlways(NARAKA_CAMERA, 0, PlayerNumber(), toggle);
}


script NARAKA_CAMERA (int pln, int toggle, int dist) clientside
{
    int angle, pitch;
    int cameraTID = unusedTID(27000, 32000);

    dist = cond(dist > 0, dist, 128);

    if (toggle == 1)
    {
        angle = -GetActorAngle(0);
        pitch = -0.05;
        Spawn("CameraDummy", GetActorX(0), GetActorY(0), GetActorZ(0)+8.0, cameraTID);
        ChangeCamera(cameraTID, 0, 0);
        DSparilChasecam[pln] = cameraTID;

        while (DSparilChasecam[pln] == cameraTID)
        {
            angle -= GetPlayerInput(-1, INPUT_YAW);
            pitch += GetPlayerInput(-1, INPUT_PITCH);
            angle = mod(angle, 1.0);
            pitch = middle(-0.1, pitch, 0.1);

            SetActorPosition(cameraTID,
                    GetActorX(0) + (dist * FixedMul(-cos(angle), cos(pitch))),
                    GetActorY(0) + (dist * FixedMul(sin(angle), cos(pitch))),
                    middle(GetActorFloorZ(0), GetActorZ(0) + 32.0 + (dist * -sin(pitch)), GetActorCeilingZ(0)),
                    0);

            SetActorAngle(cameraTID, -angle);
            SetActorPitch(cameraTID, -pitch);

            Delay(1);
        }

        Thing_Remove(cameraTID);
    }
    else
    {
        DSparilChasecam[pln] = 0;
    }
}

script 470 UNLOADING
{
    TakeInventory("DsparilPortTeleport", 10);
    TakeInventory("DsparilPortGhostsphere", 10);
    TakeInventory("GhostsphereCooldown", 100);
    TakeInventory("DSparilSummonCooldown", 100);
    TakeInventory("DSparilRevived", 10);
    TakeInventory("Staff of D'Sparil", 10);
    TakeInventory("CyberDash", 10);
    TakeInventory("CyberdemonDashCount", 999);
    TakeInventory("CyberdemonDashCooldown", 999);
    TakeInventory("ChaosDeviceCooldown", 999);
    TakeInventory("TfearCloak", 999);
    TakeInventory("TfearCloakCooldown", 999);
    TakeInventory("TfearCloakCount", 999);
    TakeInventory("TfearBeaconCooldown", 999);
    TakeInventory("RotorActive", 999);
    TakeInventory("DSparilDismountedSerpent", 999);
    TakeInventory("PowerShadow", 999);
    TakeInventory("DSparilMount", 999);
    TakeInventory("TfearSummonLimit", 999);
    TakeInventory("AbandonRemoteLaunched", 999);
    TakeInventory("DSparilTeleportLimiter", 999);
}

script 571 ENTER   { ACS_ExecuteAlways(NARAKA_SPAWN, 0, 0,0,0); }
script 572 RESPAWN { ACS_ExecuteAlways(NARAKA_SPAWN, 0, 1,0,0); }

script NARAKA_SPAWN (int respawning) // This differs from 890 in that this works only once.
{
    int pNum = playerNumber();
	
	if (GetCvar("naraka_teambalancer") == 1) { ACS_ExecuteAlways(895,0,0); }
	if (GetCvar("naraka_teambalancer") == 2) { ACS_ExecuteAlways(897,0,0); }
	
    if (GameType() == GAME_SINGLE_PLAYER || GameType() == GAME_NET_COOPERATIVE)
    {
		if (GameType () == GAME_NET_COOPERATIVE) { GiveInventory("CoopModeOn",1);
	    SetActorProperty(0,APROP_Species,"Player");}
		
        if (CheckInventory("CyberdemonClass") == 1) { GiveInventory("CyberBeef", 1); }
        if (CheckInventory("DsparilClass") == 1)
        {
			//Print(s:"I'm working! - Enter");
			//if (CheckInventory("DsparilMount") == 1) {
			TakeInventory("DsparilMount", 1);
			GiveInventory("DsparilDismount", 1); //}
            DSparilHealth[pNum] = 200;
            SerpentArmor[pNum]  = 50;
            SerpentHealth[pNum] = 100;
            GiveInventory("DsparilBeef", 1);
        }
        if (CheckInventory("KoraxClass") == 1) { GiveInventory("KoraxBeef", 1); }
        if (CheckInventory("TfearClass") == 1) { GiveInventory("DsparilBeef", 1); }
        if (CheckInventory("HitlerClass") == 1) { GiveInventory("HitlerBeef", 1); }
    }

    if (isLMS())
    {
        ApplyLMS();
		if(CheckInventory("HitlerClass") == 1) { GiveInventory("HitlerAmmoCrate",1); }
    }
	if(CheckInventory("TfearClass") == 1) { Thing_ChangeTID(0, 13150 + PlayerNumber()); }
}

script 473 (int miscshit)
{
    switch (miscshit)
    {
	case 0:
        Thing_SetTranslation(0, -1);
		break;
		
	case 1:
	    if(GetCvar("sv_weaponstay") == 1)
		setresultvalue(1);
		else setresultvalue(0);
		break;
		
	case 2:
	    if(GetCvar("samsara_permault") == 1)
		setresultvalue(1);
		else setresultvalue(0);
		break;
		
    case 3:
	    GiveInventory("HitlerLostArmor",1);
	    //SetActorProperty(0,APROP_Speed,1.55);
	    break;
    
	case 4:
	    TakeInventory("HitlerLostArmor",1);
	    //SetActorProperty(0,APROP_Speed,1.00);
	    SetActorState(0,"Spawn");
	    break;
	}
}

script 474 (int cybermove) // It's time to D-D-D-DASH!
{
    switch (cybermove)
    {
      case 1:
        if (CheckInventory("CyberDash") == 0)
        {
            ActivatorSound("cyber/dashon", 127);
            print(s:"Diverting Power to Mobile Systems");
            GiveInventory("CyberdemonDashCount", 42);
            delay(30);
            GiveInventory("CyberDash", 1);
            ACS_ExecuteAlways(NARAKA_COOLDOWN, 0, 2, 7, 474);
        }
        break;

      case 0:
        if (CheckInventory("CyberDash") == 1)
        {
            ActivatorSound("cyber/dashoff", 127);
            print(s:"Restoring Power to Weapon Systems");
            GiveInventory("CyberdemonDashCooldown", 210);
            TakeInventory("CyberdemonDashCount", 0x7FFFFFFF);
            delay(20);
            TakeInventory("CyberDash", 1);
            ACS_ExecuteAlways(NARAKA_COOLDOWN, 0, 3, 7);
        }
        break;
    }
}

script 475 (void) // D'Sparil's life-giving on Serpent kersploding.
{
    int pNum = playerNumber();
    if (isLMS())
    {
        if (GetCvar("samsara_lmslife") == 1)
        {
            SetActorProperty(0, APROP_HEALTH, DSparilHealth[pNum]);
            //GiveInventory("DsparilLMSArmor1", 1);
        }
        if (GetCvar("samsara_lmslife") == 2)
        {
            SetActorProperty(0, APROP_HEALTH, DSparilHealth[pNum]);
            GiveInventory("DsparilLMSHealth2", 50);
            //GiveInventory("DsparilLMSArmor2", 1);
        }
        if (GetCvar("samsara_lmslife") == 3)
        {
            SetActorProperty(0, APROP_HEALTH, DSparilHealth[pNum]);
            GiveInventory("DsparilLMSHealth3", 50);
            //GiveInventory("DsparilLMSArmor3", 1);
        }
        if (GetCvar("samsara_lmslife") == 4)
        {
            SetActorProperty(0, APROP_HEALTH, DSparilHealth[pNum]);
            GiveInventory("DsparilLMSHealth4", 50);
            //GiveInventory("DsparilLMSArmor4", 1);
        }
        if (GetCvar("samsara_lmslife") == 5)
        {
            SetActorProperty(0, APROP_HEALTH, DSparilHealth[pNum]);
            GiveInventory("DsparilLMSHealth5", 50);
            //GiveInventory("DsparilLMSArmor5", 1);
        }
    }
    else
    {
        SetActorProperty(0, APROP_HEALTH, DSparilHealth[pNum]);
        GiveInventory("HealthBonus", 50);
        //GiveInventory("Megasphere", 1);
    }
	if (isCoop())
	{ SetActorProperty(0, APROP_Species,"Player"); }
}

script 480 (int cloakanddagger) // It's time to H-H-H-HIDE!
{
    switch (cloakanddagger)
    {
      case 0:
        if (CheckInventory("TfearCloak") == 0 && CheckInventory("PowerShadow") == 0) { break; }

        ActivatorSound("tfear/uncloak", 127);
        print(s:"You discard the shadows behind you...");
        GiveInventory("TfearCloakCooldown", ftoi(1.5 * (21-CheckInventory("TfearCloakCount"))));
        delay(2);
        TakeInventory("TfearCloakCount", 20);
        delay(2);
        ACS_ExecuteAlways(484, 0, 6, 35);

        if (GameType() == GAME_SINGLE_PLAYER || GameType() == GAME_NET_COOPERATIVE)
        {
            TakeInventory("PowerShadow", 1);
            delay(1);
            TakeInventory("PowerShadow", 1);
        }
        else
        {
            TakeInventory("TfearCloak", 1);
        }
        break;
        
      case 1:
        if (CheckInventory("TfearCloak") > 0) { break; }

        ActivatorSound("tfear/cloak", 127);
        print(s:"You fade into the shadows...");
        GiveInventory("TfearCloakCount", 20);
        delay(5);
        ACS_ExecuteAlways(484, 0, 5, 35, 480);

        if (GameType() == GAME_SINGLE_PLAYER || GameType() == GAME_NET_COOPERATIVE)
        {
            GiveInventory("PowerShadow", 1);
            delay(1);
            GiveInventory("PowerShadow", 1);
        }
        else
        {
            GiveInventory("TfearCloak", 1);
        }
        break;
    }
}

script 491 (int messageshit) CLIENTSIDE
{
    if (PlayerNumber() != ConsolePlayerNumber()) { terminate; }
	switch (messageshit)
	{
		case 1:
			if(GetCvar("samsara_cl_printpickup") == 1) { Print(s:"VILLAIN POWER: Light Damage Buff"); }
			else { Log(s:"VILLAIN POWER: Light Damage Buff"); }
			break;
			
		case 2:
			if(GetCvar("samsara_cl_printpickup") == 1) { Print(s:"VILLAIN POWER: Armor Regeneration"); }
			else { Log(s:"VILLAIN POWER: Armor Regeneration"); }
			break;
			
		case 3:
			if(GetCvar("samsara_cl_printpickup") == 1) { Print(s:"VILLAIN POWER: Light Armor Buff"); }
			else { Log(s:"VILLAIN POWER: Light Armor Buff"); }
			break;
			
		case 4:
			if(GetCvar("samsara_cl_printpickup") == 1) { Print(s:"VILLAIN POWER: Health Regeneration"); }
			else { Log(s:"VILLAIN POWER: Health Regeneration"); }
			break;
			
		case 5:
			if(GetCvar("samsara_cl_printpickup") == 1)	{ Print(s:"VILLAIN POWER: Heavy Armor Buff"); }
			else	{ Log(s:"VILLAIN POWER: Heavy Armor Buff"); }
			break;
			
		case 6:
			if(GetCvar("samsara_cl_printpickup") == 1)	{ Print(s:"VILLAIN POWER: Heavy Damage Buff"); }
			else { Log(s:"VILLAIN POWER: Heavy Damage Buff"); }
			break;
			
		case 7:
			if(CheckInventory("CyberdemonClass") == 1)
			{	if(GetCvar("samsara_cl_printpickup") == 1) { Print(s:"You got the Spider Mastermind's Chaingun! Show them Hell!"); }
				else { Log(s:"You got the Spider Mastermind's Chaingun! Show them Hell!"); }	}
			if(CheckInventory("DSparilClass") == 1)
			{	if(GetCvar("samsara_cl_printpickup") == 1) { Print(s:"Nope, nothin' yet."); }
				else { Log(s:"Nope, nothin' yet."); }	}
			if(CheckInventory("HitlerClass") == 1)
			{	if(GetCvar("samsara_cl_printpickup") == 1) { Print(s:"You got the Vierfach Panzerschreck! Vorwarts! Vorwarts!"); }
				else { Log(s:"You got the Vierfach Panzerschreck! Vorwarts! Vorwarts!"); }	}
			if(CheckInventory("KoraxClass") == 1)
			{	if(GetCvar("samsara_cl_printpickup") == 1) { Print(s:"Nope, nothin' yet."); }
				else { Log(s:"Nope, nothin' yet."); }	}
			if(CheckInventory("TfearClass") == 1)
			{	if(GetCvar("samsara_cl_printpickup") == 1) { Print(s:"Nope, nothin' yet."); }
				else { Log(s:"Nope, nothin' yet."); }	}
			break;
			
		case 8:
			if(CheckInventory("CyberdemonClass") == 1)
			{	if(GetCvar("samsara_cl_printpickup") == 1) { Print(s:"You got a Targeting System! Hell yes."); }
				else { Log(s:"You got a Targeting System! Hell yes."); }	}
			if(CheckInventory("DSparilClass") == 1)
			{	if(GetCvar("samsara_cl_printpickup") == 1) { Print(s:"Nope, nothin' yet."); }
				else { Log(s:"Nope, nothin' yet."); }	}
			if(CheckInventory("HitlerClass") == 1)
			{	if(GetCvar("samsara_cl_printpickup") == 1) { Print(s:"Nope, nothin' yet."); }
				else { Log(s:"Nope, nothin' yet."); }	}
			if(CheckInventory("KoraxClass") == 1)
			{	if(GetCvar("samsara_cl_printpickup") == 1) { Print(s:"Nope, nothin' yet."); }
				else { Log(s:"Nope, nothin' yet."); }	}
			if(CheckInventory("TfearClass") == 1)
			{	if(GetCvar("samsara_cl_printpickup") == 1) { Print(s:"Nope, nothin' yet."); }
				else { Log(s:"Nope, nothin' yet."); }	}
			break;
	}
}

script NARAKA_COOLDOWN (int index, int delayTime, int endScript)
{
    if (index < 0 || index >= COOLDOWNITEMCOUNT)
    {
        Log(s:"\caERROR:\c- Called script ", d:NARAKA_COOLDOWN, s:" with invalid item index ", d:index);
        printDebugInfo();
        terminate;
    }

    int toCool = CooldownItems[index];  // too cool

    while (CheckInventory(toCool))
    {
        Delay(delayTime);
        TakeInventory(toCool, 1);
    }

    if (endScript != 0)
    {
        if (endScript < 0) { ACS_ExecuteWithResult(endScript); }
        else { ACS_ExecuteAlways(endScript, 0); }
    }
}

script 888 (int ent)
{
    int pNum = PlayerNumber();
    int serpentTID = 1500+pNum;	
    if (!ent) {
	    //Print(s:"I'm working! - Normal - Unspawned");
        // Dismount the Serpent. Spawn the Serpent actor in the player's current spot,
        // change its health accordingly, and morph the player to the D'Sparil On Foot class.
        if (Spawn("DSparilSerpentUnmounted", GetActorX(0), GetActorY(0), GetActorZ(0), serpentTID, GetActorAngle(0) >> 8 ) > 0)
        {
			//Print(s:"I'm working! - Normal - Spawned");
            Thing_SetTranslation(serpentTID, -1); // Make the Serpent use the translation the Player is!
            SetActorProperty(serpentTID, APROP_HEALTH, GetActorProperty(0, APROP_HEALTH) * 5);
            ThingSound(serpentTID, "dsparilserpent/active", 255);
            // Takes the player's current health and multiplies it by 5 for the Serpent.
            // Getting off the Serpent earlier means tankier Serpent!
            
            SerpentArmor [pNum] = CheckInventory("Armor");
            SerpentHealth[pNum] = GetActorProperty(0, APROP_HEALTH);
            
			int newTID = unusedTID(23000, 25000);
			int myTID  = defaultTID(-1);
			Spawn("TranslationHolder", GetActorX(0), GetActorY(0), GetActorZ(0)+8.0, newTID);
			Thing_SetTranslation(newTID, -1);

			MorphActor(0, "DSparilOnFootPlayer", "", 0x7FFFFFFF, 194, "emptytelefog", "emptytelefog");
			Thing_ChangeTID(0, myTID);
			SetActivator(newTID);

			Thing_SetTranslation(myTID, -1);
			//GiveInventory("Megasphere", 1);

			SetActivator(myTID);
			Thing_Remove(newTID);
	
            SetActorProperty(0, APROP_HEALTH, DSparilHealth[pNum]);
            GiveInventory("DSparilDismountedSerpent", 1);
            TakeInventory("DSparilDismount", 1);
            GiveInventory("DSparilMount", 1);
            playerOnFoot[pNum] = 1;
        }
        
    }
    else
    {
        // Mount the Serpent.
        // Can't get on the Serpent if it's dead!
			//Print(s:"I'm working! - Normal - Mount");
        if (ThingCount(0, serpentTID) > 0) {
            // Check if the player is close enough to the Serpent, then
            // remove the Serpent actor and morph the player back.
            int x = (GetActorX(serpentTID) - GetActorX(0)) >> 16;
            int y = (GetActorY(serpentTID) - GetActorY(0)) >> 16;
            int z = (GetActorZ(serpentTID) - GetActorZ(0)) >> 16;		
            if (z < 0) z = 0-z; // get abs of Z
            
            if (sqrt_i(x*x + y*y) <= 128 && z <= 128) {
                ThingSound(serpentTID, "dsparilserpent/active", 255);
                Thing_Remove(serpentTID);
                
                DSparilHealth[pNum] = GetActorProperty(0, APROP_HEALTH);
                
                UnmorphActor(0, 1);
                GiveInventory("DSparilSerpentArmor", SerpentArmor[pNum]);
                SetActorProperty(0, APROP_HEALTH, SerpentHealth[pNum]);
                
                TakeInventory("DSparilDismountedSerpent", 1);
                GiveInventory("DSparilDismount", 1);
                TakeInventory("DSparilMount", 1);
                playerOnFoot[pNum] = 0;
            }
        }
    }
}

script 889 (int ent)
{
    int pNum = PlayerNumber();
    int serpentTID = 1500+pNum;	
    if (!ent) {
			//Print(s:"I'm working! - TLMS - Unspawned");
        // Dismount the Serpent. Spawn the Serpent actor in the player's current spot,
        // change its health accordingly, and morph the player to the D'Sparil On Foot class.
        if (Spawn("DSparilSerpentUnmountedTLMS", GetActorX(0), GetActorY(0), GetActorZ(0), serpentTID, GetActorAngle(0) >> 8 ) > 0)
        {
			//Print(s:"I'm working! - TLMS - Spawned");
            Thing_SetTranslation(serpentTID, -1); // Make the Serpent use the translation the Player is!
            SetActorProperty(serpentTID, APROP_HEALTH, GetActorProperty(0, APROP_HEALTH) * 5);
            ThingSound(serpentTID, "dsparilserpent/active", 255);
            // Takes the player's current health and multiplies it by 5 for the Serpent.
            // Getting off the Serpent earlier means tankier Serpent!
            
            SerpentArmor [pNum] = CheckInventory("Armor");
            SerpentHealth[pNum] = GetActorProperty(0, APROP_HEALTH);
            
			int newTID = unusedTID(23000, 25000);
			int myTID  = defaultTID(-1);
			Spawn("TranslationHolder", GetActorX(0), GetActorY(0), GetActorZ(0)+8.0, newTID);
			Thing_SetTranslation(newTID, -1);

			MorphActor(0, "DSparilOnFootPlayer", "", 0x7FFFFFFF, 194, "emptytelefog", "emptytelefog");
			Thing_ChangeTID(0, myTID);
			SetActivator(newTID);

			Thing_SetTranslation(myTID, -1);
			//GiveInventory("Megasphere", 1);

			SetActivator(myTID);
			Thing_Remove(newTID);
	
            SetActorProperty(0, APROP_HEALTH, DSparilHealth[pNum]);
            GiveInventory("DSparilDismountedSerpent", 1);
            TakeInventory("DSparilDismount", 1);
            GiveInventory("DSparilMount", 1);
            playerOnFoot[pNum] = 1;
        }
        
    }
    else
    {
        // Mount the Serpent.
        // Can't get on the Serpent if it's dead!
			//Print(s:"I'm working! - TLMS - Mount");
        if (ThingCount(0, serpentTID) > 0) {
            // Check if the player is close enough to the Serpent, then
            // remove the Serpent actor and morph the player back.
            int x = (GetActorX(serpentTID) - GetActorX(0)) >> 16;
            int y = (GetActorY(serpentTID) - GetActorY(0)) >> 16;
            int z = abs(GetActorZ(serpentTID) - GetActorZ(0)) >> 16;		
            
            if (sqrt_i(x*x + y*y) <= 128 && z <= 128)
            {
                ThingSound(serpentTID, "dsparilserpent/active", 255);
                Thing_Remove(serpentTID);
                
                DSparilHealth[pNum] = GetActorProperty(0, APROP_HEALTH);
                
                UnmorphActor(0, 1);
                GiveInventory("DSparilSerpentArmor", SerpentArmor[pNum]);
                SetActorProperty(0, APROP_HEALTH, SerpentHealth[pNum]);
                
                TakeInventory("DSparilDismountedSerpent", 1);
                GiveInventory("DSparilDismount", 1);
                TakeInventory("DSparilMount", 1);
                playerOnFoot[pNum] = 0;
            }
        }
    }
}

script 893 (void)
{ 
	int tid = GetActorProperty(0, APROP_MASTERTID);
	TakeActorInventory(tid, "TfearSummonLimit", 1);
}

script 894 (int changelogshit2) NET CLIENTSIDE
{
switch (changelogshit2)
{
        case 1:
        Log(s:ChangelogNaraka);
        break;
		
        /*case 2:
        SetHudSize(1024,768,1);
        SetFont("");
        HudMessage(s:"";HUDMSG_PLAIN,1,1,512.0,384.0,0);
        break;*/
}
}

script 896 (int ent)
{
    int pNum = PlayerNumber();
    int serpentTID = 1500+pNum;	
    if (!ent) {
			//Print(s:"I'm working! - Coop - Unspawned");
        // Dismount the Serpent. Spawn the Serpent actor in the player's current spot,
        // change its health accordingly, and morph the player to the D'Sparil On Foot class.
        if (Spawn("DSparilSerpentUnmountedCoop", GetActorX(0), GetActorY(0), GetActorZ(0), serpentTID, GetActorAngle(0) >> 8 ) > 0)
        {
			//Print(s:"I'm working! - Coop - Spawned");
            Thing_SetTranslation(serpentTID, -1); // Make the Serpent use the translation the Player is!
            SetActorProperty(serpentTID, APROP_HEALTH, GetActorProperty(0, APROP_HEALTH) * 5);
            ThingSound(serpentTID, "dsparilserpent/active", 255);
            // Takes the player's current health and multiplies it by 5 for the Serpent.
            // Getting off the Serpent earlier means tankier Serpent!
            
            SerpentArmor [pNum] = CheckInventory("Armor");
            SerpentHealth[pNum] = GetActorProperty(0, APROP_HEALTH);
            
			int newTID = unusedTID(23000, 25000);
			int myTID  = defaultTID(-1);
			Spawn("TranslationHolder", GetActorX(0), GetActorY(0), GetActorZ(0)+8.0, newTID);
			Thing_SetTranslation(newTID, -1);

			MorphActor(0, "DSparilOnFootPlayer", "", 0x7FFFFFFF, 194, "emptytelefog", "emptytelefog");
			Thing_ChangeTID(0, myTID);
			SetActivator(newTID);

			Thing_SetTranslation(myTID, -1);
			//GiveInventory("Megasphere", 1);

			SetActivator(myTID);
			Thing_Remove(newTID);
	    
		
		    SetActorProperty(0, APROP_Species,"Player");
            SetActorProperty(0, APROP_HEALTH, DSparilHealth[pNum]);
            GiveInventory("DSparilDismountedSerpent", 1);
            TakeInventory("DSparilDismount", 1);
            GiveInventory("DSparilMount", 1);
            playerOnFoot[pNum] = 1;
        }
        
    }
    else
    {
        // Mount the Serpent.
        // Can't get on the Serpent if it's dead!
			//Print(s:"I'm working! - Coop - Mount");
        if (ThingCount(0, serpentTID) > 0) {
            // Check if the player is close enough to the Serpent, then
            // remove the Serpent actor and morph the player back.
            int x = (GetActorX(serpentTID) - GetActorX(0)) >> 16;
            int y = (GetActorY(serpentTID) - GetActorY(0)) >> 16;
            int z = abs(GetActorZ(serpentTID) - GetActorZ(0)) >> 16;		
            
            if (sqrt_i(x*x + y*y) <= 128 && z <= 128)
            {
                ThingSound(serpentTID, "dsparilserpent/active", 255);
                Thing_Remove(serpentTID);
                
                DSparilHealth[pNum] = GetActorProperty(0, APROP_HEALTH);
                
                UnmorphActor(0, 1);
                GiveInventory("DSparilSerpentArmor", SerpentArmor[pNum]);
                SetActorProperty(0, APROP_HEALTH, SerpentHealth[pNum]);
                
                TakeInventory("DSparilDismountedSerpent", 1);
                GiveInventory("DSparilDismount", 1);
                TakeInventory("DSparilMount", 1);
                playerOnFoot[pNum] = 0;
            }
        }
    }
}

/*script 898 ENTER
{
while (1)
{ if (CheckInventory("HitlerClass") == 1)
  { if (CheckInventory("Health") > 0)
    { if (!CheckInventory("HitlerLostArmor"))
      { if (!CheckInventory("Armor"))
        { SetActorState(0,"LoseMech"); } } }}
delay(1); }
}*/

/*script 898 (void)
{
if (CheckInventory("Armor"))
{
Print(s:"I'm armored!");
}
}*/