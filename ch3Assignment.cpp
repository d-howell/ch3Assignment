//Dalton Howell
//IN200: Intro to c++
//Chapter 3 Assignment

#include <iostream> //Including all things needed for strings, rand(), and sleep()
#include <string> 
#include <ctype.h> //used so i can change the the input string to uppercase
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;

int main()
{
    const int MAX_GAMES = 10; //Having a max of ten games
    string games[MAX_GAMES] = {"Kingdom Hearts", "The Legend of Zelda", "Pokemon", "Professor Layton"}; //Starting with these four games
    string playerName;
    srand(time(0)); //seed rng
    
    cout << "Hello, may I please have your name?\n>> ";
    getline(cin,playerName);//Using getline just in case they decide to use a space
    this_thread::sleep_for(chrono::milliseconds(1000));

    cout << "Nice to meet you, " << playerName << "!\n\n";
    this_thread::sleep_for(chrono::milliseconds(1000));//Sleeping so the program doesn't come out too fast

    cout << "Displaying a random game from our list:\n";
    
    int maxSearch, foundGame;
    for(maxSearch = 0; !(games[maxSearch].empty()); ++maxSearch) {} //Finds the index of the first empty slot
    foundGame = (rand() % maxSearch);
    cout << foundGame + 1 << ". " << games[foundGame] << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    
    

    cout << "\nSearching for \"The Legend of Zelda\".\n";
    this_thread::sleep_for(chrono::milliseconds(2000));

    for(int i = 0; i < MAX_GAMES; ++i ) //looping through the string
    {
        if (games[i] == "The Legend of Zelda") //On the first empty string, break the loop as to not waste time.
        {
            cout << games[i] << " is at position " << i + 1 << " on this list!\n";
            this_thread::sleep_for(chrono::milliseconds(1500));
            break;
        }
        this_thread::sleep_for(chrono::milliseconds(1000)); //make it sleep to feel like its searching
    }

    cout << "\nI'm going to list a few of my favorite games:\n\n";
    this_thread::sleep_for(chrono::milliseconds(2000));

    for(int i = 0; i < MAX_GAMES; ++i ) //looping through the string
    {
        if (games[i].empty()) //On the first empty string, break the loop as to not waste time.
        {
            break;
        }
        this_thread::sleep_for(chrono::milliseconds(1000));
        cout << i+1 << ". " << games[i] << endl; //display the game at the index of that array
    }

    cout << "\nPretty nice, huh?\n";
    this_thread::sleep_for(chrono::milliseconds(2000));


    
    string input; //new string for input
    bool quitGame = false, fullList = false; //setting bools to false by default to allow the loop to work
    cout << "If you'd like to add a game of your own, you can!\n";
    this_thread::sleep_for(chrono::milliseconds(1000));
    
    while ((!fullList) && (!quitGame)) //infinite loop to continue until the player quits
    {
        
        cout << "Either enter the name of your game, or enter 'quit' to exit!\n>> ";
        getline(cin,input);
        string readString = input;// This and the next line are used to see if the player wanted to quit easier
        for(int i = 0; i < input.size();++i) //Changes the string to all uppercase
        {
            readString[i] = toupper(readString[i]);
        }

        if(readString.find("QUIT") != string::npos) //If you can find quit anywhere in the string
        {
            quitGame = true;
            continue; //go back to the top of the loop, rendering it false and exiting
        }

        for(int i = 0; i < MAX_GAMES; ++i)
        {
            if(games[i].empty()) //Find the first empty slot
            {
                cout << "\nOkay, we'll add " << input << " in at slot " << i + 1 << "!\n"; //display which slot its gonna be put in
                games[i] = input; //add the input to that slot
                cout << i+1 << ". " << games[i] << endl;
                this_thread::sleep_for(chrono::milliseconds(1000));
                if (!games[MAX_GAMES-1].empty()) { //If the last slot is full, exit and flag the list as full
                    fullList = true;
                    break;
                } else {
                    cout << "You can add another game if you'd like.\n"; //If the last slot is empty, you can put in at least one more game
                    this_thread::sleep_for(chrono::milliseconds(1000));
                    break;
                }
                
            }
            
            
        } 


    }

    if(quitGame) //if you entered quit
    {
        cout << "Well, I hope you saw a few games you liked! And added a few of your own of course.\n";

    } else { //otherwise the list is full

        cout << "Oh my, it looks like our list is full now!\n";
        this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "I hope you added some of your favorites!\n";
    }

    this_thread::sleep_for(chrono::milliseconds(3000));

    cout << "\nLet's show the final list before we go: \n";

    for(int i = 0; i < MAX_GAMES; ++i ) //looping through the string
    {
        if (games[i].empty()) //On the first empty string, break the loop as to not waste time.
        {
            break;
        }
        this_thread::sleep_for(chrono::milliseconds(1000));
        cout << i+1 << ". " << games[i] << endl; //display the game at the index of that array
    }

    this_thread::sleep_for(chrono::milliseconds(3000));

    cout << "Goodbye, " << playerName << "!";

    this_thread::sleep_for(chrono::milliseconds(3000));
}