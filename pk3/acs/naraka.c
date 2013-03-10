#library "NARAKA"
#include "zcommon.acs"
#include "commonFuncs.h"

#include "narakaDefs.h"

global int 61:SerpentArmor[];  // These two need to be
global int 62:SerpentHealth[]; // remembered between levels.

int DSparilHealth[PLAYERMAX];
int playerOnFoot[PLAYERMAX];

#include "narakaFuncs.h"

script 465 (void)
{
    MorphActor(0, "DSparilOnFootPlayer", "", 0x7FFFFFFF, 194, "emptytelefog", "emptytelefog");
    //GiveInventory("Megasphere", 1);
}

script 255 (void)
{
}

script 466 (int toggle)
{
    SetPlayerProperty(0, toggle, 4);
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
}

script 571 ENTER   { ACS_ExecuteAlways(NARAKA_SPAWN, 0, 0,0,0); }
script 572 RESPAWN { ACS_ExecuteAlways(NARAKA_SPAWN, 0, 1,0,0); }

script NARAKA_SPAWN (int respawning)
{
    int pNum = playerNumber();
    if (GameType() == GAME_SINGLE_PLAYER || GameType() == GAME_NET_COOPERATIVE)
    {
        if (CheckInventory("CyberdemonClass") == 1)
        {
            GiveInventory("CyberBeef", 1);
        }
        if (CheckInventory("DsparilClass") == 1)
        {
            DSparilHealth[pNum] = 200;
            SerpentArmor[pNum]  = 50;
            SerpentHealth[pNum] = 100;
            GiveInventory("DsparilBeef", 1);
        }
        if (CheckInventory("KoraxClass") == 1)
        {
            GiveInventory("KoraxBeef", 1);
        }
    }

    if (isLMS())
    {
        ApplyLMS();
    }
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
            
            MorphActor(0, "DSparilOnFootPlayer", "", 0x7FFFFFFF, 194, "emptytelefog", "emptytelefog");
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
            
            MorphActor(0, "DSparilOnFootPlayer", "", 0x7FFFFFFF, 194, "emptytelefog", "emptytelefog");
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
