// Nicolas Nouhi 
#include "CManager.h"


CManager::CManager():BOARD_SIZE(26), NUM_OF_ROUNDS(50)
{
    mPlayerIsBankrupt = false;
}

void CManager::Play()
{
    
    
    
    //Setup game
    SetUp();
    
    //seed the generator with the same value each time then it will always produce the same sequence of numbers
    srand(mSeed);

    for (int i = 0; i < NUM_OF_ROUNDS; i++)
    {
        //cin.get(); // NOTE: Used for outputting every iteration; remove later
        
        if (!mPlayerIsBankrupt)
        {
            cout << "\n---ROUND " << i + 1 << "---\n";
            PlayRound(vPlayers[0]);
            cout << endl;
            PlayRound(vPlayers[1]);
        }   
        else
        {
            break;
        }
    }

    
    // Test..owned props
    /*cout<<vPlayers[1]->GetName() <<" has \n\n\n\n\n";
    vPlayers[1]->DisplayProperties();
    cout << vPlayers[0]->GetName() << " has \n\n\n\n\n";
    vPlayers[0]->DisplayProperties();*/
    
    DeclareWinner();
   
}

int CManager::Random()
{
    return static_cast<int>(static_cast<double> (rand()) / (RAND_MAX + 1) * 6.0f + 1);
}

void CManager::SetUp()
{
    CFileReader mFileReader;
    mSeed = mFileReader.ReadFile();
    vBoard = mFileReader.ReadFile("monopoly.txt", BOARD_SIZE);

    vPlayers.push_back(make_shared<CPlayer>("Dog", 1500, 0));
    vPlayers.push_back(make_shared<CPlayer>("Car", 1500, 0));

    cout << "Welcome to Monopol - ish" << endl; // Welcoming message

}

void CManager::ClearGame()
{
    /*for (int i = 0; i < 26; i++)
    {
        delete vBoard.at(i);
    }
    vBoard.clear();

    for (int i = 0; i < 2; i++)
    {
        delete vPlayers.at(i);
    }
    vPlayers.clear();*/
}

void CManager::DeclareWinner()
{
    cout << "\n";
    cout << "\n---Game Over--- \n" << endl;
    cout << vPlayers[0]->GetName() << " has $" << vPlayers[0]->GetBalance() << endl;
    cout << vPlayers[1]->GetName() << " has $" << vPlayers[1]->GetBalance() << endl;
    cout << "\n";
    cout << "---WINNER---" << endl;

    (vPlayers[0]->GetBalance() > vPlayers[1]->GetBalance()) ? cout << vPlayers[0]->GetName() << " wins" : cout << vPlayers[1]->GetName() << " wins";

    ClearGame();

}

void CManager::PlayRound(shared_ptr<CPlayer>& CurrentPlayer)
{

    // Players local variables
    int oldPosition = 0, newPosition = 0;
    int Dice = 0;

    Dice = Random();
    cout << CurrentPlayer->GetName() << " rolls " << Dice << endl;

    // If Player is jailed
    if(CurrentPlayer->GetIsJailed())
    {
        if (CurrentPlayer->GetBoardPos() != 6) // Move player to jail if he is not
        {
            CurrentPlayer->SetBoardPos(6);
        }
       
        if (Dice % 2 == 0)
        {
            cout << CurrentPlayer->GetName() << " receives a presidential pardon and is free to go" << endl;
            CurrentPlayer->SetIsJailed(false);
        }  
    }
  
    // Obtain the current burrent position of the player 
    oldPosition = CurrentPlayer->GetBoardPos();
    // Calculate the new board position of the player
    newPosition = (oldPosition + Dice) % BOARD_SIZE;
    // Update players board position
    UpdatePlayersPosition(CurrentPlayer, newPosition);


    cout << CurrentPlayer->GetName() << " lands on " << vBoard[newPosition]->GetName() << endl;

    // Player lands or passes go; give update balace +200
    if (newPosition != 0 && oldPosition > newPosition)
    {
        // Execute appropriate action
        vBoard[0]->Action(CurrentPlayer);
    }

    // Execute appropriate action
    vBoard[newPosition]->Action(CurrentPlayer);

    if (CurrentPlayer->GetIsBankrupt())
        mPlayerIsBankrupt=true;
    else if (CurrentPlayer->GetMortgagedState())
        CurrentPlayer->TryRepayMortgagedProperties();

    // Output players balance
    cout << CurrentPlayer->GetName() << " has $" << CurrentPlayer->GetBalance() << endl;
}

void CManager::UpdatePlayersPosition(shared_ptr<CPlayer>& Player, int BoardPos)
{
    Player->SetBoardPos(BoardPos);
}
