// Nicolas Nouhi 
#pragma once
#include "CSquare.h"
class CPlayer;

class CBonusSquare : public CSquare
{
private:
	const string mBONUSES_ARR[6] = { 
									"Find some money.",
									"Win a coding competition.",
									"Receive a donation.",
									"Win the lottery.",
									"It's your name day.",
									"It's your birthday.",
								   };
	const int mGAINS_ARR[6] = {20, 50, 100, 150, 200, 300};
public:
	CBonusSquare(string Name);
	void Action(shared_ptr<CPlayer>& Player) override;
};

