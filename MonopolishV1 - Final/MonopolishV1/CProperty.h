// Nicolas Nouhi 
#pragma once
#include <iostream>
#include "CSquare.h"
#include "CPlayer.h"
using namespace std;



class CProperty : public CSquare
{
private:
	int mCost;
	int mRent;
	int mColourGroup;
	bool mIsOwned;
	bool mIsMortgaged;
	shared_ptr<CPlayer> mOwner;


public:

	// Getters
	int GetRent() const { return mRent; }
	int GetCost() const { return mCost; }
	bool GetIsOwned() const { return mIsOwned; }
	bool GetIsMortgaded() const{ return mIsMortgaged; }
	int GetColourGroup() const { return mColourGroup; }
	shared_ptr<CPlayer> GetOwner() const { return mOwner; }

	// Setters
	void SetOwner(shared_ptr<CPlayer>& Player) { mOwner = Player; }
	void SetIsOwned(bool isOwned) { mIsOwned = isOwned; }
	void SetIsMortgaded(bool Mortgaded) { mIsMortgaged = Mortgaded; }


	CProperty(string Name, int Cost, int Rent, int ColourGroup);
	void Display() override;
	virtual void Action(shared_ptr<CPlayer>& Player) override;
	string GetName() const override { return mName; } // possibly it work

	
};

