// Nicolas Nouhi 
#pragma once
#include <iostream>
class CPlayer;

using namespace std;
class CCarWash : public CSquare
{
private:
	int mCAR_WASH_FEE;

public:
	CCarWash(string Name);
	void Action(shared_ptr<CPlayer>& Player) override;
};

