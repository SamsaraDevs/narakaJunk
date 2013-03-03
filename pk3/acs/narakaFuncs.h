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
