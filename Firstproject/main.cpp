#include <iostream>
#include <ctime>
using namespace std;

void PrintIntroduction(int Difficulty)
{
    
    cout << "\n\nYou are a secret agent trying to deactivate a level " << Difficulty;
    cout << " Bomb...\nYou need to enter the correct code to to save lives...\n\n";
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);
    const int CodeA = rand() % Difficulty + 1;
    const int CodeB = rand() % Difficulty + 1;
    const int CodeC = rand() % Difficulty + 1;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    cout << "+ There are Three numbers in the code";
    cout << "\n+ The code adds up to: " << CodeSum;
    cout << "\n+ The multiplication of the numbers is : " << CodeProduct << endl;

    int GuessA, GuessB, GuessC;
    cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    //Check if the player's input is Correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        cout << "Your code was correct. The bomb is now deactivated...CONGRATULATIONS";
        return true;
    }
    else
    {
        cout << "Your code was wrong...The Bomb exploded ***";
        return false;
    }
}


int main()
{
    srand(time(NULL));
    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        cin.clear();//clears any errors
        cin.ignore();//discards any buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
    }
    cout << "\n\n****CONGRATULATIONS YOU SAVED THE LIVES****";
    return 0;
}