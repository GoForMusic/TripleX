#include <iostream>
#include <ctime>
#include <windows.h> // for sleep()

void PrintIntroduction(int LevelDifficulty)
{
    std::cout << "You are a secret agent breaking into a level " << LevelDifficulty <<
                 " secure server room..."<<std::endl;
    std::cout <<"Enter the correct code to continue..."<<std::endl;
}

bool PlayerGame(int LevelDifficulty)
{
    PrintIntroduction(LevelDifficulty);

    const int CodeA =rand() % LevelDifficulty + LevelDifficulty;
    const int CodeB =rand() % LevelDifficulty + LevelDifficulty;
    const int CodeC =rand() % LevelDifficulty + LevelDifficulty;

    const int CodeSum  = CodeA + CodeB +CodeC;
    const int CodeProd = CodeA*CodeB*CodeC;


    //Print
    std::cout<<"+ There are 3 numbers in the code"<<std::endl;
    std::cout<<"+ The codes add-up to: "<<CodeSum<<std::endl;
    std::cout<<"+ The codes multiply to give: "<<CodeProd<< std::endl;

    // Store player data
    int GuessA, GuessB, GuessC;
    std::cin>>GuessA >> GuessB >> GuessC;


    int GuessSum = GuessA+GuessB+GuessC;
    int GuessProd = GuessA*GuessB*GuessC;

    //Check
    if (GuessSum==CodeSum && GuessProd==CodeProd){
        std::cout<<"ACCESS GRANTED!"<<std::endl;
        std::cout<<"====================="<<std::endl;
        return true;
    }else{
        std::cout<<"ERROR: TRY AGAIN!"<<std::endl;
        std::cout<<"====================="<<std::endl;
        return false;
    }
}

int main() {
    srand(time(NULL));// create new random sequence based on time of day

    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;

    while (LevelDifficulty<=MaxDifficulty){
        bool bLevelComplete=PlayerGame(LevelDifficulty);

        std::cin.clear(); // clears any errors
        std::cin.ignore(); // discard the buffer

        if(bLevelComplete){
            ++LevelDifficulty;
        }
    }
    std::cout<<"**** GREAT WORK AGENT! You got all the files! Now get out of there! ****"<<std::endl;
    return 0;
}
