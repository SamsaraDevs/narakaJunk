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
"FROM V0.11 TO V0.12:\n\
========================\n\
- Korax's speed has been slightly increased, as has the speed and damage of his Ethereal Wraith magic.\n\
- Coop powerups for the villains have had their power slightly enhanced.\n\
- Villains now get CoopModeOn when playing in coop games.\n\
- Korax's Green/Brown Chaos Magics have been combined into one Chaos Serpent Magic.\n\
- Korax now has Steel Chain magic to grab enemies at long range and yank them over to him.";