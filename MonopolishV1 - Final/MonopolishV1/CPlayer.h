// Nicolas Nouhi 
#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class CProperty;
typedef vector<CProperty*> CPropertyVector;
class CPlayer
{
private:
	string mName;
	int mBalance;
	int mBoardPos;
	bool mIsBankrupt;
	bool mIsJailed; //remove later only for part b
	bool mMortgagedState;
	CPropertyVector vOwnedProperties;


public:
	CPlayer(string Name, int Balance, int BoardPos);

	// Getters:
	string GetName() const { return mName; }
	int GetBalance() const { return mBalance; }
	int GetBoardPos() const { return mBoardPos; }
	int GetIsJailed() const { return mIsJailed; }
	bool GetIsBankrupt() const { return mIsBankrupt; }
	CPropertyVector GetOwnedProperties() { return vOwnedProperties; }
	bool GetMortgagedState() const{ return mMortgagedState; }

	// Setters:
	void SetName(string Name) { mName = Name; }
	void SetBalance(int Balance) { mBalance += Balance; }
	void SetBoardPos(int BoardPos) { mBoardPos = BoardPos; }
	void SetIsJailed(bool IsJailed) { mIsJailed = IsJailed; }
	void SetIsBankrupt();
	void SetMortgagedState(bool Mortgage) { mMortgagedState = Mortgage; }
	
	
	void SendPlayerToJail();
	void DisplayProperties();
	void BuyProperty(CProperty* Property);
	bool HandleMortgage(int Rent);
	void TryRepayMortgagedProperties();
	

};

