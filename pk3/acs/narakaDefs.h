#define NARAKA_COOLDOWN     484
#define NARAKA_CAMERA       485
#define NARAKA_SPAWN        573

#define CLASSCOUNT 4
#define COOLDOWNITEMCOUNT 8

#define LMSMODES 6

int NarakaClassItems[CLASSCOUNT] = 
{
    "CyberdemonClass",
    "DSparilClass",
    "KoraxClass",
    "TfearClass",
};

int CooldownItems[COOLDOWNITEMCOUNT] =
{
    "GhostsphereCooldown",
    "DSparilSummonCooldown",
    "CyberdemonDashCount",
    "CyberdemonDashCooldown",
    "ChaosDeviceCooldown",
    "TfearCloakCount",
    "TfearCloakCooldown",
    "TfearBeaconCooldown",
};

int LMSLifeHPs[CLASSCOUNT][LMSMODES] = 
{
    {200, 200, 400, 600, 800, 1000},
    {150, 150, 250, 350, 450, 550},
    {150, 150, 300, 450, 600, 750},
    {100, 100, 200, 300, 400, 500},
};

int DSparilHPs[LMSMODES] = {100, 100, 200, 300, 400, 500};

int LMSLifeArmors[CLASSCOUNT][LMSMODES] = 
{
    {"", "CyberLMSArmor1",   "CyberLMSArmor2",   "CyberLMSArmor3",   "CyberLMSArmor4",   "CyberLMSArmor5"},  
    {"", "DSparilLMSArmor1", "DSparilLMSArmor2", "DSparilLMSArmor3", "DSparilLMSArmor4", "DSparilLMSArmor5"}, 
    {"", "KoraxLMSArmor1",   "KoraxLMSArmor2",   "KoraxLMSArmor3",   "KoraxLMSArmor4",   "KoraxLMSArmor5"},   
    {"", "TfearLMSArmor1",   "TfearLMSArmor2",   "TfearLMSArmor3",   "TfearLMSArmor4",   "TfearLMSArmor5"},   
};

int LMSUlts[CLASSCOUNT] = 
{
    "Master Chaingun",
    "",
    "",
    "",
};

int LMSUniques[CLASSCOUNT] = 
{
    "CyberTargeter",
    "",
    "",
    "",
};

int ChangelogNaraka =
"FROM V0.1 TO V0.11e:\n\
========================\n\
- Korax has been added as Parias' villain.\n\
- The villains are now resistant to everyone's VIs.\n\
- D'Sparil can mount and dismount his Serpent at will.\n\
- Villains should be more resistant to axing.\n\
- Tfear and his Pfhor Troopers should now spew the proper-colored gibs.\n\
- The Disciples of D'Sparil have been buffed and now have more HP and more damaging attacks.\n\
- The Cyberdemon's rocket launch and explosion sounds are different from Doomguy's, for easier identification.\n\
- The Cyberdemon now has his unique item and BFG.\n\
- D'Sparil on foot getting hurt with the Zorchers or ice no longer regains him his health.\n\
- Tfear's Flawed zoom-in is now much faster.\n\
- Tfear's Guilt no longer raises instantly. Does raise and lower faster than before, though.\n\
- D'Sparil's death sequence now properly shows his translation.\n\
- Villains now respect samsara_jumpmod.\n\
- Villain ammo and weapon pickups now flash the screen like normal pickups.\n\
- The Cyberdemon's rockets have a less static-y launch sound and have twice the rolloff.\n\
- Naraka weapon pickup buffs now persist from level to level.\n\
- Naraka's health pickups now support infinite health.\n\
- Tfear now can only have four Troopers out at one time.\n\
- Implemented Naraka changelog.\n\
- With the summon limit in place, Tfear's summon cooldown has been reduced from 30 to 21.\n\
- D'Sparil's serpent now moves faster, bites harder and faster, and heals itself slightly on every bite. On dismount, it also pauses momentarily, for people who like to dismount, summon, and remount.\n\
- D'Sparil on his Serpent should now zorch properly.\n\
- D'Sparil's zorch effect is no longer green.\n\
- Cyberdemon should now freeze properly, and his freeze roar should now play properly.\n\
- D'Sparil's sprites have been converted to .png. Not sure why they weren't already.\n\
- Weapon pickup messages have been clientsided, so now the server doesn't speak every time someone picks up a weapon.\n\
- D'Sparil's firing/melee animations should now show properly to spectators.\n\
- SBARINFO updated to 0.29b's SBARINFO.\n\
- The Pfhor Troopers now have their own Duke gib sequence and sprites, thanks to President People.\n\
- A primitive team balancer has been implemented. It checks to see if there are more villains than heroes, or if there's twice as many heroes than villains, and if so forces the joinee to spectate.";