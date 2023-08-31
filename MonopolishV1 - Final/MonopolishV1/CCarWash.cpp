// Nicolas Nouhi 
#include "CSquare.h"
#include "CCarWash.h"
#include "CPlayer.h"

CCarWash::CCarWash(string Name):CSquare(Name), mCAR_WASH_FEE(10) {}

void CCarWash::Action(shared_ptr<CPlayer>& Player)
{
	if (Player->GetBalance() - mCAR_WASH_FEE >= 0)
	{
		Player->SetBalance(-mCAR_WASH_FEE);
		cout << Player->GetName() << " pays $" << mCAR_WASH_FEE << " for a car wash" << endl;
	}
	else
	{
		cout << Player->GetName()<< "cannot pay $" << mCAR_WASH_FEE << " for a car wash and goes to Jail" << endl;
		Player->SetIsJailed(true);
	}
	
}
