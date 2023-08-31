// Nicolas Nouhi 
#include "CSquare.h"
#include "CPlayer.h"
#include "CGoToJailSquare.h"


CGoToJailSquare::CGoToJailSquare(string Name, int JailSquarePos) : CSquare(Name), mJAIL_FEE(50)
{
	mJailSquarePos = JailSquarePos;
}

void CGoToJailSquare::Action(shared_ptr<CPlayer>& Player)
{
	// Send player to jail and apply fee
	Player->SetBoardPos(mJailSquarePos);
	if (Player->GetBalance() - mJAIL_FEE >= 0)
	{
		Player->SetBalance(-mJAIL_FEE);

		cout << Player->GetName() << " goes to Jail" << endl;
		cout << Player->GetName() << " pays $" << mJAIL_FEE << endl;
	}
	else
	{
		cout << Player->GetName() << " cannot afford to pay $" << mJAIL_FEE << " and goes to Jail" << endl;
		Player->SetIsJailed(true);
	}
	
}


