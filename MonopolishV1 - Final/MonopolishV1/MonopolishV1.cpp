
#include <iostream>
#include "CManager.h"
#include <crtdbg.h>
#include <memory>

using namespace std;



int main()
{
    _crtBreakAlloc = -1;

    {
        unique_ptr<CManager> GameInstance = make_unique<CManager>();
        GameInstance->Play();
    }
    
    _CrtDumpMemoryLeaks();
    
}

