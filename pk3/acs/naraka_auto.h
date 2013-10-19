script 899 open
{
while (1)
    {
        // I'd use defaultCVar but best-ever breaks on it for some reason :/
        if (!GetCVar("naraka_bancyber"))
        {   ConsoleCommand("set naraka_bancyber 0");
        ConsoleCommand("archivecvar naraka_bancyber"); }
        
        if (!GetCVar("naraka_bandsparil"))
        {   ConsoleCommand("set naraka_bandsparil 0");
        ConsoleCommand("archivecvar naraka_bandsparil"); }
        
        if (!GetCVar("naraka_banhitler"))
        {   ConsoleCommand("set naraka_banhitler 0");
        ConsoleCommand("archivecvar naraka_banhitler"); }
        
        if (!GetCVar("naraka_bankorax"))
        {   ConsoleCommand("set naraka_bankorax 0");
        ConsoleCommand("archivecvar naraka_bankorax"); }
        
        if (!GetCVar("naraka_bantfear"))
        {   ConsoleCommand("set naraka_bantfear 0");
        ConsoleCommand("archivecvar naraka_bantfear"); }
        
        if (!GetCVar("naraka_cyberdamage"))
        {   ConsoleCommand("set naraka_cyberdamage 0");
        ConsoleCommand("archivecvar naraka_cyberdamage"); }
        
        if (!GetCVar("naraka_cyberdefense"))
        {   ConsoleCommand("set naraka_cyberdefense 0");
        ConsoleCommand("archivecvar naraka_cyberdefense"); }
        
        if (!GetCVar("naraka_dsparildamage"))
        {   ConsoleCommand("set naraka_dsparildamage 0");
        ConsoleCommand("archivecvar naraka_dsparildamage"); }
        
        if (!GetCVar("naraka_dsparildefense"))
        {   ConsoleCommand("set naraka_dsparildefense 0");
        ConsoleCommand("archivecvar naraka_dsparildefense"); }
        
        if (!GetCVar("naraka_hitlerdamage"))
        {   ConsoleCommand("set naraka_hitlerdamage 0");
        ConsoleCommand("archivecvar naraka_hitlerdamage"); }
        
        if (!GetCVar("naraka_hitlerdefense"))
        {   ConsoleCommand("set naraka_hitlerdefense 0");
        ConsoleCommand("archivecvar naraka_hitlerdefense"); }
        
        if (!GetCVar("naraka_koraxdamage"))
        {   ConsoleCommand("set naraka_koraxdamage 0");
        ConsoleCommand("archivecvar naraka_koraxdamage"); }
        
        if (!GetCVar("naraka_koraxdefense"))
        {   ConsoleCommand("set naraka_koraxdefense 0");
        ConsoleCommand("archivecvar naraka_koraxdefense"); }
        
        if (!GetCVar("naraka_tfeardamage"))
        {   ConsoleCommand("set naraka_tfeardamage 0");
        ConsoleCommand("archivecvar naraka_tfeardamage"); }
        
        if (!GetCVar("naraka_tfeardefense"))
        {   ConsoleCommand("set naraka_tfeardefense 0");
        ConsoleCommand("archivecvar naraka_tfeardefense"); }
        
        if (!GetCVar("naraka_teambalancer"))
        {   ConsoleCommand("set naraka_teambalancer 1");
        ConsoleCommand("archivecvar naraka_teambalancer"); }
		
        Delay(1);
    }
}

script 890 ENTER//(int respawning) // This differs from Naraka_Spawn in that this is a constant loop to be played.
{
    int i;
	int respawning;
	
	//while (1)
    //{
	if(CheckInventory("IsNarakaClass") == 1)
	{
	    if (CheckInventory("HitlerClass") == 1)
          { if (CheckInventory("Health") > 0)
            { if (!CheckInventory("HitlerLostArmor"))
              { if (!CheckInventory("Armor"))
                { SetActorState(0,"LoseMech"); } } } }
				
		if (CheckInventory("HitlerClass") == 1)
		  { if (CheckInventory("HitlerLostArmor") == 1) { SetActorProperty(0,APROP_Speed,1.55); }
		    else { SetActorProperty(0,APROP_Speed,1.00); }
		  }
		
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
		
		if (GetCvar("naraka_bancyber") == 1) { ACS_ExecuteAlways(910,0,0); }
		//if (GetCvar("naraka_bansnotfolus") == 1) { ACS_ExecuteAlways(910,0,1); }
		if (GetCvar("naraka_bandsparil") == 1) { ACS_ExecuteAlways(910,0,2); }
		if (GetCvar("naraka_banhitler") == 1) { ACS_ExecuteAlways(910,0,3); }
		if (GetCvar("naraka_bankorax") == 1) { ACS_ExecuteAlways(910,0,4); }
		//if (GetCvar("naraka_banproton") == 1) { ACS_ExecuteAlways(910,0,5); }
		if (GetCvar("naraka_bantfear") == 1) { ACS_ExecuteAlways(910,0,6); }
		//if (GetCvar("naraka_banshambler") == 1) { ACS_ExecuteAlways(910,0,7); }
		
		// POWERUPS SHIT
		// Because this seems to break on co-op
	    if(CheckInventory("GotWeapon0") == 1) { GiveInventory("CoopLesserBamf",1); }
		else { TakeInventory("CoopLesserBamf",1); }
	    if(CheckInventory("GotWeapon2") == 1) { GiveInventory("CoopHaloMode",1); }
		else { TakeInventory("CoopHaloMode",1); }
	    if(CheckInventory("GotWeapon3") == 1) { GiveInventory("CoopBeefStringy",1); }
		else { TakeInventory("CoopBeefStringy",1); }
	    if(CheckInventory("GotWeapon4") == 1) { GiveInventory("CoopCawadootyMode",1); }
		else { TakeInventory("CoopCawadootyMode",1); }
	    if(CheckInventory("GotWeapon5") == 1) { GiveInventory("CoopBeef",1); }
		else { TakeInventory("CoopBeef",1); }
	    if(CheckInventory("GotWeapon6") == 1) { GiveInventory("CoopBamf",1); }
		else { TakeInventory("CoopBamf",1); }
		
		if (!respawning)
		{
        HandleCyberDamage(respawning);
        HandleCyberDefense(respawning);
        //HandleSnotfolusDamage();
        //HandleSnotfolusDefense();
        HandleDSparilDamage(respawning);
        HandleDSparilDefense(respawning);
        HandleHitlerDamage(respawning);
        HandleHitlerDefense(respawning);
        HandleKoraxDamage(respawning);
        HandleKoraxDefense(respawning);
        //HandleProtonDamage();
        //HandleProtonDefense();
        HandleTfearDamage(respawning);
        HandleTfearDefense(respawning);
        //HandleShamblerDamage();
        //HandleShamblerDefense();
		}
	}
    Delay(1);
	Restart;
}

//script 891 enter { ACS_ExecuteWithResult(890, 0,0,0); }
script 891 respawn { ACS_ExecuteWithResult(890, 0,0,0); }
script 892 return { ACS_ExecuteWithResult(890, 0,0,0); }

script 476 ENTER
{
    while (1)
    {
        if (CheckInventory("CyberdemonClass") == 1)
        { GiveInventory("VillainAmmoHeavy", 1); }
        if (CheckInventory("CoopCawadootyMode") == 1)
        { GiveInventory("HealPack0",1); }
        if (CheckInventory("CoopHaloMode") == 1)
        { GiveInventory("ArmorScrap",1); }
        delay(175);
    }
}