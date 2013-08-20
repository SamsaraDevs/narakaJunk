#define NARAKA_COOLDOWN     484
#define NARAKA_CAMERA       485
#define NARAKA_SPAWN        573

#define CLASSCOUNT 5
#define COOLDOWNITEMCOUNT 8

#define LMSMODES 6

int NarakaClassItems[CLASSCOUNT] = 
{
    "CyberdemonClass",
    "DSparilClass",
    "HitlerClass",
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
    {100, 100, 200, 300, 400, 500},
    {150, 150, 300, 450, 600, 750},
    {100, 100, 200, 300, 400, 500},
};

int DSparilHPs[LMSMODES] = {100, 100, 200, 300, 400, 500};

int LMSLifeArmors[CLASSCOUNT][LMSMODES] = 
{
    {"", "CyberLMSArmor1",   "CyberLMSArmor2",   "CyberLMSArmor3",   "CyberLMSArmor4",   "CyberLMSArmor5"},  
    {"", "DSparilLMSArmor1", "DSparilLMSArmor2", "DSparilLMSArmor3", "DSparilLMSArmor4", "DSparilLMSArmor5"},
    {"", "HitlerLMSArmor1",  "HitlerLMSArmor2",  "HitlerLMSArmor3",  "HitlerLMSArmor4",  "HitlerLMSArmor5"},  
    {"", "KoraxLMSArmor1",   "KoraxLMSArmor2",   "KoraxLMSArmor3",   "KoraxLMSArmor4",   "KoraxLMSArmor5"},   
    {"", "TfearLMSArmor1",   "TfearLMSArmor2",   "TfearLMSArmor3",   "TfearLMSArmor4",   "TfearLMSArmor5"},   
};

int LMSUlts[CLASSCOUNT] = 
{
    "Master Chaingun",
    "",
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
    "",
};

int ChangelogNaraka =
"FROM V0.11 TO V0.12:\n\
========================\n\
- Korax's speed has been slightly increased, as has the speed and damage of his Ethereal Wraith magic.\n\
- Coop powerups for the villains have had their power slightly enhanced.\n\
- Villains now get CoopModeOn when playing in coop games.\n\
- Korax's Green/Brown Chaos Magics have been combined into one Chaos Serpent Magic.\n\
- Korax now has Steel Chain magic to grab enemies at long range and yank them over to him.\n\
- Team balancer now runs after 5 people join the game, and now only runs on the joining team.\n\
- Vllain pickup messages no longer display globally.\n\
- D'Sparil can now dismount after respawning.\n\
- Tfear's Flawed now runs off Light ammo, rather than Heavy.\n\
- Admiral Tfear now has a new weapon: The Predator Type 'Abandon', a rapid-fire grenade launcher that arcs low and bounces, allowing him to cover an area.\n\
- The Hatred's projectiles now move a slight bit faster, for slightly easier hitting.\n\
- Guilt's lunge no longer uses ammo, and comes out slightly faster.\n\
- Korax's death sequence has been completely reworked in DECORATE, thanks to Popsoap.\n\
- Admiral Tfear did not have any CoopMode or TLMS mode checks for his weapons, meaning all his attacks would get stuck on allies. This has been fixed.\n\
- The Cyberdemon and D'Sparil now have proper bar HUDs. Only two more to go!\n\
- Spectating unmounted D'Sparil now no longer results in an HOM.\n\
- Tfear's Pfhor summons now can no longer be summoned in the environment and rendered useless.\n\
- Tfear's Pfhor now have a more Marathon-esque teleport sequence.\n\
- The HUDs now work in the automap.\n\
- Admiral Tfear now has (some of) his proper sprites!\n\
- Summoned Pfhor now inherit colors from their summoner.\n\
- By popular request, there is now a Mana Jewel at the bottom of Korax's HUD, indicating what weapon is equipped by color association.\n\
- Heroes and Villains can now work side by side in co-op without getting stuck on each other.\n\
- Minions no longer bring Invasion to a screeching halt.\n\
- Up to seven Pfhor Troopers can now be summoned. Their max damage range has been decreased from 15 to 10.";