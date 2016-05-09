#include "hangman.h"

extern vector<string> Words;

Hangman::Hangman()
{

}

void Hangman::RunGame()
{
    /* create random slogan */
    srand(time(NULL));
    int randomIndex = rand() % Words.size();

    Slogan = Words [randomIndex];
    SizeOfSlogan = Slogan.size();

    /* array to hold find letters */
    vector<int>IdxArr;
    IdxArr.resize(SizeOfSlogan);
    IdxArr.clear();

    unsigned int i=0;
    unsigned short int PlayState=0;
    unsigned int find = 0;

    while(PlayState != 5)
    {
        /* Display covered Slogan */
        for(i=0 ; i< Slogan.size() ; ++i)
        {
            if(!IdxArr[i]) cout << "_ ";
            else cout << Slogan[i];
        }

        cout  << endl;
        cout  << "Write a letter: ";
        cin >> Letter;
        Letter = tolower(Letter);

        /* find Letter in Slogan */
        bool found = false;
        for(i = 0 ; i < Slogan.size() ; ++i)
        {
            if(Slogan[i]==Letter)
            {
                found = true;
                IdxArr[i] = i+1; // becouse of 0 value for 0 idx
            }
        }

        /* if Letter found */
        if(!found)
        {
            cout << "Sorry, bad guess!" << endl;
            DrawHangman(++PlayState);
        }
        else
        {
            cout << "Good guess!" << endl;
            DrawHangman(PlayState);
        }

        /* check if Slogan is correct */
        for(i = 0 ; i < Slogan.size() ; ++i)
        {
            if(IdxArr[i] != 0) find++;
            if(find==Slogan.size())
            {
                cout << "YOU WIN!" << endl;
                return;
            }
        }
        find = 0;
        cout << "******************************" << endl;
    }
    cout << endl;
}

void Hangman::DrawHangman(int _state)
{
    if(_state==5)
    {
     cout<<endl<<endl
      <<"   +----+     "<<endl
      <<"   |    |     "<<endl
      <<"   |    O     "<<endl
      <<"   |   /|\\   "<<endl
      <<"   |   / \\   "<<endl
      <<"   |Your Dead "<<endl
      <<"  ============"<<endl
      <<" The word was: " << Slogan << endl;
    }
    else if(_state==4)
    {
     cout<<endl<<endl
      <<"   +----+  "<<endl
      <<"   |    |  "<<endl
      <<"   |    O  "<<endl
      <<"   |   /|\\ "<<endl
      <<"   |     \\ "<<endl
      <<"   |       "<<endl
      <<"  ============"<<endl<<endl;
    }
    else if(_state==3)
    {
     cout<<endl<<endl
      <<"   +----+  "<<endl
      <<"   |    |  "<<endl
      <<"   |    O  "<<endl
      <<"   |   /|\\ "<<endl
      <<"   |       "<<endl
      <<"   |       "<<endl
      <<"  ============="<<endl<<endl;
    }
    else if(_state==2)
    {
     cout<<endl<<endl
      <<"   +----+  "<<endl
      <<"   |    |  "<<endl
      <<"   |    O  "<<endl
      <<"   |   /|  "<<endl
      <<"   |       "<<endl
      <<"   |       "<<endl
      <<"  ============="<<endl<<endl;
    }
    else if(_state==1)
    {
     cout<<endl<<endl
      <<"   +----+  "<<endl
      <<"   |    |  "<<endl
      <<"   |    O  "<<endl
      <<"   |    |  "<<endl
      <<"   |       "<<endl
      <<"   |       "<<endl
      <<"  ============="<<endl<<endl;
    }
    else if(_state==0)
    {
     cout<<endl<<endl
      <<"   +----+  "<<endl
      <<"   |    |  "<<endl
      <<"   |       "<<endl
      <<"   |       "<<endl
      <<"   |       "<<endl
      <<"   |       "<<endl
      <<"  ============="<<endl<<endl;
    }
}

