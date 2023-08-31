// Nicolas Nouhi 
#include "CSquare.h"
#include "CPlayer.h"

CSquare::~CSquare()
{
	/*cout << "invoked" << endl;*/
}
CSquare::CSquare()
{
}

CSquare::CSquare(string name)
{
	mName = name;

}

void CSquare::Display()
{
	cout << mName << endl;
}





