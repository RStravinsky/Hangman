#ifndef LOADFILE
#define LOADFILE
#include <fstream>
#include <iostream>

using namespace std;

unsigned int const MAX_WORDS_IN_FILE = 255;
unsigned int Count;
extern vector<string> Words;

bool LoadFile()
{
    Count = 0;
    ifstream FILE;
    FILE.open("/home/rafal/Dokumenty/QT_Workspace/Projekty/Hangman/words.txt");
    if(!FILE.is_open()){
        cout<<"ERROR - Could not open dictionary file..."<<endl;
        return false;
    }

    //Temporary string
    string temp;

    while(FILE >> temp)
    {
     // Get the next word from FILE
     Words.push_back( temp );
     Count++;
     // If we surpass the max exit and tell the user
     if(Count > MAX_WORDS_IN_FILE)
     {
      cout<<endl<<"ERROR - Too many words in the file, stopping with "
       <<MAX_WORDS_IN_FILE<<" Words."<<endl;
      FILE.close();
      return false;
     }
    }

    //Close input file
    FILE.close();
    return true;
}

#endif // LOADFILE

