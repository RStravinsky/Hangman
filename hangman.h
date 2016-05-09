#ifndef HANGMAN_H
#define HANGMAN_H
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

class Hangman
{
private:
    void DrawHangman(int _state);
    string Slogan;
    string GuessSlogan;
    string DisplaySlogan;
    char Letter;
    unsigned int SizeOfSlogan;

public:
    Hangman();
    void RunGame();

};

#endif // HANGMAN_H
