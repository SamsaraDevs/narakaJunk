#library "NARAKA"
#include "zcommon.acs"
#include "commonFuncs.h"

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


    Thing_SetTranslation(myTID, -1);
    //GiveInventory("Megasphere", 1);

    SetActivator(myTID);
    Thing_Remove(newTID);

}

script 255 (void) { }

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
}

script 571 ENTER   { ACS_ExecuteAlways(NARAKA_SPAWN, 0, 0,0,0); }
script 572 RESPAWN { ACS_ExecuteAlways(NARAKA_SPAWN, 0, 1,0,0); }

script NARAKA_SPAWN (int respawning) // This differs from 890 in that this works only once.
{
    int pNum = playerNumber();
    if (GameType() == GAME_SINGLE_PLAYER || GameType() == GAME_NET_COOPERATIVE)
    {
	    GiveInventory("CoopModeOn",1);
        if (CheckInventory("CyberdemonClass") == 1) { GiveInventory("CyberBeef", 1); }
        if (CheckInventory("DsparilClass") == 1)
        {
            DSparilHealth[pNum] = 200;
            SerpentArmor[pNum]  = 50;
            SerpentHealth[pNum] = 100;
            GiveInventory("DsparilBeef", 1);
        }
        if (CheckInventory("KoraxClass") == 1) { GiveInventory("KoraxBeef", 1); }
        if (CheckInventory("TfearClass") == 1) { GiveInventory("DsparilBeef", 1); }
    }

    if (isLMS())
    {
        ApplyLMS();
    }
	if(CheckInventory("TfearClass") == 1) { Thing_ChangeTID(0, 13150 + PlayerNumber()); }
}

script 473 (void)
{
    Thing_SetTranslation(0, -1);
}

/*script 474 (int cybermove) NET
{
    switch (cybermove)
    {
      case 1:
        SetActorProperty(0, APROP_Speed, 0.45);
        break;
        
      case 2:
        SetActorProperty(0, APROP_Speed, 0.15);
        break;
        
      case 3:
        SetActorProperty(0, APROP_Speed, 1.0);
        break;
    }
}*/

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
}

script 476 ENTER
{
    while (1)
    {
        if (CheckInventory("CyberdemonClass") == 1)
        {
            GiveInventory("VillainAmmoHeavy", 1);
        }
        delay(175);
    }
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

script 490 (void)
{
	if(GetCvar("sv_weaponstay") == 1)
		setresultvalue(1);
		else setresultvalue(0);
}

script 492 (void)
{
	if(GetCvar("samsara_permault") == 1)
		setresultvalue(1);
		else setresultvalue(0);
}

script 491 (int messageshit) CLIENTSIDE
{
	switch (messageshit)
	{
		case 1:
			if(GetCvar("samsara_cl_printpickup") == 1) { Print(s:"You feel your power surging."); }
			else { Log(s:"You feel your power surging."); }
			break;
			
		case 2:
			if(GetCvar("samsara_cl_printpickup") == 1) { Print(s:"You feel your arsenal expanding."); }
			else { Log(s:"You feel your arsenal expanding."); }
			break;
			
		case 3:
			if(GetCvar("samsara_cl_printpickup") == 1) { Print(s:"You feel your armor hardening."); }
			else { Log(s:"You feel your armor hardening."); }
			break;
			
		case 4:
			if(GetCvar("samsara_cl_printpickup") == 1) { Print(s:"You feel your arsenal expanding."); }
			else { Log(s:"You feel your arsenal expanding."); }
			break;
			
		case 5:
			if(GetCvar("samsara_cl_printpickup") == 1)	{ Print(s:"You feel utterly impenetrable."); }
			else	{ Log(s:"You feel utterly impenetrable."); }
			break;
			
		case 6:
			if(GetCvar("samsara_cl_printpickup") == 1)	{ Print(s:"You feel your strength has no limits."); }
			else { Log(s:"You feel your strength has no limits."); }
			break;
			
		case 7:
			if(CheckInventory("CyberdemonClass") == 1)
			{	if(GetCvar("samsara_cl_printpickup") == 1) { Print(s:"You got the Spider Mastermind's Chaingun! Show them Hell!"); }
				else { Log(s:"You got the Spider Mastermind's Chaingun! Show them Hell!"); }	}
			if(CheckInventory("DSparilClass") == 1)
			{	if(GetCvar("samsara_cl_printpickup") == 1) { Print(s:"Nope, nothin' yet."); }
				else { Log(s:"Nope, nothin' yet."); }	}
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
        // Dismount the Serpent. Spawn the Serpent actor in the player's current spot,
        // change its health accordingly, and morph the player to the D'Sparil On Foot class.
        if (Spawn("DSparilSerpentUnmounted", GetActorX(0), GetActorY(0), GetActorZ(0), serpentTID, GetActorAngle(0) >> 8 ) > 0)
        {
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
        // Dismount the Serpent. Spawn the Serpent actor in the player's current spot,
        // change its health accordingly, and morph the player to the D'Sparil On Foot class.
        if (Spawn("DSparilSerpentUnmountedTLMS", GetActorX(0), GetActorY(0), GetActorZ(0), serpentTID, GetActorAngle(0) >> 8 ) > 0)
        {
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

script 890 ENTER // This differs from Naraka_Spawn in that this is a constant loop to be played.
{
    int i;
	
	if(CheckInventory("IsNarakaClass") == 1)
	{
	
		// JUMPING SHIT
        if (CheckInventory("TfearClass") == 1)
		{
            if (GetCVar("samsara_nocustomgravity"))
			{ SetActorProperty(0, APROP_Gravity, 1.0); }
            else
			{ SetActorProperty(0, APROP_Gravity, 0.15); }
		}
		else
		{ SetActorProperty(0, APROP_Gravity, 1.0); }
		
        /*if (CheckInventory("KoraxClass") == 1);
		{ i = JumpZFromHeight(41 + GetCVar("samsara_jumpmod"), GetActorProperty(0, APROP_Gravity)); }
        if (CheckInventory("KoraxClass") == 0);
		{*/ i = JumpZFromHeight(32 + GetCVar("samsara_jumpmod"), GetActorProperty(0, APROP_Gravity)); //}

        SetActorProperty(0, APROP_JumpZ, max(i, 0));
		
		
		// POWERUPS SHIT
		// Because this seems to break on co-op
	    if(CheckInventory("GotWeapon0") == 1) { GiveInventory("CoopLesserBamf",1); }
		else { TakeInventory("CoopLesserBamf",1); }
	    if(CheckInventory("GotWeapon3") == 1) { GiveInventory("CoopBeefStringy",1); }
		else { TakeInventory("CoopBeefStringy",1); }
	    if(CheckInventory("GotWeapon5") == 1) { GiveInventory("CoopBeef",1); }
		else { TakeInventory("CoopBeef",1); }
	    if(CheckInventory("GotWeapon6") == 1) { GiveInventory("CoopBamf",1); }
		else { TakeInventory("CoopBamf",1); }
	}
    Delay(1);
	Restart;
}

//script 891 enter { ACS_ExecuteWithResult(890, 0,0,0); }
script 891 respawn { ACS_ExecuteWithResult(890, 0,0,0); }
script 892 return { ACS_ExecuteWithResult(890, 0,0,0); }

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

script 895 ENTER clientside
{
    if (PlayerNumber() != ConsolePlayerNumber()) { terminate; }
    if (GetCVar("teamlms") == 1)
	{
	    if (PlayerCount() >= 4)
	    {
		if (PlayerTeam() == 1)
		{
			if (GetTeamProperty(1,TPROP_NumPlayers) > GetTeamProperty(0,TPROP_NumPlayers))
			{ Print(s:"\cgVillains\cf have too many players!\n\n\cfSpectating in five...");
			delay(35);
			if (GetTeamProperty(1,TPROP_NumPlayers) > GetTeamProperty(0,TPROP_NumPlayers))
			{ Print(s:"\cgVillains\cf have too many players!\n\n\cfSpectating in four...");
			delay(35);
			if (GetTeamProperty(1,TPROP_NumPlayers) > GetTeamProperty(0,TPROP_NumPlayers))
			{ Print(s:"\cgVillains\cf have too many players!\n\n\cfSpectating in three...");
			delay(35);
			if (GetTeamProperty(1,TPROP_NumPlayers) > GetTeamProperty(0,TPROP_NumPlayers))
			{ Print(s:"\cgVillains\cf have too many players!\n\n\cfSpectating in two...");
			delay(35);
			if (GetTeamProperty(1,TPROP_NumPlayers) > GetTeamProperty(0,TPROP_NumPlayers))
			{ Print(s:"\cgVillains\cf have too many players!\n\n\cfSpectating in one...");
			delay(35);
			if (GetTeamProperty(1,TPROP_NumPlayers) > GetTeamProperty(0,TPROP_NumPlayers))
			{ ConsoleCommand("spectate"); }}}}}}
		}
		if (PlayerTeam() == 0)
		{
			if (GetTeamProperty(0,TPROP_NumPlayers) > (GetTeamProperty(1,TPROP_NumPlayers)*2))
			{ Print(s:"\chHeroes\cf have too many players!\n\n\cfSpectating in five...");
			delay(35);
			if (GetTeamProperty(0,TPROP_NumPlayers) > (GetTeamProperty(1,TPROP_NumPlayers)*2))
			{ Print(s:"\chHeroes\cf have too many players!\n\n\cfSpectating in four...");
			delay(35);
			if (GetTeamProperty(0,TPROP_NumPlayers) > (GetTeamProperty(1,TPROP_NumPlayers)*2))
			{ Print(s:"\chHeroes\cf have too many players!\n\n\cfSpectating in three...");
			delay(35);
			if (GetTeamProperty(0,TPROP_NumPlayers) > (GetTeamProperty(1,TPROP_NumPlayers)*2))
			{ Print(s:"\chHeroes\cf have too many players!\n\n\cfSpectating in two...");
			delay(35);
			if (GetTeamProperty(0,TPROP_NumPlayers) > (GetTeamProperty(1,TPROP_NumPlayers)*2))
			{ Print(s:"\chHeroes\cf have too many players!\n\n\cfSpectating in one...");
			delay(35);
			if (GetTeamProperty(0,TPROP_NumPlayers) > (GetTeamProperty(1,TPROP_NumPlayers)*2))
			{ ConsoleCommand("spectate"); }}}}}}
		}
	    }
	}
	delay(1);
	terminate;
}

/*script 896 open
{
    if (!GetCVar("naraka_teambalancer"))
    {   ConsoleCommand("set naraka_teambalancer 0");
    ConsoleCommand("archivecvar naraka_teambalancer"); }
}

script 897 (void)
{
	if(GetCvar("naraka_teambalancer") == 1)
		setresultvalue(1);
		else setresultvalue(0);
}*/