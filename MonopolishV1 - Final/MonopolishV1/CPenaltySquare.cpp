// Nicolas Nouhi 
#include "CPenaltySquare.h"
#include "CManager.h"

CPenaltySquare::CPenaltySquare(string Name) :CSquare(Name) {}

void CPenaltySquare::Action(shared_ptr<CPlayer>& Player)
{
	// Roll dice twitch since landed on bonus square
	CManager GameInstance;
	int roll = GameInstance.Random() - 1;

	cout << mPENALTIES_ARR[roll] << " Lose $" << mFEES_ARR[roll] << "." << endl;
	if (Player->GetBalance() - mFEES_ARR[roll] >= 0)
	{
		Player->SetBalance(-mFEES_ARR[roll]);
	}
	else 
	{
		cout << Player->GetName() << " cannot pay $" << mFEES_ARR[roll] << " penalty and goes to Jail" << endl;
		Player->SetIsJailed(true);
	}
}