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
"FROM v0.12 TO v0.13:\n\
========================\n\
- Pfhor no longer repeat the victim's name in place of the killer's name.\n\
- The Team Balancer no longer checks to see if there are X amount of player in the game. Instead, it checks if X amount of players are on either team. This should result in much more lenient balancing when there's a small number of players.\n\
- Joining the game at the last minute no longer breaks the balancer.\n\
- Hitler now always gains his speed boost when he loses his mech.\n\
- Tfear's Flawed no longer uses the SYSTEM ERROR obituary.\n\
- Minions now have +FRIENDLY in the co-op version, which means they should now attack enemy monsters.\n\
- Hitler's 10% damage resistance buff now only takes effect in co-op play as his 'Beef' item.\n\
- D'Sparil's cooldown for his summon and Chaos Device has been doubled--but whenever he enters his Pain State when on-foot, the cooldown is shortened slightly. This should reward more aggressive D'Sparils and slow down those who simply teleport, summon, and repeat.\n\
- Likewise, Tfear's cooldown for his Beacon has been doubled, and whenever he enters his Pain state the cooldown is shortened.\n\
- Tfear's questionable shotgun-esque alt-fire for the Abandon has been replaced with a more-suitable-for-the-role remote grenade launcher.\n\
- The powerups for the Shotgun and the Chaingun have been replaced with something more useful--very slight armor and health regeneration.\n\
- The pickup messages have been reworked so that people actually know what you're getting on picking them up.\n\
- D'Sparil, Korax, and Cyberdemon are now less resistant to Duke's explosives. Hitler is now slightly more resistant.\n\
- By massive request, Disciples no longer drop Lesser Tomes of Power. Bye bye, awesome book. ;_;\n\
- All of the Villains (sans D'Sparil due to technical issues) now have different colors across their life/armor bar to represent how much they have.\n\
- Due to popular demand, Hitler's obituary has been changed.\n\
- naraka_ban[class], naraka_[class]defense, and naraka_[class]damage have been imported. If you think a class is too OP, UP, or broken, now you have control over them!\n\
- Tfear now has a HUD graphic composed of Marathon Pfhor textures.\n\
- When sv_weaponstay is enabled, villains get a flash on their screen when they pick up a powerup.\n\
- The Villains now have their respective individual colors, like the Heroes do.\n\
- The team balancer has been turned into a cvar, naraka_teambalancer. 0 does not attempt to balance the teams at all, 1 favors Heroes but allows Villains to have equal numbers with the heroes if desired, 2 is more strict and does not allow Villains to have equal numbers. Defaults to 1.";