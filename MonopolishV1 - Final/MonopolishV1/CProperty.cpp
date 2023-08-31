// Nicolas Nouhi 
#include "CProperty.h"


CProperty::CProperty(string Name, int Cost, int Rent, int ColourGroup) : CSquare(Name)
{
	mCost = Cost;
	mRent = Rent;
	mColourGroup = ColourGroup;
	mIsOwned = false;
	mIsMortgaged = false;
	mOwner = NULL;
}

void CProperty::Display()
{
	if (mIsMortgaged)
	{
		cout << GetName() << " is mortgaged " << mCost << " " << mRent << " " << mColourGroup << endl;
		return;
	}
	cout << GetName()<< " " << mCost << " " << mRent << " " << mColourGroup << endl;
}

void CProperty::Action(shared_ptr<CPlayer>& Player)
{
	if (mIsMortgaged && mOwner!=Player)
	{
		cout << mName << " is mortgaged and does not collect any rent" << endl;
		return;
	}

	// not owned; buy
	if (mIsOwned == false)
	{
		if (Player->GetBalance() - mCost > 0)
		{

			Player->SetBalance(-mCost);
			mIsOwned = true;
			mOwner = Player;
			cout << Player->GetName() << " buys " << mName <<" for $" <<mCost<< endl;
			Player->BuyProperty(this);
		}	
	}
	else if (Player != mOwner) // if property is declared as mortgaged don't collect rent
	{
		int newRent = mRent;
		int countProperties = 0;
		CPropertyVector  vTempPlayersProperties = mOwner->GetOwnedProperties();

		// Calculate new rent
		for (auto& it : vTempPlayersProperties)
		{
			if (it->mColourGroup == this->mColourGroup)
			{
				countProperties++;
			}
		}

		if (countProperties == 3 && (this->mColourGroup == 3 || this->mColourGroup == 6))// 3 & 6 colour groups have 3 properties
		{
			newRent *= 2;
		}
		else if (countProperties == 2 && (this->mColourGroup != 3 && this->mColourGroup != 6))
		{
			newRent *= 2;
		}

		// Player affords to pay rent
		if (Player->GetBalance() - newRent >= 0)
		{
			Player->SetBalance(-newRent);
			mOwner->SetBalance(newRent);
			cout << Player->GetName() << " pays $" << newRent <<endl;
		}
		else if(Player->HandleMortgage(newRent)) // player must mortgage properties 
		{
			Player->SetBalance(-newRent);
			mOwner->SetBalance(newRent);
			cout << Player->GetName() << " pays $" << newRent << endl;
		}
		else // player mortgaged all properties and still can't afford to pay rent
		{
			Player->SetIsBankrupt();
		}
	}
}
