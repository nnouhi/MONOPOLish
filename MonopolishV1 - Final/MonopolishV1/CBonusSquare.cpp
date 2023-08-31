// Nicolas Nouhi 
#include "CBonusSquare.h"
#include "CManager.h"
#include "CPlayer.h"
CBonusSquare::CBonusSquare(string Name):CSquare(Name){}

void CBonusSquare::Action(shared_ptr<CPlayer>& Player)
{
	// Roll dice twitch since landed on bonus square
	CManager GameInstance;
	int roll = GameInstance.Random() - 1;
	
	cout << mBONUSES_ARR[roll] << " Gain $" << mGAINS_ARR[roll]<<"."<<endl;
	Player->SetBalance(mGAINS_ARR[roll]);
}
