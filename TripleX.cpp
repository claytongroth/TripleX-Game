#include <iostream>
#include <ctime>

void PrintIntro(int LevelDifficulty)
{
    std::cout << "\n\nThis is the true test, level: " << LevelDifficulty;
    std::cout << "\nYou need to enter the correct codes to continue!\n\n";
}
bool PlayGame(int LevelDifficulty)
{
    PrintIntro(LevelDifficulty);

    const int CodeA = rand() % LevelDifficulty + LevelDifficulty;
    const int CodeB = rand() % LevelDifficulty + LevelDifficulty;
    const int CodeC = rand() % LevelDifficulty + LevelDifficulty;

    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;

    std::cout << std::endl;
    std::cout << "There are three numbers in the code...\n";
    std::cout << "The codes all add up to: \n";
    std::cout << "The codes all multiply to: " << CodeProduct << std::endl;

    int GuessA, GuessB, GuessC;
    std::cout << ">>Attempt to guess. Type a _Space_ between each number " << std::endl;
    // >> extraction operator/.....
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if ((GuessSum == CodeSum) && (GuessProduct == CodeProduct)){
        if (LevelDifficulty == 5){
            std::cout << "\n++++++++++++++++++\nYou beat the game!\n++++++++++++++++++";
        } else if (LevelDifficulty < 5){
            std::cout << "You win!\n Moving on to level: " << LevelDifficulty + 1;
        }

        return true;
    }else{
        std::cout << "Try again!\n****************************************\n You made it to level: " << LevelDifficulty;
        return false;
    }
    
}

int main() 
{
    srand(time(NULL)); //seed rand

    int LevelDifficulty = 1;
    int const MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty) { // loop till all levels are complete
    
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // clears any errors
        std::cin.ignore(); // discards the buffer
        if (bLevelComplete ){
            ++LevelDifficulty;
        }
        
    }
    return 0; // exit program
}
