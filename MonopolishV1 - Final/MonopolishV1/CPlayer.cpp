// Nicolas Nouhi 
#include "CSquare.h"
#include "CPlayer.h"
#include "CProperty.h"


CPlayer::CPlayer(string Name, int Balance, int BoardPos)
{
	mName = Name;
	mBalance = Balance;
	mBoardPos = BoardPos;
	mIsJailed = false;
	mIsBankrupt = false;
	mMortgagedState = false;
}

void CPlayer::BuyProperty(CProperty* Property)
{
	// After buying a property sort vector by property cost
	vOwnedProperties.push_back(Property);
	sort(vOwnedProperties.begin(), vOwnedProperties.end(), [](const CProperty* lhs, const CProperty* rhs) {
		return lhs->GetCost() < rhs->GetCost();
		});
}

bool CPlayer::HandleMortgage(int Rent)
{
	mMortgagedState = true;
	cout << mName << " cannot afford to pay $" << Rent << " and is mortgaging properties:" << endl;
	int p = 0;
	while (mBalance < Rent && p < vOwnedProperties.size())
	{
		// Mortgage properties until funds rise above required rent
		if (!vOwnedProperties.at(p)->GetIsMortgaded())
		{
			vOwnedProperties.at(p)->SetIsMortgaded(true);
			mBalance += vOwnedProperties.at(p)->GetCost();
			cout << vOwnedProperties.at(p)->GetName() << endl;
		}
		p++;
	}

	return  mBalance < Rent ? false : true;

}

void CPlayer::TryRepayMortgagedProperties()
{
	if (vOwnedProperties.size() > 0) // find first mortgaged property
	{
		CProperty* firstMortgage = nullptr;
		for (auto& property : vOwnedProperties)
		{
			if (property->GetIsMortgaded())
			{
				firstMortgage = property;
				break;
			}
		}
		// try repay mortgaged property
		if (firstMortgage != nullptr && mBalance - firstMortgage->GetCost() >= 0)
		{
			mBalance -= firstMortgage->GetCost();
			firstMortgage->SetIsMortgaded(false);
			cout << mName << " has repayed the mortgage of " << firstMortgage->GetName() << endl;

		}
	}
}


void CPlayer::SetIsBankrupt()
{
	mBalance = 0;
	mIsBankrupt = true;
	cout << mName << " is bankrupt" << endl;
}

void CPlayer::SendPlayerToJail()
{
	mBoardPos = 6;
}

void CPlayer::DisplayProperties()
{
	// only for debug
	for (auto& it : vOwnedProperties)
	{
		it->Display();
	}	
}
