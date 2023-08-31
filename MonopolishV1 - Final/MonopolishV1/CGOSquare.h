// Nicolas Nouhi 
#pragma once
#include <iostream>
using namespace std;
class CPlayer;
class CGOSquare : public CSquare
{
private:
	const int mGO_AMOUNT;

public:
	CGOSquare(string Name);
	void Action(shared_ptr<CPlayer>& Player) override;
};

