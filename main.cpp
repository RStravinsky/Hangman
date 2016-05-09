#include <cstdlib>
#include <vector>
#include "loadfile.h"
#include "hangman.h"

using namespace std;

vector<string> Words;

void GameTitle()
{
    cout<< "Welconme to the game Hangman!" << endl;
    cout<< "developed by Rafal Strawinski" << endl;
    cout << endl;
    cout << "* You will be given up 7 attempts to find a letter." << endl;
    cout << "* you have a chance to solve the word after each letter attempt. " << endl;
    cout << endl;
    cout << endl;
}

int main(void)
{
    char Continue = 'Y';
    Hangman hangman;

    GameTitle();

    if(LoadFile())
    {
        while(Continue=='Y')
        {
            hangman.RunGame();
            cout << "Do you want play again (Y/N)?";
            cin >> Continue;
            Continue = toupper(Continue);
        }
        cout<< "Thanks for playing." << endl;
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}



