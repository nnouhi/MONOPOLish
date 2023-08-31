// Nicolas Nouhi 
#pragma once
#include <iostream>

using namespace std;
class CPlayer;

class CSquare
{
protected:
	string mName;
public:
	virtual ~CSquare() = 0; // Call default destructor of subclass
	CSquare();//default constructor
	CSquare(string name);//normal square constructor
	virtual void Display();
	virtual void Action(shared_ptr<CPlayer>& Player) = 0; // CSquare becomes an abstract class

	// Getters:
	virtual string GetName() const { return mName; }
	

	


};

