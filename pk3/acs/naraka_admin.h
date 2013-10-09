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

script 895 (void) clientside // Allows Villains to be equal with the Heroes
{
    if (PlayerNumber() != ConsolePlayerNumber()) { terminate; }
    if (GetCVar("teamlms") == 1)
	{
		if (PlayerTeam() == 1)
		{
		    if (GetTeamProperty(1,TPROP_NumPlayers) >= 4)
		    {
			    if (GetTeamProperty(1,TPROP_NumPlayers) > GetTeamProperty(0,TPROP_NumPlayers))
			    { Print(s:"\cgVillains\cf have too many players!");
				ConsoleCommand("spectate"); }
		    }
		}
		if (GetTeamProperty(0,TPROP_NumPlayers) > 6)
		{
		    if (PlayerTeam() == 0)
		    {
			    if (GetTeamProperty(0,TPROP_NumPlayers) > (GetTeamProperty(1,TPROP_NumPlayers)*2))
			    { Print(s:"\chHeroes\cf have too many players!");
				ConsoleCommand("spectate"); }
		    }
		}
	}
	delay(1);
	terminate;
}

script 897 (void) clientside // Does not allow Villains to have equal numbers with Heroes
{
    if (PlayerNumber() != ConsolePlayerNumber()) { terminate; }
    if (GetCVar("teamlms") == 1)
	{
		if (PlayerTeam() == 1)
		{
		    if (GetTeamProperty(1,TPROP_NumPlayers) >= 4)
		    {
			    if (GetTeamProperty(1,TPROP_NumPlayers) >= GetTeamProperty(0,TPROP_NumPlayers))
			    { Print(s:"\cgVillains\cf have too many players!");
				ConsoleCommand("spectate"); }
		    }
		}
		if (GetTeamProperty(0,TPROP_NumPlayers) > 6)
		{
		    if (PlayerTeam() == 0)
		    {
			    if (GetTeamProperty(0,TPROP_NumPlayers) > (GetTeamProperty(1,TPROP_NumPlayers)*2))
			    { Print(s:"\chHeroes\cf have too many players!");
				ConsoleCommand("spectate"); }
		    }
		}
	}
	delay(1);
	terminate;
}