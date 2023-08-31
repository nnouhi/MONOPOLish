// Nicolas Nouhi 
#include "CSquare.h"
#include "CPlayer.h"
#include "CJailSquare.h"

CJailSquare::CJailSquare(string Name):CSquare(Name){}

void CJailSquare::Action(shared_ptr<CPlayer>& Player)
{
	cout << Player->GetName() << " is just visiting"<<endl;
}
