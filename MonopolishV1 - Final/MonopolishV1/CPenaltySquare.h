// Nicolas Nouhi 
#pragma once
#include "CSquare.h"
class CPenaltySquare : public CSquare
{
private:
	const string mPENALTIES_ARR[6] = {
									"Buy a coffee.",
									"Pay your broadband bill.",
									"Donate to charity.",
									"Loose your wallet.",
									"Go for a romantic meal.",
									"Pay university fees.",
								   };
	const int mFEES_ARR[6] = { 20, 50, 100, 150, 200, 300 };
public:
	
	CPenaltySquare(string Name);
	void Action(shared_ptr<CPlayer>& Player) override;
};

