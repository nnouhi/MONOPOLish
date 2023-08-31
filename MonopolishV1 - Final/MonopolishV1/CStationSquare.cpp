// Nicolas Nouhi 
#include "CStationSquare.h"


CStationSquare::CStationSquare(string Name):CProperty(Name, 200, 10,-1){}

void CStationSquare::Action(shared_ptr<CPlayer>& Player)
{
	string propertyName = GetName();
	int propertyRent = GetRent(), propertyCost = GetCost();
	shared_ptr<CPlayer> Owner = GetOwner();
	bool isOwned = GetIsOwned();

	if (GetIsMortgaded() && Owner!=Player)
	{
		cout << propertyName << " is mortgaged and does not collect any rent" << endl;
		return;
	}
	// not owned; buy
	if (!isOwned)
	{
		if (Player->GetBalance() - propertyCost >= 0)
		{
			Player->SetBalance(-GetCost());
			SetIsOwned(true);
			SetOwner(Player);
			cout << Player->GetName() << " buys " << propertyName << " for $" << propertyCost << endl;
			Player->BuyProperty(this);
		}
		
	}
	else if (Player != Owner)
	{
		if (Player->GetBalance() - propertyRent >= 0)
		{
			Player->SetBalance(-propertyRent);
			Owner->SetBalance(propertyRent);
			cout << Player->GetName() << " pays $" << propertyRent << " for ticket" << endl;
		}
		else if (Player->HandleMortgage(propertyRent)) // player must mortgage properties 
		{
			Player->SetBalance(-propertyRent);
			Owner->SetBalance(propertyRent);
			cout << Player->GetName() << " pays $" << propertyRent << endl;
		}
		else // player mortgaged all properties and still can't afford to pay rent
		{
			Player->SetIsBankrupt();
		}
	}
}
