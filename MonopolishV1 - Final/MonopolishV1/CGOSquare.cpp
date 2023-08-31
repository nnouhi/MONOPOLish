// Nicolas Nouhi 
#include "CPlayer.h"
#include "CSquare.h"
#include "CGOSquare.h"

CGOSquare::CGOSquare(string Name):CSquare(Name), mGO_AMOUNT(200) {}

void CGOSquare::Action(shared_ptr<CPlayer>& Player)
{
	Player->SetBalance(mGO_AMOUNT);
	cout << Player->GetName() << " passes GO and collects $" <<mGO_AMOUNT<< endl;
}
