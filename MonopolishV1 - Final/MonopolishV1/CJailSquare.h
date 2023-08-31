// Nicolas Nouhi 
#pragma once
#include <iostream>
using namespace std;
class CPlayer;
class CJailSquare : public CSquare
{
public:
	CJailSquare(string Name);
	void Action(shared_ptr<CPlayer>& Player) override;
};

