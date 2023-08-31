// Nicolas Nouhi 
#pragma once
#include <iostream>
using namespace std;
class CPlayer;
class CGoToJailSquare : public CSquare
{
private:
	int mJailSquarePos;
	int mJAIL_FEE;

public:
	CGoToJailSquare(string Name, int JailSquarePos);
	void Action(shared_ptr<CPlayer>& Player) override;
	
};

