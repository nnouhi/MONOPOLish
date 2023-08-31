// Nicolas Nouhi 
#pragma once
#include <iostream>
#include "CProperty.h"
#include "CPlayer.h"
using namespace std;
class CStationSquare : public CProperty
{
private:
	/*int mStationCost = 200;
	int mTicketCost = 10;*/
	
public:
	CStationSquare(string Name);
	void Action(shared_ptr<CPlayer>& Player) override;
};

