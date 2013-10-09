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
		
        Delay(1);
    }
}

script 910 (int which) CLIENTSIDE
{
if (PlayerNumber() != ConsolePlayerNumber()) { terminate; }
switch (which)
    {
    case 0:
	    if (CheckInventory("CyberdemonClass") == 1)
		{ Print(s:"\c[m7]The admin has banned the \crCyberdemon\c[m7] from play.");
		ConsoleCommand("spectate"); } //KickFromGame(0,"\c[m7]The admin has banned \cdDoomguy\c[m7] from play."); }
		break;
	
	case 1:
		if (CheckInventory("SnotfolusClass") == 1)
		{ Print(s:"\c[m7]The admin has banned \c[m4]Lord Snotfolus\c[m7] from play.");
		ConsoleCommand("spectate"); } 
		break;
		
	case 2:
		if (CheckInventory("DsparilClass") == 1)
		{ Print(s:"\c[m7]The admin has banned \c[c3]D'Sparil\c[m7] from play.");
		ConsoleCommand("spectate"); } 
		break;
		
	case 3:
		if (CheckInventory("HitlerClass") == 1)
		{ Print(s:"\c[m7]The admin has banned \cbAdolf Hitler\c[m7] from play.");
		ConsoleCommand("spectate"); } 
		break;
		
	case 4:
		if (CheckInventory("KoraxClass") == 1)
		{ Print(s:"\c[m7]The admin has banned \cuKorax\c[m7] from play.");
		ConsoleCommand("spectate"); } 
		break;
		
	case 5:
		if (CheckInventory("ProtonClass") == 1)
		{ Print(s:"\c[m7]The admin has banned \c[q2]Dr. Proton\c[m7] from play.");
		ConsoleCommand("spectate"); } 
		break;
		
	case 6:
		if (CheckInventory("TfearClass") == 1)
		{ Print(s:"\c[m7]The admin has banned \ctAdmiral Tfear\c[m7] from play.");
		ConsoleCommand("spectate"); } 
		break;
		
	case 7:
		if (CheckInventory("ShamblerClass") == 1)
		{ Print(s:"\c[m7]The admin has banned the \c[c8]Shambler\c[m7] from play.");
		ConsoleCommand("spectate"); } 
		break;
    }
}