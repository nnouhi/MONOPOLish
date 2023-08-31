// Nicolas Nouhi 
#pragma once
#include <iostream>
#include "CSquare.h"
#include "CPlayer.h"
#include "CFileReader.h"
#include <crtdbg.h>


typedef vector<shared_ptr<CSquare>> SquareVector;
typedef vector<shared_ptr<CPlayer>> PlayerVector;
class CManager
{
private:
	
	int mSeed;
	SquareVector vBoard;
	PlayerVector vPlayers;
	const int BOARD_SIZE;
	const int NUM_OF_ROUNDS;
	bool mPlayerIsBankrupt;

	void SetUp();
	void ClearGame();
	void DeclareWinner();
	void UpdatePlayersPosition(shared_ptr<CPlayer>& Player, int BoardPos);
	void PlayRound(shared_ptr<CPlayer>& CurrentPlayer);
	
	
public:
	CManager();
	void Play();
	int Random();


};

