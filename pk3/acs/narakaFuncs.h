function int narakaClassNum(void)
{
    int i;
    for (i = 0; i < CLASSCOUNT; i++)
    {
        if (CheckInventory(NarakaClassItems[i])) { return i; }
    }
    return -1;
}

function void ApplyLMS(void)
{
    int classnum = narakaClassNum();
    if (classnum == -1) { return; }

    int lmsLevel = middle(0, GetCVar("samsara_lmslife"), LMSMODES-1);
    int villianHealth   = LMSLifeHPs[classnum][lmsLevel];
    int villianArmor    = LMSLifeArmors[classnum][lmsLevel];
    int villianUlt      = LMSUlts[classnum];

    if (isLMS() && (GetCVar("teamlms") || GetCVar("teamplay"))) { GiveInventory("TLMSModeOn", 1); }
    GiveInventory("Backpack", 1);
    GiveInventory("VillainAmmoHeavy", 200);
    GiveInventory("VillainAmmoLight", 600);

    SetActorProperty(0, APROP_Health, villianHealth);
    DSparilHealth[PlayerNumber()] = DSparilHPs[lmsLevel];
    if (villianArmor != "") { GiveInventory(villianArmor, 1); }

    if (GetCVar("samsara_lmsult") && villianUlt != "") { GiveInventory(villianUlt, 1); }
}

function int HandleCyberDamage(int respawning)
{
if (CheckInventory("CyberdemonClass") == 1)
{
    if (GetCvar("naraka_Cyberdamage") != -10) { TakeInventory("PowerDamageBuff-10",1); }
    if (GetCvar("naraka_Cyberdamage") != -9)  { TakeInventory("PowerDamageBuff-9",1); }
    if (GetCvar("naraka_Cyberdamage") != -8)  { TakeInventory("PowerDamageBuff-8",1); }
    if (GetCvar("naraka_Cyberdamage") != -7)  { TakeInventory("PowerDamageBuff-7",1); }
    if (GetCvar("naraka_Cyberdamage") != -6)  { TakeInventory("PowerDamageBuff-6",1); }
    if (GetCvar("naraka_Cyberdamage") != -5)  { TakeInventory("PowerDamageBuff-5",1); }
    if (GetCvar("naraka_Cyberdamage") != -4)  { TakeInventory("PowerDamageBuff-4",1); }
    if (GetCvar("naraka_Cyberdamage") != -3)  { TakeInventory("PowerDamageBuff-3",1); }
    if (GetCvar("naraka_Cyberdamage") != -2)  { TakeInventory("PowerDamageBuff-2",1); }
    if (GetCvar("naraka_Cyberdamage") != -1)  { TakeInventory("PowerDamageBuff-1",1); }
    if (GetCvar("naraka_Cyberdamage") != 1)   { TakeInventory("PowerDamageBuff1",1); }
    if (GetCvar("naraka_Cyberdamage") != 2)   { TakeInventory("PowerDamageBuff2",1); }
    if (GetCvar("naraka_Cyberdamage") != 3)   { TakeInventory("PowerDamageBuff3",1); }
    if (GetCvar("naraka_Cyberdamage") != 4)   { TakeInventory("PowerDamageBuff4",1); }
    if (GetCvar("naraka_Cyberdamage") != 5)   { TakeInventory("PowerDamageBuff5",1); }
    if (GetCvar("naraka_Cyberdamage") != 6)   { TakeInventory("PowerDamageBuff6",1); }
    if (GetCvar("naraka_Cyberdamage") != 7)   { TakeInventory("PowerDamageBuff7",1); }
    if (GetCvar("naraka_Cyberdamage") != 8)   { TakeInventory("PowerDamageBuff8",1); }
    if (GetCvar("naraka_Cyberdamage") != 9)   { TakeInventory("PowerDamageBuff9",1); }
    if (GetCvar("naraka_Cyberdamage") != 10)  { TakeInventory("PowerDamageBuff10",1); }
    if (GetCvar("naraka_Cyberdamage") != 11)  { TakeInventory("PowerDamageBuff11",1); }
    if (GetCvar("naraka_Cyberdamage") != 12)  { TakeInventory("PowerDamageBuff12",1); }
    if (GetCvar("naraka_Cyberdamage") != 13)  { TakeInventory("PowerDamageBuff13",1); }
    if (GetCvar("naraka_Cyberdamage") != 14)  { TakeInventory("PowerDamageBuff14",1); }
    if (GetCvar("naraka_Cyberdamage") != 15)  { TakeInventory("PowerDamageBuff15",1); }
    if (GetCvar("naraka_Cyberdamage") != 16)  { TakeInventory("PowerDamageBuff16",1); }
    if (GetCvar("naraka_Cyberdamage") != 17)  { TakeInventory("PowerDamageBuff17",1); }
    if (GetCvar("naraka_Cyberdamage") != 18)  { TakeInventory("PowerDamageBuff18",1); }
    if (GetCvar("naraka_Cyberdamage") != 19)  { TakeInventory("PowerDamageBuff19",1); }
    if (GetCvar("naraka_Cyberdamage") != 20)  { TakeInventory("PowerDamageBuff20",1); }
    if (GetCvar("naraka_Cyberdamage") != 21)  { TakeInventory("PowerDamageBuff21",1); }
    if (GetCvar("naraka_Cyberdamage") != 22)  { TakeInventory("PowerDamageBuff22",1); }
    if (GetCvar("naraka_Cyberdamage") != 23)  { TakeInventory("PowerDamageBuff23",1); }
    if (GetCvar("naraka_Cyberdamage") != 24)  { TakeInventory("PowerDamageBuff24",1); }
    if (GetCvar("naraka_Cyberdamage") != 25)  { TakeInventory("PowerDamageBuff25",1); }
    if (GetCvar("naraka_Cyberdamage") != 26)  { TakeInventory("PowerDamageBuff26",1); }
    if (GetCvar("naraka_Cyberdamage") != 27)  { TakeInventory("PowerDamageBuff27",1); }
    if (GetCvar("naraka_Cyberdamage") != 28)  { TakeInventory("PowerDamageBuff28",1); }
    if (GetCvar("naraka_Cyberdamage") != 29)  { TakeInventory("PowerDamageBuff29",1); }
    if (GetCvar("naraka_Cyberdamage") != 30)  { TakeInventory("PowerDamageBuff30",1); }
	
    if (GetCvar("naraka_Cyberdamage") == -10) { GiveInventory("PowerDamageBuff-10",1); }
    if (GetCvar("naraka_Cyberdamage") == -9)  { GiveInventory("PowerDamageBuff-9",1); }
    if (GetCvar("naraka_Cyberdamage") == -8)  { GiveInventory("PowerDamageBuff-8",1); }
    if (GetCvar("naraka_Cyberdamage") == -7)  { GiveInventory("PowerDamageBuff-7",1); }
    if (GetCvar("naraka_Cyberdamage") == -6)  { GiveInventory("PowerDamageBuff-6",1); }
    if (GetCvar("naraka_Cyberdamage") == -5)  { GiveInventory("PowerDamageBuff-5",1); }
    if (GetCvar("naraka_Cyberdamage") == -4)  { GiveInventory("PowerDamageBuff-4",1); }
    if (GetCvar("naraka_Cyberdamage") == -3)  { GiveInventory("PowerDamageBuff-3",1); }
    if (GetCvar("naraka_Cyberdamage") == -2)  { GiveInventory("PowerDamageBuff-2",1); }
    if (GetCvar("naraka_Cyberdamage") == -1)  { GiveInventory("PowerDamageBuff-1",1); }
    if (GetCvar("naraka_Cyberdamage") == 1)   { GiveInventory("PowerDamageBuff1",1); }
    if (GetCvar("naraka_Cyberdamage") == 2)   { GiveInventory("PowerDamageBuff2",1); }
    if (GetCvar("naraka_Cyberdamage") == 3)   { GiveInventory("PowerDamageBuff3",1); }
    if (GetCvar("naraka_Cyberdamage") == 4)   { GiveInventory("PowerDamageBuff4",1); }
    if (GetCvar("naraka_Cyberdamage") == 5)   { GiveInventory("PowerDamageBuff5",1); }
    if (GetCvar("naraka_Cyberdamage") == 6)   { GiveInventory("PowerDamageBuff6",1); }
    if (GetCvar("naraka_Cyberdamage") == 7)   { GiveInventory("PowerDamageBuff7",1); }
    if (GetCvar("naraka_Cyberdamage") == 8)   { GiveInventory("PowerDamageBuff8",1); }
    if (GetCvar("naraka_Cyberdamage") == 9)   { GiveInventory("PowerDamageBuff9",1); }
    if (GetCvar("naraka_Cyberdamage") == 10)  { GiveInventory("PowerDamageBuff10",1); }
    if (GetCvar("naraka_Cyberdamage") == 11)  { GiveInventory("PowerDamageBuff11",1); }
    if (GetCvar("naraka_Cyberdamage") == 12)  { GiveInventory("PowerDamageBuff12",1); }
    if (GetCvar("naraka_Cyberdamage") == 13)  { GiveInventory("PowerDamageBuff13",1); }
    if (GetCvar("naraka_Cyberdamage") == 14)  { GiveInventory("PowerDamageBuff14",1); }
    if (GetCvar("naraka_Cyberdamage") == 15)  { GiveInventory("PowerDamageBuff15",1); }
    if (GetCvar("naraka_Cyberdamage") == 16)  { GiveInventory("PowerDamageBuff16",1); }
    if (GetCvar("naraka_Cyberdamage") == 17)  { GiveInventory("PowerDamageBuff17",1); }
    if (GetCvar("naraka_Cyberdamage") == 18)  { GiveInventory("PowerDamageBuff18",1); }
    if (GetCvar("naraka_Cyberdamage") == 19)  { GiveInventory("PowerDamageBuff19",1); }
    if (GetCvar("naraka_Cyberdamage") == 20)  { GiveInventory("PowerDamageBuff20",1); }
    if (GetCvar("naraka_Cyberdamage") == 21)  { GiveInventory("PowerDamageBuff21",1); }
    if (GetCvar("naraka_Cyberdamage") == 22)  { GiveInventory("PowerDamageBuff22",1); }
    if (GetCvar("naraka_Cyberdamage") == 23)  { GiveInventory("PowerDamageBuff23",1); }
    if (GetCvar("naraka_Cyberdamage") == 24)  { GiveInventory("PowerDamageBuff24",1); }
    if (GetCvar("naraka_Cyberdamage") == 25)  { GiveInventory("PowerDamageBuff25",1); }
    if (GetCvar("naraka_Cyberdamage") == 26)  { GiveInventory("PowerDamageBuff26",1); }
    if (GetCvar("naraka_Cyberdamage") == 27)  { GiveInventory("PowerDamageBuff27",1); }
    if (GetCvar("naraka_Cyberdamage") == 28)  { GiveInventory("PowerDamageBuff28",1); }
    if (GetCvar("naraka_Cyberdamage") == 29)  { GiveInventory("PowerDamageBuff29",1); }
    if (GetCvar("naraka_Cyberdamage") == 30)  { GiveInventory("PowerDamageBuff30",1); }
}
return 1;
}

function int HandleCyberDefense(int respawning)
{
if (CheckInventory("CyberdemonClass") == 1)
{
    if (GetCvar("naraka_Cyberdefense") != -10) { TakeInventory("PowerDefenseBuff-10",1); }
    if (GetCvar("naraka_Cyberdefense") != -9)  { TakeInventory("PowerDefenseBuff-9",1); }
    if (GetCvar("naraka_Cyberdefense") != -8)  { TakeInventory("PowerDefenseBuff-8",1); }
    if (GetCvar("naraka_Cyberdefense") != -7)  { TakeInventory("PowerDefenseBuff-7",1); }
    if (GetCvar("naraka_Cyberdefense") != -6)  { TakeInventory("PowerDefenseBuff-6",1); }
    if (GetCvar("naraka_Cyberdefense") != -5)  { TakeInventory("PowerDefenseBuff-5",1); }
    if (GetCvar("naraka_Cyberdefense") != -4)  { TakeInventory("PowerDefenseBuff-4",1); }
    if (GetCvar("naraka_Cyberdefense") != -3)  { TakeInventory("PowerDefenseBuff-3",1); }
    if (GetCvar("naraka_Cyberdefense") != -2)  { TakeInventory("PowerDefenseBuff-2",1); }
    if (GetCvar("naraka_Cyberdefense") != -1)  { TakeInventory("PowerDefenseBuff-1",1); }
    if (GetCvar("naraka_Cyberdefense") != 1)   { TakeInventory("PowerDefenseBuff1",1); }
    if (GetCvar("naraka_Cyberdefense") != 2)   { TakeInventory("PowerDefenseBuff2",1); }
    if (GetCvar("naraka_Cyberdefense") != 3)   { TakeInventory("PowerDefenseBuff3",1); }
    if (GetCvar("naraka_Cyberdefense") != 4)   { TakeInventory("PowerDefenseBuff4",1); }
    if (GetCvar("naraka_Cyberdefense") != 5)   { TakeInventory("PowerDefenseBuff5",1); }
    if (GetCvar("naraka_Cyberdefense") != 6)   { TakeInventory("PowerDefenseBuff6",1); }
    if (GetCvar("naraka_Cyberdefense") != 7)   { TakeInventory("PowerDefenseBuff7",1); }
    if (GetCvar("naraka_Cyberdefense") != 8)   { TakeInventory("PowerDefenseBuff8",1); }
    if (GetCvar("naraka_Cyberdefense") != 9)   { TakeInventory("PowerDefenseBuff9",1); }
    if (GetCvar("naraka_Cyberdefense") != 10)  { TakeInventory("PowerDefenseBuff10",1); }
    if (GetCvar("naraka_Cyberdefense") != 11)  { TakeInventory("PowerDefenseBuff11",1); }
    if (GetCvar("naraka_Cyberdefense") != 12)  { TakeInventory("PowerDefenseBuff12",1); }
    if (GetCvar("naraka_Cyberdefense") != 13)  { TakeInventory("PowerDefenseBuff13",1); }
    if (GetCvar("naraka_Cyberdefense") != 14)  { TakeInventory("PowerDefenseBuff14",1); }
    if (GetCvar("naraka_Cyberdefense") != 15)  { TakeInventory("PowerDefenseBuff15",1); }
    if (GetCvar("naraka_Cyberdefense") != 16)  { TakeInventory("PowerDefenseBuff16",1); }
    if (GetCvar("naraka_Cyberdefense") != 17)  { TakeInventory("PowerDefenseBuff17",1); }
    if (GetCvar("naraka_Cyberdefense") != 18)  { TakeInventory("PowerDefenseBuff18",1); }
    if (GetCvar("naraka_Cyberdefense") != 19)  { TakeInventory("PowerDefenseBuff19",1); }
    if (GetCvar("naraka_Cyberdefense") != 20)  { TakeInventory("PowerDefenseBuff20",1); }
	
    if (GetCvar("naraka_Cyberdefense") == -10) { GiveInventory("PowerDefenseBuff-10",1); }
    if (GetCvar("naraka_Cyberdefense") == -9)  { GiveInventory("PowerDefenseBuff-9",1); }
    if (GetCvar("naraka_Cyberdefense") == -8)  { GiveInventory("PowerDefenseBuff-8",1); }
    if (GetCvar("naraka_Cyberdefense") == -7)  { GiveInventory("PowerDefenseBuff-7",1); }
    if (GetCvar("naraka_Cyberdefense") == -6)  { GiveInventory("PowerDefenseBuff-6",1); }
    if (GetCvar("naraka_Cyberdefense") == -5)  { GiveInventory("PowerDefenseBuff-5",1); }
    if (GetCvar("naraka_Cyberdefense") == -4)  { GiveInventory("PowerDefenseBuff-4",1); }
    if (GetCvar("naraka_Cyberdefense") == -3)  { GiveInventory("PowerDefenseBuff-3",1); }
    if (GetCvar("naraka_Cyberdefense") == -2)  { GiveInventory("PowerDefenseBuff-2",1); }
    if (GetCvar("naraka_Cyberdefense") == -1)  { GiveInventory("PowerDefenseBuff-1",1); }
    if (GetCvar("naraka_Cyberdefense") == 1)   { GiveInventory("PowerDefenseBuff1",1); }
    if (GetCvar("naraka_Cyberdefense") == 2)   { GiveInventory("PowerDefenseBuff2",1); }
    if (GetCvar("naraka_Cyberdefense") == 3)   { GiveInventory("PowerDefenseBuff3",1); }
    if (GetCvar("naraka_Cyberdefense") == 4)   { GiveInventory("PowerDefenseBuff4",1); }
    if (GetCvar("naraka_Cyberdefense") == 5)   { GiveInventory("PowerDefenseBuff5",1); }
    if (GetCvar("naraka_Cyberdefense") == 6)   { GiveInventory("PowerDefenseBuff6",1); }
    if (GetCvar("naraka_Cyberdefense") == 7)   { GiveInventory("PowerDefenseBuff7",1); }
    if (GetCvar("naraka_Cyberdefense") == 8)   { GiveInventory("PowerDefenseBuff8",1); }
    if (GetCvar("naraka_Cyberdefense") == 9)   { GiveInventory("PowerDefenseBuff9",1); }
    if (GetCvar("naraka_Cyberdefense") == 10)  { GiveInventory("PowerDefenseBuff10",1); }
    if (GetCvar("naraka_Cyberdefense") == 11)  { GiveInventory("PowerDefenseBuff11",1); }
    if (GetCvar("naraka_Cyberdefense") == 12)  { GiveInventory("PowerDefenseBuff12",1); }
    if (GetCvar("naraka_Cyberdefense") == 13)  { GiveInventory("PowerDefenseBuff13",1); }
    if (GetCvar("naraka_Cyberdefense") == 14)  { GiveInventory("PowerDefenseBuff14",1); }
    if (GetCvar("naraka_Cyberdefense") == 15)  { GiveInventory("PowerDefenseBuff15",1); }
    if (GetCvar("naraka_Cyberdefense") == 16)  { GiveInventory("PowerDefenseBuff16",1); }
    if (GetCvar("naraka_Cyberdefense") == 17)  { GiveInventory("PowerDefenseBuff17",1); }
    if (GetCvar("naraka_Cyberdefense") == 18)  { GiveInventory("PowerDefenseBuff18",1); }
    if (GetCvar("naraka_Cyberdefense") == 19)  { GiveInventory("PowerDefenseBuff19",1); }
    if (GetCvar("naraka_Cyberdefense") == 20)  { GiveInventory("PowerDefenseBuff20",1); }
}
return 1;
}

function int HandleDSparilDamage(int respawning)
{
if (CheckInventory("DSparilClass") == 1)
{
    if (GetCvar("naraka_DSparildamage") != -10) { TakeInventory("PowerDamageBuff-10",1); }
    if (GetCvar("naraka_DSparildamage") != -9)  { TakeInventory("PowerDamageBuff-9",1); }
    if (GetCvar("naraka_DSparildamage") != -8)  { TakeInventory("PowerDamageBuff-8",1); }
    if (GetCvar("naraka_DSparildamage") != -7)  { TakeInventory("PowerDamageBuff-7",1); }
    if (GetCvar("naraka_DSparildamage") != -6)  { TakeInventory("PowerDamageBuff-6",1); }
    if (GetCvar("naraka_DSparildamage") != -5)  { TakeInventory("PowerDamageBuff-5",1); }
    if (GetCvar("naraka_DSparildamage") != -4)  { TakeInventory("PowerDamageBuff-4",1); }
    if (GetCvar("naraka_DSparildamage") != -3)  { TakeInventory("PowerDamageBuff-3",1); }
    if (GetCvar("naraka_DSparildamage") != -2)  { TakeInventory("PowerDamageBuff-2",1); }
    if (GetCvar("naraka_DSparildamage") != -1)  { TakeInventory("PowerDamageBuff-1",1); }
    if (GetCvar("naraka_DSparildamage") != 1)   { TakeInventory("PowerDamageBuff1",1); }
    if (GetCvar("naraka_DSparildamage") != 2)   { TakeInventory("PowerDamageBuff2",1); }
    if (GetCvar("naraka_DSparildamage") != 3)   { TakeInventory("PowerDamageBuff3",1); }
    if (GetCvar("naraka_DSparildamage") != 4)   { TakeInventory("PowerDamageBuff4",1); }
    if (GetCvar("naraka_DSparildamage") != 5)   { TakeInventory("PowerDamageBuff5",1); }
    if (GetCvar("naraka_DSparildamage") != 6)   { TakeInventory("PowerDamageBuff6",1); }
    if (GetCvar("naraka_DSparildamage") != 7)   { TakeInventory("PowerDamageBuff7",1); }
    if (GetCvar("naraka_DSparildamage") != 8)   { TakeInventory("PowerDamageBuff8",1); }
    if (GetCvar("naraka_DSparildamage") != 9)   { TakeInventory("PowerDamageBuff9",1); }
    if (GetCvar("naraka_DSparildamage") != 10)  { TakeInventory("PowerDamageBuff10",1); }
    if (GetCvar("naraka_DSparildamage") != 11)  { TakeInventory("PowerDamageBuff11",1); }
    if (GetCvar("naraka_DSparildamage") != 12)  { TakeInventory("PowerDamageBuff12",1); }
    if (GetCvar("naraka_DSparildamage") != 13)  { TakeInventory("PowerDamageBuff13",1); }
    if (GetCvar("naraka_DSparildamage") != 14)  { TakeInventory("PowerDamageBuff14",1); }
    if (GetCvar("naraka_DSparildamage") != 15)  { TakeInventory("PowerDamageBuff15",1); }
    if (GetCvar("naraka_DSparildamage") != 16)  { TakeInventory("PowerDamageBuff16",1); }
    if (GetCvar("naraka_DSparildamage") != 17)  { TakeInventory("PowerDamageBuff17",1); }
    if (GetCvar("naraka_DSparildamage") != 18)  { TakeInventory("PowerDamageBuff18",1); }
    if (GetCvar("naraka_DSparildamage") != 19)  { TakeInventory("PowerDamageBuff19",1); }
    if (GetCvar("naraka_DSparildamage") != 20)  { TakeInventory("PowerDamageBuff20",1); }
    if (GetCvar("naraka_DSparildamage") != 21)  { TakeInventory("PowerDamageBuff21",1); }
    if (GetCvar("naraka_DSparildamage") != 22)  { TakeInventory("PowerDamageBuff22",1); }
    if (GetCvar("naraka_DSparildamage") != 23)  { TakeInventory("PowerDamageBuff23",1); }
    if (GetCvar("naraka_DSparildamage") != 24)  { TakeInventory("PowerDamageBuff24",1); }
    if (GetCvar("naraka_DSparildamage") != 25)  { TakeInventory("PowerDamageBuff25",1); }
    if (GetCvar("naraka_DSparildamage") != 26)  { TakeInventory("PowerDamageBuff26",1); }
    if (GetCvar("naraka_DSparildamage") != 27)  { TakeInventory("PowerDamageBuff27",1); }
    if (GetCvar("naraka_DSparildamage") != 28)  { TakeInventory("PowerDamageBuff28",1); }
    if (GetCvar("naraka_DSparildamage") != 29)  { TakeInventory("PowerDamageBuff29",1); }
    if (GetCvar("naraka_DSparildamage") != 30)  { TakeInventory("PowerDamageBuff30",1); }
	
    if (GetCvar("naraka_DSparildamage") == -10) { GiveInventory("PowerDamageBuff-10",1); }
    if (GetCvar("naraka_DSparildamage") == -9)  { GiveInventory("PowerDamageBuff-9",1); }
    if (GetCvar("naraka_DSparildamage") == -8)  { GiveInventory("PowerDamageBuff-8",1); }
    if (GetCvar("naraka_DSparildamage") == -7)  { GiveInventory("PowerDamageBuff-7",1); }
    if (GetCvar("naraka_DSparildamage") == -6)  { GiveInventory("PowerDamageBuff-6",1); }
    if (GetCvar("naraka_DSparildamage") == -5)  { GiveInventory("PowerDamageBuff-5",1); }
    if (GetCvar("naraka_DSparildamage") == -4)  { GiveInventory("PowerDamageBuff-4",1); }
    if (GetCvar("naraka_DSparildamage") == -3)  { GiveInventory("PowerDamageBuff-3",1); }
    if (GetCvar("naraka_DSparildamage") == -2)  { GiveInventory("PowerDamageBuff-2",1); }
    if (GetCvar("naraka_DSparildamage") == -1)  { GiveInventory("PowerDamageBuff-1",1); }
    if (GetCvar("naraka_DSparildamage") == 1)   { GiveInventory("PowerDamageBuff1",1); }
    if (GetCvar("naraka_DSparildamage") == 2)   { GiveInventory("PowerDamageBuff2",1); }
    if (GetCvar("naraka_DSparildamage") == 3)   { GiveInventory("PowerDamageBuff3",1); }
    if (GetCvar("naraka_DSparildamage") == 4)   { GiveInventory("PowerDamageBuff4",1); }
    if (GetCvar("naraka_DSparildamage") == 5)   { GiveInventory("PowerDamageBuff5",1); }
    if (GetCvar("naraka_DSparildamage") == 6)   { GiveInventory("PowerDamageBuff6",1); }
    if (GetCvar("naraka_DSparildamage") == 7)   { GiveInventory("PowerDamageBuff7",1); }
    if (GetCvar("naraka_DSparildamage") == 8)   { GiveInventory("PowerDamageBuff8",1); }
    if (GetCvar("naraka_DSparildamage") == 9)   { GiveInventory("PowerDamageBuff9",1); }
    if (GetCvar("naraka_DSparildamage") == 10)  { GiveInventory("PowerDamageBuff10",1); }
    if (GetCvar("naraka_DSparildamage") == 11)  { GiveInventory("PowerDamageBuff11",1); }
    if (GetCvar("naraka_DSparildamage") == 12)  { GiveInventory("PowerDamageBuff12",1); }
    if (GetCvar("naraka_DSparildamage") == 13)  { GiveInventory("PowerDamageBuff13",1); }
    if (GetCvar("naraka_DSparildamage") == 14)  { GiveInventory("PowerDamageBuff14",1); }
    if (GetCvar("naraka_DSparildamage") == 15)  { GiveInventory("PowerDamageBuff15",1); }
    if (GetCvar("naraka_DSparildamage") == 16)  { GiveInventory("PowerDamageBuff16",1); }
    if (GetCvar("naraka_DSparildamage") == 17)  { GiveInventory("PowerDamageBuff17",1); }
    if (GetCvar("naraka_DSparildamage") == 18)  { GiveInventory("PowerDamageBuff18",1); }
    if (GetCvar("naraka_DSparildamage") == 19)  { GiveInventory("PowerDamageBuff19",1); }
    if (GetCvar("naraka_DSparildamage") == 20)  { GiveInventory("PowerDamageBuff20",1); }
    if (GetCvar("naraka_DSparildamage") == 21)  { GiveInventory("PowerDamageBuff21",1); }
    if (GetCvar("naraka_DSparildamage") == 22)  { GiveInventory("PowerDamageBuff22",1); }
    if (GetCvar("naraka_DSparildamage") == 23)  { GiveInventory("PowerDamageBuff23",1); }
    if (GetCvar("naraka_DSparildamage") == 24)  { GiveInventory("PowerDamageBuff24",1); }
    if (GetCvar("naraka_DSparildamage") == 25)  { GiveInventory("PowerDamageBuff25",1); }
    if (GetCvar("naraka_DSparildamage") == 26)  { GiveInventory("PowerDamageBuff26",1); }
    if (GetCvar("naraka_DSparildamage") == 27)  { GiveInventory("PowerDamageBuff27",1); }
    if (GetCvar("naraka_DSparildamage") == 28)  { GiveInventory("PowerDamageBuff28",1); }
    if (GetCvar("naraka_DSparildamage") == 29)  { GiveInventory("PowerDamageBuff29",1); }
    if (GetCvar("naraka_DSparildamage") == 30)  { GiveInventory("PowerDamageBuff30",1); }
}
return 1;
}

function int HandleDSparilDefense(int respawning)
{
if (CheckInventory("DSparilClass") == 1)
{
    if (GetCvar("naraka_DSparildefense") != -10) { TakeInventory("PowerDefenseBuff-10",1); }
    if (GetCvar("naraka_DSparildefense") != -9)  { TakeInventory("PowerDefenseBuff-9",1); }
    if (GetCvar("naraka_DSparildefense") != -8)  { TakeInventory("PowerDefenseBuff-8",1); }
    if (GetCvar("naraka_DSparildefense") != -7)  { TakeInventory("PowerDefenseBuff-7",1); }
    if (GetCvar("naraka_DSparildefense") != -6)  { TakeInventory("PowerDefenseBuff-6",1); }
    if (GetCvar("naraka_DSparildefense") != -5)  { TakeInventory("PowerDefenseBuff-5",1); }
    if (GetCvar("naraka_DSparildefense") != -4)  { TakeInventory("PowerDefenseBuff-4",1); }
    if (GetCvar("naraka_DSparildefense") != -3)  { TakeInventory("PowerDefenseBuff-3",1); }
    if (GetCvar("naraka_DSparildefense") != -2)  { TakeInventory("PowerDefenseBuff-2",1); }
    if (GetCvar("naraka_DSparildefense") != -1)  { TakeInventory("PowerDefenseBuff-1",1); }
    if (GetCvar("naraka_DSparildefense") != 1)   { TakeInventory("PowerDefenseBuff1",1); }
    if (GetCvar("naraka_DSparildefense") != 2)   { TakeInventory("PowerDefenseBuff2",1); }
    if (GetCvar("naraka_DSparildefense") != 3)   { TakeInventory("PowerDefenseBuff3",1); }
    if (GetCvar("naraka_DSparildefense") != 4)   { TakeInventory("PowerDefenseBuff4",1); }
    if (GetCvar("naraka_DSparildefense") != 5)   { TakeInventory("PowerDefenseBuff5",1); }
    if (GetCvar("naraka_DSparildefense") != 6)   { TakeInventory("PowerDefenseBuff6",1); }
    if (GetCvar("naraka_DSparildefense") != 7)   { TakeInventory("PowerDefenseBuff7",1); }
    if (GetCvar("naraka_DSparildefense") != 8)   { TakeInventory("PowerDefenseBuff8",1); }
    if (GetCvar("naraka_DSparildefense") != 9)   { TakeInventory("PowerDefenseBuff9",1); }
    if (GetCvar("naraka_DSparildefense") != 10)  { TakeInventory("PowerDefenseBuff10",1); }
    if (GetCvar("naraka_DSparildefense") != 11)  { TakeInventory("PowerDefenseBuff11",1); }
    if (GetCvar("naraka_DSparildefense") != 12)  { TakeInventory("PowerDefenseBuff12",1); }
    if (GetCvar("naraka_DSparildefense") != 13)  { TakeInventory("PowerDefenseBuff13",1); }
    if (GetCvar("naraka_DSparildefense") != 14)  { TakeInventory("PowerDefenseBuff14",1); }
    if (GetCvar("naraka_DSparildefense") != 15)  { TakeInventory("PowerDefenseBuff15",1); }
    if (GetCvar("naraka_DSparildefense") != 16)  { TakeInventory("PowerDefenseBuff16",1); }
    if (GetCvar("naraka_DSparildefense") != 17)  { TakeInventory("PowerDefenseBuff17",1); }
    if (GetCvar("naraka_DSparildefense") != 18)  { TakeInventory("PowerDefenseBuff18",1); }
    if (GetCvar("naraka_DSparildefense") != 19)  { TakeInventory("PowerDefenseBuff19",1); }
    if (GetCvar("naraka_DSparildefense") != 20)  { TakeInventory("PowerDefenseBuff20",1); }
	
    if (GetCvar("naraka_DSparildefense") == -10) { GiveInventory("PowerDefenseBuff-10",1); }
    if (GetCvar("naraka_DSparildefense") == -9)  { GiveInventory("PowerDefenseBuff-9",1); }
    if (GetCvar("naraka_DSparildefense") == -8)  { GiveInventory("PowerDefenseBuff-8",1); }
    if (GetCvar("naraka_DSparildefense") == -7)  { GiveInventory("PowerDefenseBuff-7",1); }
    if (GetCvar("naraka_DSparildefense") == -6)  { GiveInventory("PowerDefenseBuff-6",1); }
    if (GetCvar("naraka_DSparildefense") == -5)  { GiveInventory("PowerDefenseBuff-5",1); }
    if (GetCvar("naraka_DSparildefense") == -4)  { GiveInventory("PowerDefenseBuff-4",1); }
    if (GetCvar("naraka_DSparildefense") == -3)  { GiveInventory("PowerDefenseBuff-3",1); }
    if (GetCvar("naraka_DSparildefense") == -2)  { GiveInventory("PowerDefenseBuff-2",1); }
    if (GetCvar("naraka_DSparildefense") == -1)  { GiveInventory("PowerDefenseBuff-1",1); }
    if (GetCvar("naraka_DSparildefense") == 1)   { GiveInventory("PowerDefenseBuff1",1); }
    if (GetCvar("naraka_DSparildefense") == 2)   { GiveInventory("PowerDefenseBuff2",1); }
    if (GetCvar("naraka_DSparildefense") == 3)   { GiveInventory("PowerDefenseBuff3",1); }
    if (GetCvar("naraka_DSparildefense") == 4)   { GiveInventory("PowerDefenseBuff4",1); }
    if (GetCvar("naraka_DSparildefense") == 5)   { GiveInventory("PowerDefenseBuff5",1); }
    if (GetCvar("naraka_DSparildefense") == 6)   { GiveInventory("PowerDefenseBuff6",1); }
    if (GetCvar("naraka_DSparildefense") == 7)   { GiveInventory("PowerDefenseBuff7",1); }
    if (GetCvar("naraka_DSparildefense") == 8)   { GiveInventory("PowerDefenseBuff8",1); }
    if (GetCvar("naraka_DSparildefense") == 9)   { GiveInventory("PowerDefenseBuff9",1); }
    if (GetCvar("naraka_DSparildefense") == 10)  { GiveInventory("PowerDefenseBuff10",1); }
    if (GetCvar("naraka_DSparildefense") == 11)  { GiveInventory("PowerDefenseBuff11",1); }
    if (GetCvar("naraka_DSparildefense") == 12)  { GiveInventory("PowerDefenseBuff12",1); }
    if (GetCvar("naraka_DSparildefense") == 13)  { GiveInventory("PowerDefenseBuff13",1); }
    if (GetCvar("naraka_DSparildefense") == 14)  { GiveInventory("PowerDefenseBuff14",1); }
    if (GetCvar("naraka_DSparildefense") == 15)  { GiveInventory("PowerDefenseBuff15",1); }
    if (GetCvar("naraka_DSparildefense") == 16)  { GiveInventory("PowerDefenseBuff16",1); }
    if (GetCvar("naraka_DSparildefense") == 17)  { GiveInventory("PowerDefenseBuff17",1); }
    if (GetCvar("naraka_DSparildefense") == 18)  { GiveInventory("PowerDefenseBuff18",1); }
    if (GetCvar("naraka_DSparildefense") == 19)  { GiveInventory("PowerDefenseBuff19",1); }
    if (GetCvar("naraka_DSparildefense") == 20)  { GiveInventory("PowerDefenseBuff20",1); }
}
return 1;
}

function int HandleHitlerDamage(int respawning)
{
if (CheckInventory("HitlerClass") == 1)
{
    if (GetCvar("naraka_Hitlerdamage") != -10) { TakeInventory("PowerDamageBuff-10",1); }
    if (GetCvar("naraka_Hitlerdamage") != -9)  { TakeInventory("PowerDamageBuff-9",1); }
    if (GetCvar("naraka_Hitlerdamage") != -8)  { TakeInventory("PowerDamageBuff-8",1); }
    if (GetCvar("naraka_Hitlerdamage") != -7)  { TakeInventory("PowerDamageBuff-7",1); }
    if (GetCvar("naraka_Hitlerdamage") != -6)  { TakeInventory("PowerDamageBuff-6",1); }
    if (GetCvar("naraka_Hitlerdamage") != -5)  { TakeInventory("PowerDamageBuff-5",1); }
    if (GetCvar("naraka_Hitlerdamage") != -4)  { TakeInventory("PowerDamageBuff-4",1); }
    if (GetCvar("naraka_Hitlerdamage") != -3)  { TakeInventory("PowerDamageBuff-3",1); }
    if (GetCvar("naraka_Hitlerdamage") != -2)  { TakeInventory("PowerDamageBuff-2",1); }
    if (GetCvar("naraka_Hitlerdamage") != -1)  { TakeInventory("PowerDamageBuff-1",1); }
    if (GetCvar("naraka_Hitlerdamage") != 1)   { TakeInventory("PowerDamageBuff1",1); }
    if (GetCvar("naraka_Hitlerdamage") != 2)   { TakeInventory("PowerDamageBuff2",1); }
    if (GetCvar("naraka_Hitlerdamage") != 3)   { TakeInventory("PowerDamageBuff3",1); }
    if (GetCvar("naraka_Hitlerdamage") != 4)   { TakeInventory("PowerDamageBuff4",1); }
    if (GetCvar("naraka_Hitlerdamage") != 5)   { TakeInventory("PowerDamageBuff5",1); }
    if (GetCvar("naraka_Hitlerdamage") != 6)   { TakeInventory("PowerDamageBuff6",1); }
    if (GetCvar("naraka_Hitlerdamage") != 7)   { TakeInventory("PowerDamageBuff7",1); }
    if (GetCvar("naraka_Hitlerdamage") != 8)   { TakeInventory("PowerDamageBuff8",1); }
    if (GetCvar("naraka_Hitlerdamage") != 9)   { TakeInventory("PowerDamageBuff9",1); }
    if (GetCvar("naraka_Hitlerdamage") != 10)  { TakeInventory("PowerDamageBuff10",1); }
    if (GetCvar("naraka_Hitlerdamage") != 11)  { TakeInventory("PowerDamageBuff11",1); }
    if (GetCvar("naraka_Hitlerdamage") != 12)  { TakeInventory("PowerDamageBuff12",1); }
    if (GetCvar("naraka_Hitlerdamage") != 13)  { TakeInventory("PowerDamageBuff13",1); }
    if (GetCvar("naraka_Hitlerdamage") != 14)  { TakeInventory("PowerDamageBuff14",1); }
    if (GetCvar("naraka_Hitlerdamage") != 15)  { TakeInventory("PowerDamageBuff15",1); }
    if (GetCvar("naraka_Hitlerdamage") != 16)  { TakeInventory("PowerDamageBuff16",1); }
    if (GetCvar("naraka_Hitlerdamage") != 17)  { TakeInventory("PowerDamageBuff17",1); }
    if (GetCvar("naraka_Hitlerdamage") != 18)  { TakeInventory("PowerDamageBuff18",1); }
    if (GetCvar("naraka_Hitlerdamage") != 19)  { TakeInventory("PowerDamageBuff19",1); }
    if (GetCvar("naraka_Hitlerdamage") != 20)  { TakeInventory("PowerDamageBuff20",1); }
    if (GetCvar("naraka_Hitlerdamage") != 21)  { TakeInventory("PowerDamageBuff21",1); }
    if (GetCvar("naraka_Hitlerdamage") != 22)  { TakeInventory("PowerDamageBuff22",1); }
    if (GetCvar("naraka_Hitlerdamage") != 23)  { TakeInventory("PowerDamageBuff23",1); }
    if (GetCvar("naraka_Hitlerdamage") != 24)  { TakeInventory("PowerDamageBuff24",1); }
    if (GetCvar("naraka_Hitlerdamage") != 25)  { TakeInventory("PowerDamageBuff25",1); }
    if (GetCvar("naraka_Hitlerdamage") != 26)  { TakeInventory("PowerDamageBuff26",1); }
    if (GetCvar("naraka_Hitlerdamage") != 27)  { TakeInventory("PowerDamageBuff27",1); }
    if (GetCvar("naraka_Hitlerdamage") != 28)  { TakeInventory("PowerDamageBuff28",1); }
    if (GetCvar("naraka_Hitlerdamage") != 29)  { TakeInventory("PowerDamageBuff29",1); }
    if (GetCvar("naraka_Hitlerdamage") != 30)  { TakeInventory("PowerDamageBuff30",1); }
	
    if (GetCvar("naraka_Hitlerdamage") == -10) { GiveInventory("PowerDamageBuff-10",1); }
    if (GetCvar("naraka_Hitlerdamage") == -9)  { GiveInventory("PowerDamageBuff-9",1); }
    if (GetCvar("naraka_Hitlerdamage") == -8)  { GiveInventory("PowerDamageBuff-8",1); }
    if (GetCvar("naraka_Hitlerdamage") == -7)  { GiveInventory("PowerDamageBuff-7",1); }
    if (GetCvar("naraka_Hitlerdamage") == -6)  { GiveInventory("PowerDamageBuff-6",1); }
    if (GetCvar("naraka_Hitlerdamage") == -5)  { GiveInventory("PowerDamageBuff-5",1); }
    if (GetCvar("naraka_Hitlerdamage") == -4)  { GiveInventory("PowerDamageBuff-4",1); }
    if (GetCvar("naraka_Hitlerdamage") == -3)  { GiveInventory("PowerDamageBuff-3",1); }
    if (GetCvar("naraka_Hitlerdamage") == -2)  { GiveInventory("PowerDamageBuff-2",1); }
    if (GetCvar("naraka_Hitlerdamage") == -1)  { GiveInventory("PowerDamageBuff-1",1); }
    if (GetCvar("naraka_Hitlerdamage") == 1)   { GiveInventory("PowerDamageBuff1",1); }
    if (GetCvar("naraka_Hitlerdamage") == 2)   { GiveInventory("PowerDamageBuff2",1); }
    if (GetCvar("naraka_Hitlerdamage") == 3)   { GiveInventory("PowerDamageBuff3",1); }
    if (GetCvar("naraka_Hitlerdamage") == 4)   { GiveInventory("PowerDamageBuff4",1); }
    if (GetCvar("naraka_Hitlerdamage") == 5)   { GiveInventory("PowerDamageBuff5",1); }
    if (GetCvar("naraka_Hitlerdamage") == 6)   { GiveInventory("PowerDamageBuff6",1); }
    if (GetCvar("naraka_Hitlerdamage") == 7)   { GiveInventory("PowerDamageBuff7",1); }
    if (GetCvar("naraka_Hitlerdamage") == 8)   { GiveInventory("PowerDamageBuff8",1); }
    if (GetCvar("naraka_Hitlerdamage") == 9)   { GiveInventory("PowerDamageBuff9",1); }
    if (GetCvar("naraka_Hitlerdamage") == 10)  { GiveInventory("PowerDamageBuff10",1); }
    if (GetCvar("naraka_Hitlerdamage") == 11)  { GiveInventory("PowerDamageBuff11",1); }
    if (GetCvar("naraka_Hitlerdamage") == 12)  { GiveInventory("PowerDamageBuff12",1); }
    if (GetCvar("naraka_Hitlerdamage") == 13)  { GiveInventory("PowerDamageBuff13",1); }
    if (GetCvar("naraka_Hitlerdamage") == 14)  { GiveInventory("PowerDamageBuff14",1); }
    if (GetCvar("naraka_Hitlerdamage") == 15)  { GiveInventory("PowerDamageBuff15",1); }
    if (GetCvar("naraka_Hitlerdamage") == 16)  { GiveInventory("PowerDamageBuff16",1); }
    if (GetCvar("naraka_Hitlerdamage") == 17)  { GiveInventory("PowerDamageBuff17",1); }
    if (GetCvar("naraka_Hitlerdamage") == 18)  { GiveInventory("PowerDamageBuff18",1); }
    if (GetCvar("naraka_Hitlerdamage") == 19)  { GiveInventory("PowerDamageBuff19",1); }
    if (GetCvar("naraka_Hitlerdamage") == 20)  { GiveInventory("PowerDamageBuff20",1); }
    if (GetCvar("naraka_Hitlerdamage") == 21)  { GiveInventory("PowerDamageBuff21",1); }
    if (GetCvar("naraka_Hitlerdamage") == 22)  { GiveInventory("PowerDamageBuff22",1); }
    if (GetCvar("naraka_Hitlerdamage") == 23)  { GiveInventory("PowerDamageBuff23",1); }
    if (GetCvar("naraka_Hitlerdamage") == 24)  { GiveInventory("PowerDamageBuff24",1); }
    if (GetCvar("naraka_Hitlerdamage") == 25)  { GiveInventory("PowerDamageBuff25",1); }
    if (GetCvar("naraka_Hitlerdamage") == 26)  { GiveInventory("PowerDamageBuff26",1); }
    if (GetCvar("naraka_Hitlerdamage") == 27)  { GiveInventory("PowerDamageBuff27",1); }
    if (GetCvar("naraka_Hitlerdamage") == 28)  { GiveInventory("PowerDamageBuff28",1); }
    if (GetCvar("naraka_Hitlerdamage") == 29)  { GiveInventory("PowerDamageBuff29",1); }
    if (GetCvar("naraka_Hitlerdamage") == 30)  { GiveInventory("PowerDamageBuff30",1); }
}
return 1;
}

function int HandleHitlerDefense(int respawning)
{
if (CheckInventory("HitlerClass") == 1)
{
    if (GetCvar("naraka_Hitlerdefense") != -10) { TakeInventory("PowerDefenseBuff-10",1); }
    if (GetCvar("naraka_Hitlerdefense") != -9)  { TakeInventory("PowerDefenseBuff-9",1); }
    if (GetCvar("naraka_Hitlerdefense") != -8)  { TakeInventory("PowerDefenseBuff-8",1); }
    if (GetCvar("naraka_Hitlerdefense") != -7)  { TakeInventory("PowerDefenseBuff-7",1); }
    if (GetCvar("naraka_Hitlerdefense") != -6)  { TakeInventory("PowerDefenseBuff-6",1); }
    if (GetCvar("naraka_Hitlerdefense") != -5)  { TakeInventory("PowerDefenseBuff-5",1); }
    if (GetCvar("naraka_Hitlerdefense") != -4)  { TakeInventory("PowerDefenseBuff-4",1); }
    if (GetCvar("naraka_Hitlerdefense") != -3)  { TakeInventory("PowerDefenseBuff-3",1); }
    if (GetCvar("naraka_Hitlerdefense") != -2)  { TakeInventory("PowerDefenseBuff-2",1); }
    if (GetCvar("naraka_Hitlerdefense") != -1)  { TakeInventory("PowerDefenseBuff-1",1); }
    if (GetCvar("naraka_Hitlerdefense") != 1)   { TakeInventory("PowerDefenseBuff1",1); }
    if (GetCvar("naraka_Hitlerdefense") != 2)   { TakeInventory("PowerDefenseBuff2",1); }
    if (GetCvar("naraka_Hitlerdefense") != 3)   { TakeInventory("PowerDefenseBuff3",1); }
    if (GetCvar("naraka_Hitlerdefense") != 4)   { TakeInventory("PowerDefenseBuff4",1); }
    if (GetCvar("naraka_Hitlerdefense") != 5)   { TakeInventory("PowerDefenseBuff5",1); }
    if (GetCvar("naraka_Hitlerdefense") != 6)   { TakeInventory("PowerDefenseBuff6",1); }
    if (GetCvar("naraka_Hitlerdefense") != 7)   { TakeInventory("PowerDefenseBuff7",1); }
    if (GetCvar("naraka_Hitlerdefense") != 8)   { TakeInventory("PowerDefenseBuff8",1); }
    if (GetCvar("naraka_Hitlerdefense") != 9)   { TakeInventory("PowerDefenseBuff9",1); }
    if (GetCvar("naraka_Hitlerdefense") != 10)  { TakeInventory("PowerDefenseBuff10",1); }
    if (GetCvar("naraka_Hitlerdefense") != 11)  { TakeInventory("PowerDefenseBuff11",1); }
    if (GetCvar("naraka_Hitlerdefense") != 12)  { TakeInventory("PowerDefenseBuff12",1); }
    if (GetCvar("naraka_Hitlerdefense") != 13)  { TakeInventory("PowerDefenseBuff13",1); }
    if (GetCvar("naraka_Hitlerdefense") != 14)  { TakeInventory("PowerDefenseBuff14",1); }
    if (GetCvar("naraka_Hitlerdefense") != 15)  { TakeInventory("PowerDefenseBuff15",1); }
    if (GetCvar("naraka_Hitlerdefense") != 16)  { TakeInventory("PowerDefenseBuff16",1); }
    if (GetCvar("naraka_Hitlerdefense") != 17)  { TakeInventory("PowerDefenseBuff17",1); }
    if (GetCvar("naraka_Hitlerdefense") != 18)  { TakeInventory("PowerDefenseBuff18",1); }
    if (GetCvar("naraka_Hitlerdefense") != 19)  { TakeInventory("PowerDefenseBuff19",1); }
    if (GetCvar("naraka_Hitlerdefense") != 20)  { TakeInventory("PowerDefenseBuff20",1); }
	
    if (GetCvar("naraka_Hitlerdefense") == -10) { GiveInventory("PowerDefenseBuff-10",1); }
    if (GetCvar("naraka_Hitlerdefense") == -9)  { GiveInventory("PowerDefenseBuff-9",1); }
    if (GetCvar("naraka_Hitlerdefense") == -8)  { GiveInventory("PowerDefenseBuff-8",1); }
    if (GetCvar("naraka_Hitlerdefense") == -7)  { GiveInventory("PowerDefenseBuff-7",1); }
    if (GetCvar("naraka_Hitlerdefense") == -6)  { GiveInventory("PowerDefenseBuff-6",1); }
    if (GetCvar("naraka_Hitlerdefense") == -5)  { GiveInventory("PowerDefenseBuff-5",1); }
    if (GetCvar("naraka_Hitlerdefense") == -4)  { GiveInventory("PowerDefenseBuff-4",1); }
    if (GetCvar("naraka_Hitlerdefense") == -3)  { GiveInventory("PowerDefenseBuff-3",1); }
    if (GetCvar("naraka_Hitlerdefense") == -2)  { GiveInventory("PowerDefenseBuff-2",1); }
    if (GetCvar("naraka_Hitlerdefense") == -1)  { GiveInventory("PowerDefenseBuff-1",1); }
    if (GetCvar("naraka_Hitlerdefense") == 1)   { GiveInventory("PowerDefenseBuff1",1); }
    if (GetCvar("naraka_Hitlerdefense") == 2)   { GiveInventory("PowerDefenseBuff2",1); }
    if (GetCvar("naraka_Hitlerdefense") == 3)   { GiveInventory("PowerDefenseBuff3",1); }
    if (GetCvar("naraka_Hitlerdefense") == 4)   { GiveInventory("PowerDefenseBuff4",1); }
    if (GetCvar("naraka_Hitlerdefense") == 5)   { GiveInventory("PowerDefenseBuff5",1); }
    if (GetCvar("naraka_Hitlerdefense") == 6)   { GiveInventory("PowerDefenseBuff6",1); }
    if (GetCvar("naraka_Hitlerdefense") == 7)   { GiveInventory("PowerDefenseBuff7",1); }
    if (GetCvar("naraka_Hitlerdefense") == 8)   { GiveInventory("PowerDefenseBuff8",1); }
    if (GetCvar("naraka_Hitlerdefense") == 9)   { GiveInventory("PowerDefenseBuff9",1); }
    if (GetCvar("naraka_Hitlerdefense") == 10)  { GiveInventory("PowerDefenseBuff10",1); }
    if (GetCvar("naraka_Hitlerdefense") == 11)  { GiveInventory("PowerDefenseBuff11",1); }
    if (GetCvar("naraka_Hitlerdefense") == 12)  { GiveInventory("PowerDefenseBuff12",1); }
    if (GetCvar("naraka_Hitlerdefense") == 13)  { GiveInventory("PowerDefenseBuff13",1); }
    if (GetCvar("naraka_Hitlerdefense") == 14)  { GiveInventory("PowerDefenseBuff14",1); }
    if (GetCvar("naraka_Hitlerdefense") == 15)  { GiveInventory("PowerDefenseBuff15",1); }
    if (GetCvar("naraka_Hitlerdefense") == 16)  { GiveInventory("PowerDefenseBuff16",1); }
    if (GetCvar("naraka_Hitlerdefense") == 17)  { GiveInventory("PowerDefenseBuff17",1); }
    if (GetCvar("naraka_Hitlerdefense") == 18)  { GiveInventory("PowerDefenseBuff18",1); }
    if (GetCvar("naraka_Hitlerdefense") == 19)  { GiveInventory("PowerDefenseBuff19",1); }
    if (GetCvar("naraka_Hitlerdefense") == 20)  { GiveInventory("PowerDefenseBuff20",1); }
}
return 1;
}

function int HandleKoraxDamage(int respawning)
{
if (CheckInventory("KoraxClass") == 1)
{
    if (GetCvar("naraka_Koraxdamage") != -10) { TakeInventory("PowerDamageBuff-10",1); }
    if (GetCvar("naraka_Koraxdamage") != -9)  { TakeInventory("PowerDamageBuff-9",1); }
    if (GetCvar("naraka_Koraxdamage") != -8)  { TakeInventory("PowerDamageBuff-8",1); }
    if (GetCvar("naraka_Koraxdamage") != -7)  { TakeInventory("PowerDamageBuff-7",1); }
    if (GetCvar("naraka_Koraxdamage") != -6)  { TakeInventory("PowerDamageBuff-6",1); }
    if (GetCvar("naraka_Koraxdamage") != -5)  { TakeInventory("PowerDamageBuff-5",1); }
    if (GetCvar("naraka_Koraxdamage") != -4)  { TakeInventory("PowerDamageBuff-4",1); }
    if (GetCvar("naraka_Koraxdamage") != -3)  { TakeInventory("PowerDamageBuff-3",1); }
    if (GetCvar("naraka_Koraxdamage") != -2)  { TakeInventory("PowerDamageBuff-2",1); }
    if (GetCvar("naraka_Koraxdamage") != -1)  { TakeInventory("PowerDamageBuff-1",1); }
    if (GetCvar("naraka_Koraxdamage") != 1)   { TakeInventory("PowerDamageBuff1",1); }
    if (GetCvar("naraka_Koraxdamage") != 2)   { TakeInventory("PowerDamageBuff2",1); }
    if (GetCvar("naraka_Koraxdamage") != 3)   { TakeInventory("PowerDamageBuff3",1); }
    if (GetCvar("naraka_Koraxdamage") != 4)   { TakeInventory("PowerDamageBuff4",1); }
    if (GetCvar("naraka_Koraxdamage") != 5)   { TakeInventory("PowerDamageBuff5",1); }
    if (GetCvar("naraka_Koraxdamage") != 6)   { TakeInventory("PowerDamageBuff6",1); }
    if (GetCvar("naraka_Koraxdamage") != 7)   { TakeInventory("PowerDamageBuff7",1); }
    if (GetCvar("naraka_Koraxdamage") != 8)   { TakeInventory("PowerDamageBuff8",1); }
    if (GetCvar("naraka_Koraxdamage") != 9)   { TakeInventory("PowerDamageBuff9",1); }
    if (GetCvar("naraka_Koraxdamage") != 10)  { TakeInventory("PowerDamageBuff10",1); }
    if (GetCvar("naraka_Koraxdamage") != 11)  { TakeInventory("PowerDamageBuff11",1); }
    if (GetCvar("naraka_Koraxdamage") != 12)  { TakeInventory("PowerDamageBuff12",1); }
    if (GetCvar("naraka_Koraxdamage") != 13)  { TakeInventory("PowerDamageBuff13",1); }
    if (GetCvar("naraka_Koraxdamage") != 14)  { TakeInventory("PowerDamageBuff14",1); }
    if (GetCvar("naraka_Koraxdamage") != 15)  { TakeInventory("PowerDamageBuff15",1); }
    if (GetCvar("naraka_Koraxdamage") != 16)  { TakeInventory("PowerDamageBuff16",1); }
    if (GetCvar("naraka_Koraxdamage") != 17)  { TakeInventory("PowerDamageBuff17",1); }
    if (GetCvar("naraka_Koraxdamage") != 18)  { TakeInventory("PowerDamageBuff18",1); }
    if (GetCvar("naraka_Koraxdamage") != 19)  { TakeInventory("PowerDamageBuff19",1); }
    if (GetCvar("naraka_Koraxdamage") != 20)  { TakeInventory("PowerDamageBuff20",1); }
    if (GetCvar("naraka_Koraxdamage") != 21)  { TakeInventory("PowerDamageBuff21",1); }
    if (GetCvar("naraka_Koraxdamage") != 22)  { TakeInventory("PowerDamageBuff22",1); }
    if (GetCvar("naraka_Koraxdamage") != 23)  { TakeInventory("PowerDamageBuff23",1); }
    if (GetCvar("naraka_Koraxdamage") != 24)  { TakeInventory("PowerDamageBuff24",1); }
    if (GetCvar("naraka_Koraxdamage") != 25)  { TakeInventory("PowerDamageBuff25",1); }
    if (GetCvar("naraka_Koraxdamage") != 26)  { TakeInventory("PowerDamageBuff26",1); }
    if (GetCvar("naraka_Koraxdamage") != 27)  { TakeInventory("PowerDamageBuff27",1); }
    if (GetCvar("naraka_Koraxdamage") != 28)  { TakeInventory("PowerDamageBuff28",1); }
    if (GetCvar("naraka_Koraxdamage") != 29)  { TakeInventory("PowerDamageBuff29",1); }
    if (GetCvar("naraka_Koraxdamage") != 30)  { TakeInventory("PowerDamageBuff30",1); }
	
    if (GetCvar("naraka_Koraxdamage") == -10) { GiveInventory("PowerDamageBuff-10",1); }
    if (GetCvar("naraka_Koraxdamage") == -9)  { GiveInventory("PowerDamageBuff-9",1); }
    if (GetCvar("naraka_Koraxdamage") == -8)  { GiveInventory("PowerDamageBuff-8",1); }
    if (GetCvar("naraka_Koraxdamage") == -7)  { GiveInventory("PowerDamageBuff-7",1); }
    if (GetCvar("naraka_Koraxdamage") == -6)  { GiveInventory("PowerDamageBuff-6",1); }
    if (GetCvar("naraka_Koraxdamage") == -5)  { GiveInventory("PowerDamageBuff-5",1); }
    if (GetCvar("naraka_Koraxdamage") == -4)  { GiveInventory("PowerDamageBuff-4",1); }
    if (GetCvar("naraka_Koraxdamage") == -3)  { GiveInventory("PowerDamageBuff-3",1); }
    if (GetCvar("naraka_Koraxdamage") == -2)  { GiveInventory("PowerDamageBuff-2",1); }
    if (GetCvar("naraka_Koraxdamage") == -1)  { GiveInventory("PowerDamageBuff-1",1); }
    if (GetCvar("naraka_Koraxdamage") == 1)   { GiveInventory("PowerDamageBuff1",1); }
    if (GetCvar("naraka_Koraxdamage") == 2)   { GiveInventory("PowerDamageBuff2",1); }
    if (GetCvar("naraka_Koraxdamage") == 3)   { GiveInventory("PowerDamageBuff3",1); }
    if (GetCvar("naraka_Koraxdamage") == 4)   { GiveInventory("PowerDamageBuff4",1); }
    if (GetCvar("naraka_Koraxdamage") == 5)   { GiveInventory("PowerDamageBuff5",1); }
    if (GetCvar("naraka_Koraxdamage") == 6)   { GiveInventory("PowerDamageBuff6",1); }
    if (GetCvar("naraka_Koraxdamage") == 7)   { GiveInventory("PowerDamageBuff7",1); }
    if (GetCvar("naraka_Koraxdamage") == 8)   { GiveInventory("PowerDamageBuff8",1); }
    if (GetCvar("naraka_Koraxdamage") == 9)   { GiveInventory("PowerDamageBuff9",1); }
    if (GetCvar("naraka_Koraxdamage") == 10)  { GiveInventory("PowerDamageBuff10",1); }
    if (GetCvar("naraka_Koraxdamage") == 11)  { GiveInventory("PowerDamageBuff11",1); }
    if (GetCvar("naraka_Koraxdamage") == 12)  { GiveInventory("PowerDamageBuff12",1); }
    if (GetCvar("naraka_Koraxdamage") == 13)  { GiveInventory("PowerDamageBuff13",1); }
    if (GetCvar("naraka_Koraxdamage") == 14)  { GiveInventory("PowerDamageBuff14",1); }
    if (GetCvar("naraka_Koraxdamage") == 15)  { GiveInventory("PowerDamageBuff15",1); }
    if (GetCvar("naraka_Koraxdamage") == 16)  { GiveInventory("PowerDamageBuff16",1); }
    if (GetCvar("naraka_Koraxdamage") == 17)  { GiveInventory("PowerDamageBuff17",1); }
    if (GetCvar("naraka_Koraxdamage") == 18)  { GiveInventory("PowerDamageBuff18",1); }
    if (GetCvar("naraka_Koraxdamage") == 19)  { GiveInventory("PowerDamageBuff19",1); }
    if (GetCvar("naraka_Koraxdamage") == 20)  { GiveInventory("PowerDamageBuff20",1); }
    if (GetCvar("naraka_Koraxdamage") == 21)  { GiveInventory("PowerDamageBuff21",1); }
    if (GetCvar("naraka_Koraxdamage") == 22)  { GiveInventory("PowerDamageBuff22",1); }
    if (GetCvar("naraka_Koraxdamage") == 23)  { GiveInventory("PowerDamageBuff23",1); }
    if (GetCvar("naraka_Koraxdamage") == 24)  { GiveInventory("PowerDamageBuff24",1); }
    if (GetCvar("naraka_Koraxdamage") == 25)  { GiveInventory("PowerDamageBuff25",1); }
    if (GetCvar("naraka_Koraxdamage") == 26)  { GiveInventory("PowerDamageBuff26",1); }
    if (GetCvar("naraka_Koraxdamage") == 27)  { GiveInventory("PowerDamageBuff27",1); }
    if (GetCvar("naraka_Koraxdamage") == 28)  { GiveInventory("PowerDamageBuff28",1); }
    if (GetCvar("naraka_Koraxdamage") == 29)  { GiveInventory("PowerDamageBuff29",1); }
    if (GetCvar("naraka_Koraxdamage") == 30)  { GiveInventory("PowerDamageBuff30",1); }
}
return 1;
}

function int HandleKoraxDefense(int respawning)
{
if (CheckInventory("KoraxClass") == 1)
{
    if (GetCvar("naraka_Koraxdefense") != -10) { TakeInventory("PowerDefenseBuff-10",1); }
    if (GetCvar("naraka_Koraxdefense") != -9)  { TakeInventory("PowerDefenseBuff-9",1); }
    if (GetCvar("naraka_Koraxdefense") != -8)  { TakeInventory("PowerDefenseBuff-8",1); }
    if (GetCvar("naraka_Koraxdefense") != -7)  { TakeInventory("PowerDefenseBuff-7",1); }
    if (GetCvar("naraka_Koraxdefense") != -6)  { TakeInventory("PowerDefenseBuff-6",1); }
    if (GetCvar("naraka_Koraxdefense") != -5)  { TakeInventory("PowerDefenseBuff-5",1); }
    if (GetCvar("naraka_Koraxdefense") != -4)  { TakeInventory("PowerDefenseBuff-4",1); }
    if (GetCvar("naraka_Koraxdefense") != -3)  { TakeInventory("PowerDefenseBuff-3",1); }
    if (GetCvar("naraka_Koraxdefense") != -2)  { TakeInventory("PowerDefenseBuff-2",1); }
    if (GetCvar("naraka_Koraxdefense") != -1)  { TakeInventory("PowerDefenseBuff-1",1); }
    if (GetCvar("naraka_Koraxdefense") != 1)   { TakeInventory("PowerDefenseBuff1",1); }
    if (GetCvar("naraka_Koraxdefense") != 2)   { TakeInventory("PowerDefenseBuff2",1); }
    if (GetCvar("naraka_Koraxdefense") != 3)   { TakeInventory("PowerDefenseBuff3",1); }
    if (GetCvar("naraka_Koraxdefense") != 4)   { TakeInventory("PowerDefenseBuff4",1); }
    if (GetCvar("naraka_Koraxdefense") != 5)   { TakeInventory("PowerDefenseBuff5",1); }
    if (GetCvar("naraka_Koraxdefense") != 6)   { TakeInventory("PowerDefenseBuff6",1); }
    if (GetCvar("naraka_Koraxdefense") != 7)   { TakeInventory("PowerDefenseBuff7",1); }
    if (GetCvar("naraka_Koraxdefense") != 8)   { TakeInventory("PowerDefenseBuff8",1); }
    if (GetCvar("naraka_Koraxdefense") != 9)   { TakeInventory("PowerDefenseBuff9",1); }
    if (GetCvar("naraka_Koraxdefense") != 10)  { TakeInventory("PowerDefenseBuff10",1); }
    if (GetCvar("naraka_Koraxdefense") != 11)  { TakeInventory("PowerDefenseBuff11",1); }
    if (GetCvar("naraka_Koraxdefense") != 12)  { TakeInventory("PowerDefenseBuff12",1); }
    if (GetCvar("naraka_Koraxdefense") != 13)  { TakeInventory("PowerDefenseBuff13",1); }
    if (GetCvar("naraka_Koraxdefense") != 14)  { TakeInventory("PowerDefenseBuff14",1); }
    if (GetCvar("naraka_Koraxdefense") != 15)  { TakeInventory("PowerDefenseBuff15",1); }
    if (GetCvar("naraka_Koraxdefense") != 16)  { TakeInventory("PowerDefenseBuff16",1); }
    if (GetCvar("naraka_Koraxdefense") != 17)  { TakeInventory("PowerDefenseBuff17",1); }
    if (GetCvar("naraka_Koraxdefense") != 18)  { TakeInventory("PowerDefenseBuff18",1); }
    if (GetCvar("naraka_Koraxdefense") != 19)  { TakeInventory("PowerDefenseBuff19",1); }
    if (GetCvar("naraka_Koraxdefense") != 20)  { TakeInventory("PowerDefenseBuff20",1); }
	
    if (GetCvar("naraka_Koraxdefense") == -10) { GiveInventory("PowerDefenseBuff-10",1); }
    if (GetCvar("naraka_Koraxdefense") == -9)  { GiveInventory("PowerDefenseBuff-9",1); }
    if (GetCvar("naraka_Koraxdefense") == -8)  { GiveInventory("PowerDefenseBuff-8",1); }
    if (GetCvar("naraka_Koraxdefense") == -7)  { GiveInventory("PowerDefenseBuff-7",1); }
    if (GetCvar("naraka_Koraxdefense") == -6)  { GiveInventory("PowerDefenseBuff-6",1); }
    if (GetCvar("naraka_Koraxdefense") == -5)  { GiveInventory("PowerDefenseBuff-5",1); }
    if (GetCvar("naraka_Koraxdefense") == -4)  { GiveInventory("PowerDefenseBuff-4",1); }
    if (GetCvar("naraka_Koraxdefense") == -3)  { GiveInventory("PowerDefenseBuff-3",1); }
    if (GetCvar("naraka_Koraxdefense") == -2)  { GiveInventory("PowerDefenseBuff-2",1); }
    if (GetCvar("naraka_Koraxdefense") == -1)  { GiveInventory("PowerDefenseBuff-1",1); }
    if (GetCvar("naraka_Koraxdefense") == 1)   { GiveInventory("PowerDefenseBuff1",1); }
    if (GetCvar("naraka_Koraxdefense") == 2)   { GiveInventory("PowerDefenseBuff2",1); }
    if (GetCvar("naraka_Koraxdefense") == 3)   { GiveInventory("PowerDefenseBuff3",1); }
    if (GetCvar("naraka_Koraxdefense") == 4)   { GiveInventory("PowerDefenseBuff4",1); }
    if (GetCvar("naraka_Koraxdefense") == 5)   { GiveInventory("PowerDefenseBuff5",1); }
    if (GetCvar("naraka_Koraxdefense") == 6)   { GiveInventory("PowerDefenseBuff6",1); }
    if (GetCvar("naraka_Koraxdefense") == 7)   { GiveInventory("PowerDefenseBuff7",1); }
    if (GetCvar("naraka_Koraxdefense") == 8)   { GiveInventory("PowerDefenseBuff8",1); }
    if (GetCvar("naraka_Koraxdefense") == 9)   { GiveInventory("PowerDefenseBuff9",1); }
    if (GetCvar("naraka_Koraxdefense") == 10)  { GiveInventory("PowerDefenseBuff10",1); }
    if (GetCvar("naraka_Koraxdefense") == 11)  { GiveInventory("PowerDefenseBuff11",1); }
    if (GetCvar("naraka_Koraxdefense") == 12)  { GiveInventory("PowerDefenseBuff12",1); }
    if (GetCvar("naraka_Koraxdefense") == 13)  { GiveInventory("PowerDefenseBuff13",1); }
    if (GetCvar("naraka_Koraxdefense") == 14)  { GiveInventory("PowerDefenseBuff14",1); }
    if (GetCvar("naraka_Koraxdefense") == 15)  { GiveInventory("PowerDefenseBuff15",1); }
    if (GetCvar("naraka_Koraxdefense") == 16)  { GiveInventory("PowerDefenseBuff16",1); }
    if (GetCvar("naraka_Koraxdefense") == 17)  { GiveInventory("PowerDefenseBuff17",1); }
    if (GetCvar("naraka_Koraxdefense") == 18)  { GiveInventory("PowerDefenseBuff18",1); }
    if (GetCvar("naraka_Koraxdefense") == 19)  { GiveInventory("PowerDefenseBuff19",1); }
    if (GetCvar("naraka_Koraxdefense") == 20)  { GiveInventory("PowerDefenseBuff20",1); }
}
return 1;
}

function int HandleTfearDamage(int respawning)
{
if (CheckInventory("TfearClass") == 1)
{
    if (GetCvar("naraka_Tfeardamage") != -10) { TakeInventory("PowerDamageBuff-10",1); }
    if (GetCvar("naraka_Tfeardamage") != -9)  { TakeInventory("PowerDamageBuff-9",1); }
    if (GetCvar("naraka_Tfeardamage") != -8)  { TakeInventory("PowerDamageBuff-8",1); }
    if (GetCvar("naraka_Tfeardamage") != -7)  { TakeInventory("PowerDamageBuff-7",1); }
    if (GetCvar("naraka_Tfeardamage") != -6)  { TakeInventory("PowerDamageBuff-6",1); }
    if (GetCvar("naraka_Tfeardamage") != -5)  { TakeInventory("PowerDamageBuff-5",1); }
    if (GetCvar("naraka_Tfeardamage") != -4)  { TakeInventory("PowerDamageBuff-4",1); }
    if (GetCvar("naraka_Tfeardamage") != -3)  { TakeInventory("PowerDamageBuff-3",1); }
    if (GetCvar("naraka_Tfeardamage") != -2)  { TakeInventory("PowerDamageBuff-2",1); }
    if (GetCvar("naraka_Tfeardamage") != -1)  { TakeInventory("PowerDamageBuff-1",1); }
    if (GetCvar("naraka_Tfeardamage") != 1)   { TakeInventory("PowerDamageBuff1",1); }
    if (GetCvar("naraka_Tfeardamage") != 2)   { TakeInventory("PowerDamageBuff2",1); }
    if (GetCvar("naraka_Tfeardamage") != 3)   { TakeInventory("PowerDamageBuff3",1); }
    if (GetCvar("naraka_Tfeardamage") != 4)   { TakeInventory("PowerDamageBuff4",1); }
    if (GetCvar("naraka_Tfeardamage") != 5)   { TakeInventory("PowerDamageBuff5",1); }
    if (GetCvar("naraka_Tfeardamage") != 6)   { TakeInventory("PowerDamageBuff6",1); }
    if (GetCvar("naraka_Tfeardamage") != 7)   { TakeInventory("PowerDamageBuff7",1); }
    if (GetCvar("naraka_Tfeardamage") != 8)   { TakeInventory("PowerDamageBuff8",1); }
    if (GetCvar("naraka_Tfeardamage") != 9)   { TakeInventory("PowerDamageBuff9",1); }
    if (GetCvar("naraka_Tfeardamage") != 10)  { TakeInventory("PowerDamageBuff10",1); }
    if (GetCvar("naraka_Tfeardamage") != 11)  { TakeInventory("PowerDamageBuff11",1); }
    if (GetCvar("naraka_Tfeardamage") != 12)  { TakeInventory("PowerDamageBuff12",1); }
    if (GetCvar("naraka_Tfeardamage") != 13)  { TakeInventory("PowerDamageBuff13",1); }
    if (GetCvar("naraka_Tfeardamage") != 14)  { TakeInventory("PowerDamageBuff14",1); }
    if (GetCvar("naraka_Tfeardamage") != 15)  { TakeInventory("PowerDamageBuff15",1); }
    if (GetCvar("naraka_Tfeardamage") != 16)  { TakeInventory("PowerDamageBuff16",1); }
    if (GetCvar("naraka_Tfeardamage") != 17)  { TakeInventory("PowerDamageBuff17",1); }
    if (GetCvar("naraka_Tfeardamage") != 18)  { TakeInventory("PowerDamageBuff18",1); }
    if (GetCvar("naraka_Tfeardamage") != 19)  { TakeInventory("PowerDamageBuff19",1); }
    if (GetCvar("naraka_Tfeardamage") != 20)  { TakeInventory("PowerDamageBuff20",1); }
    if (GetCvar("naraka_Tfeardamage") != 21)  { TakeInventory("PowerDamageBuff21",1); }
    if (GetCvar("naraka_Tfeardamage") != 22)  { TakeInventory("PowerDamageBuff22",1); }
    if (GetCvar("naraka_Tfeardamage") != 23)  { TakeInventory("PowerDamageBuff23",1); }
    if (GetCvar("naraka_Tfeardamage") != 24)  { TakeInventory("PowerDamageBuff24",1); }
    if (GetCvar("naraka_Tfeardamage") != 25)  { TakeInventory("PowerDamageBuff25",1); }
    if (GetCvar("naraka_Tfeardamage") != 26)  { TakeInventory("PowerDamageBuff26",1); }
    if (GetCvar("naraka_Tfeardamage") != 27)  { TakeInventory("PowerDamageBuff27",1); }
    if (GetCvar("naraka_Tfeardamage") != 28)  { TakeInventory("PowerDamageBuff28",1); }
    if (GetCvar("naraka_Tfeardamage") != 29)  { TakeInventory("PowerDamageBuff29",1); }
    if (GetCvar("naraka_Tfeardamage") != 30)  { TakeInventory("PowerDamageBuff30",1); }
	
    if (GetCvar("naraka_Tfeardamage") == -10) { GiveInventory("PowerDamageBuff-10",1); }
    if (GetCvar("naraka_Tfeardamage") == -9)  { GiveInventory("PowerDamageBuff-9",1); }
    if (GetCvar("naraka_Tfeardamage") == -8)  { GiveInventory("PowerDamageBuff-8",1); }
    if (GetCvar("naraka_Tfeardamage") == -7)  { GiveInventory("PowerDamageBuff-7",1); }
    if (GetCvar("naraka_Tfeardamage") == -6)  { GiveInventory("PowerDamageBuff-6",1); }
    if (GetCvar("naraka_Tfeardamage") == -5)  { GiveInventory("PowerDamageBuff-5",1); }
    if (GetCvar("naraka_Tfeardamage") == -4)  { GiveInventory("PowerDamageBuff-4",1); }
    if (GetCvar("naraka_Tfeardamage") == -3)  { GiveInventory("PowerDamageBuff-3",1); }
    if (GetCvar("naraka_Tfeardamage") == -2)  { GiveInventory("PowerDamageBuff-2",1); }
    if (GetCvar("naraka_Tfeardamage") == -1)  { GiveInventory("PowerDamageBuff-1",1); }
    if (GetCvar("naraka_Tfeardamage") == 1)   { GiveInventory("PowerDamageBuff1",1); }
    if (GetCvar("naraka_Tfeardamage") == 2)   { GiveInventory("PowerDamageBuff2",1); }
    if (GetCvar("naraka_Tfeardamage") == 3)   { GiveInventory("PowerDamageBuff3",1); }
    if (GetCvar("naraka_Tfeardamage") == 4)   { GiveInventory("PowerDamageBuff4",1); }
    if (GetCvar("naraka_Tfeardamage") == 5)   { GiveInventory("PowerDamageBuff5",1); }
    if (GetCvar("naraka_Tfeardamage") == 6)   { GiveInventory("PowerDamageBuff6",1); }
    if (GetCvar("naraka_Tfeardamage") == 7)   { GiveInventory("PowerDamageBuff7",1); }
    if (GetCvar("naraka_Tfeardamage") == 8)   { GiveInventory("PowerDamageBuff8",1); }
    if (GetCvar("naraka_Tfeardamage") == 9)   { GiveInventory("PowerDamageBuff9",1); }
    if (GetCvar("naraka_Tfeardamage") == 10)  { GiveInventory("PowerDamageBuff10",1); }
    if (GetCvar("naraka_Tfeardamage") == 11)  { GiveInventory("PowerDamageBuff11",1); }
    if (GetCvar("naraka_Tfeardamage") == 12)  { GiveInventory("PowerDamageBuff12",1); }
    if (GetCvar("naraka_Tfeardamage") == 13)  { GiveInventory("PowerDamageBuff13",1); }
    if (GetCvar("naraka_Tfeardamage") == 14)  { GiveInventory("PowerDamageBuff14",1); }
    if (GetCvar("naraka_Tfeardamage") == 15)  { GiveInventory("PowerDamageBuff15",1); }
    if (GetCvar("naraka_Tfeardamage") == 16)  { GiveInventory("PowerDamageBuff16",1); }
    if (GetCvar("naraka_Tfeardamage") == 17)  { GiveInventory("PowerDamageBuff17",1); }
    if (GetCvar("naraka_Tfeardamage") == 18)  { GiveInventory("PowerDamageBuff18",1); }
    if (GetCvar("naraka_Tfeardamage") == 19)  { GiveInventory("PowerDamageBuff19",1); }
    if (GetCvar("naraka_Tfeardamage") == 20)  { GiveInventory("PowerDamageBuff20",1); }
    if (GetCvar("naraka_Tfeardamage") == 21)  { GiveInventory("PowerDamageBuff21",1); }
    if (GetCvar("naraka_Tfeardamage") == 22)  { GiveInventory("PowerDamageBuff22",1); }
    if (GetCvar("naraka_Tfeardamage") == 23)  { GiveInventory("PowerDamageBuff23",1); }
    if (GetCvar("naraka_Tfeardamage") == 24)  { GiveInventory("PowerDamageBuff24",1); }
    if (GetCvar("naraka_Tfeardamage") == 25)  { GiveInventory("PowerDamageBuff25",1); }
    if (GetCvar("naraka_Tfeardamage") == 26)  { GiveInventory("PowerDamageBuff26",1); }
    if (GetCvar("naraka_Tfeardamage") == 27)  { GiveInventory("PowerDamageBuff27",1); }
    if (GetCvar("naraka_Tfeardamage") == 28)  { GiveInventory("PowerDamageBuff28",1); }
    if (GetCvar("naraka_Tfeardamage") == 29)  { GiveInventory("PowerDamageBuff29",1); }
    if (GetCvar("naraka_Tfeardamage") == 30)  { GiveInventory("PowerDamageBuff30",1); }
}
return 1;
}

function int HandleTfearDefense(int respawning)
{
if (CheckInventory("TfearClass") == 1)
{
    if (GetCvar("naraka_Tfeardefense") != -10) { TakeInventory("PowerDefenseBuff-10",1); }
    if (GetCvar("naraka_Tfeardefense") != -9)  { TakeInventory("PowerDefenseBuff-9",1); }
    if (GetCvar("naraka_Tfeardefense") != -8)  { TakeInventory("PowerDefenseBuff-8",1); }
    if (GetCvar("naraka_Tfeardefense") != -7)  { TakeInventory("PowerDefenseBuff-7",1); }
    if (GetCvar("naraka_Tfeardefense") != -6)  { TakeInventory("PowerDefenseBuff-6",1); }
    if (GetCvar("naraka_Tfeardefense") != -5)  { TakeInventory("PowerDefenseBuff-5",1); }
    if (GetCvar("naraka_Tfeardefense") != -4)  { TakeInventory("PowerDefenseBuff-4",1); }
    if (GetCvar("naraka_Tfeardefense") != -3)  { TakeInventory("PowerDefenseBuff-3",1); }
    if (GetCvar("naraka_Tfeardefense") != -2)  { TakeInventory("PowerDefenseBuff-2",1); }
    if (GetCvar("naraka_Tfeardefense") != -1)  { TakeInventory("PowerDefenseBuff-1",1); }
    if (GetCvar("naraka_Tfeardefense") != 1)   { TakeInventory("PowerDefenseBuff1",1); }
    if (GetCvar("naraka_Tfeardefense") != 2)   { TakeInventory("PowerDefenseBuff2",1); }
    if (GetCvar("naraka_Tfeardefense") != 3)   { TakeInventory("PowerDefenseBuff3",1); }
    if (GetCvar("naraka_Tfeardefense") != 4)   { TakeInventory("PowerDefenseBuff4",1); }
    if (GetCvar("naraka_Tfeardefense") != 5)   { TakeInventory("PowerDefenseBuff5",1); }
    if (GetCvar("naraka_Tfeardefense") != 6)   { TakeInventory("PowerDefenseBuff6",1); }
    if (GetCvar("naraka_Tfeardefense") != 7)   { TakeInventory("PowerDefenseBuff7",1); }
    if (GetCvar("naraka_Tfeardefense") != 8)   { TakeInventory("PowerDefenseBuff8",1); }
    if (GetCvar("naraka_Tfeardefense") != 9)   { TakeInventory("PowerDefenseBuff9",1); }
    if (GetCvar("naraka_Tfeardefense") != 10)  { TakeInventory("PowerDefenseBuff10",1); }
    if (GetCvar("naraka_Tfeardefense") != 11)  { TakeInventory("PowerDefenseBuff11",1); }
    if (GetCvar("naraka_Tfeardefense") != 12)  { TakeInventory("PowerDefenseBuff12",1); }
    if (GetCvar("naraka_Tfeardefense") != 13)  { TakeInventory("PowerDefenseBuff13",1); }
    if (GetCvar("naraka_Tfeardefense") != 14)  { TakeInventory("PowerDefenseBuff14",1); }
    if (GetCvar("naraka_Tfeardefense") != 15)  { TakeInventory("PowerDefenseBuff15",1); }
    if (GetCvar("naraka_Tfeardefense") != 16)  { TakeInventory("PowerDefenseBuff16",1); }
    if (GetCvar("naraka_Tfeardefense") != 17)  { TakeInventory("PowerDefenseBuff17",1); }
    if (GetCvar("naraka_Tfeardefense") != 18)  { TakeInventory("PowerDefenseBuff18",1); }
    if (GetCvar("naraka_Tfeardefense") != 19)  { TakeInventory("PowerDefenseBuff19",1); }
    if (GetCvar("naraka_Tfeardefense") != 20)  { TakeInventory("PowerDefenseBuff20",1); }
	
    if (GetCvar("naraka_Tfeardefense") == -10) { GiveInventory("PowerDefenseBuff-10",1); }
    if (GetCvar("naraka_Tfeardefense") == -9)  { GiveInventory("PowerDefenseBuff-9",1); }
    if (GetCvar("naraka_Tfeardefense") == -8)  { GiveInventory("PowerDefenseBuff-8",1); }
    if (GetCvar("naraka_Tfeardefense") == -7)  { GiveInventory("PowerDefenseBuff-7",1); }
    if (GetCvar("naraka_Tfeardefense") == -6)  { GiveInventory("PowerDefenseBuff-6",1); }
    if (GetCvar("naraka_Tfeardefense") == -5)  { GiveInventory("PowerDefenseBuff-5",1); }
    if (GetCvar("naraka_Tfeardefense") == -4)  { GiveInventory("PowerDefenseBuff-4",1); }
    if (GetCvar("naraka_Tfeardefense") == -3)  { GiveInventory("PowerDefenseBuff-3",1); }
    if (GetCvar("naraka_Tfeardefense") == -2)  { GiveInventory("PowerDefenseBuff-2",1); }
    if (GetCvar("naraka_Tfeardefense") == -1)  { GiveInventory("PowerDefenseBuff-1",1); }
    if (GetCvar("naraka_Tfeardefense") == 1)   { GiveInventory("PowerDefenseBuff1",1); }
    if (GetCvar("naraka_Tfeardefense") == 2)   { GiveInventory("PowerDefenseBuff2",1); }
    if (GetCvar("naraka_Tfeardefense") == 3)   { GiveInventory("PowerDefenseBuff3",1); }
    if (GetCvar("naraka_Tfeardefense") == 4)   { GiveInventory("PowerDefenseBuff4",1); }
    if (GetCvar("naraka_Tfeardefense") == 5)   { GiveInventory("PowerDefenseBuff5",1); }
    if (GetCvar("naraka_Tfeardefense") == 6)   { GiveInventory("PowerDefenseBuff6",1); }
    if (GetCvar("naraka_Tfeardefense") == 7)   { GiveInventory("PowerDefenseBuff7",1); }
    if (GetCvar("naraka_Tfeardefense") == 8)   { GiveInventory("PowerDefenseBuff8",1); }
    if (GetCvar("naraka_Tfeardefense") == 9)   { GiveInventory("PowerDefenseBuff9",1); }
    if (GetCvar("naraka_Tfeardefense") == 10)  { GiveInventory("PowerDefenseBuff10",1); }
    if (GetCvar("naraka_Tfeardefense") == 11)  { GiveInventory("PowerDefenseBuff11",1); }
    if (GetCvar("naraka_Tfeardefense") == 12)  { GiveInventory("PowerDefenseBuff12",1); }
    if (GetCvar("naraka_Tfeardefense") == 13)  { GiveInventory("PowerDefenseBuff13",1); }
    if (GetCvar("naraka_Tfeardefense") == 14)  { GiveInventory("PowerDefenseBuff14",1); }
    if (GetCvar("naraka_Tfeardefense") == 15)  { GiveInventory("PowerDefenseBuff15",1); }
    if (GetCvar("naraka_Tfeardefense") == 16)  { GiveInventory("PowerDefenseBuff16",1); }
    if (GetCvar("naraka_Tfeardefense") == 17)  { GiveInventory("PowerDefenseBuff17",1); }
    if (GetCvar("naraka_Tfeardefense") == 18)  { GiveInventory("PowerDefenseBuff18",1); }
    if (GetCvar("naraka_Tfeardefense") == 19)  { GiveInventory("PowerDefenseBuff19",1); }
    if (GetCvar("naraka_Tfeardefense") == 20)  { GiveInventory("PowerDefenseBuff20",1); }
}
return 1;
}