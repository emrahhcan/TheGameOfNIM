#include <iostream>
#include <string>
#include <vector>   /* Vector */
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */
using namespace std;

// Global Variables - Dynamic Values
int numberOfMatchSticks;
int selectedRow;
string playerTurn;
string firstPlayer;
string secondPlayer;
bool yourTurn = false;
vector<int> matchSticksArr;

// Global Variables - Static Values
bool computer = false;
string line = "----------------------------------------------------\n";
string lineForSettings = "------------------------------------------------------------------\n";
string lineForPlayerInfo = "---------------------------------------\n";
string yourChoice = "Your choice = ";
string chooseMatchNumber = "Please choose the number of rows for matchsticks: ";
string gameBoardNotification = "The game board has being prepared with number of ";
string playerTurnNotification = " will start the game first\n";
string choosePlayer = "Who will start to play first? Please write exact name => ";

// Defining functions
void matchesForPlayers();
void initMatchSticks(int);
bool removeSticks(int, int);
void gameBoardTwoPlayer();

// Main method starts here
int main()
{
    // Settings
    int chooseSettings;
    string settings =
        "Play Against to Computer (1) | Play in Two Players (2) | Quit (3)";

    cout << endl;
    cout << settings << endl;
    cout << lineForSettings;
    cout << yourChoice;
    cin >> chooseSettings;
    cout << lineForSettings;

    // Decide whether user choose to play against computer or to play with another player. Otherwise, quit the game
    switch (chooseSettings)
    {
    case 1:
        cout << line;
        cout << "I could not complete it :/" << endl;
        cout << line;
        break;
    case 2:
        // Game Panel
        gameBoardTwoPlayer();
        break;
    default:
        cout << line;
        cout << "Loser! Game will terminate itself" << endl;
        cout << line;
        break;
    }

    return 0;
}
// Initialize matchsticks
void initMatchSticks(int row)
{
    for (int i = 0; i < row; i++)
    {
        matchSticksArr.push_back((2 * i) + 1);
    }
}

// Initializing rows for matchsticks
void matchesForPlayers()
{
    for (int i = 0; i < matchSticksArr.size(); i++)
    {
        for (int j = 0; j < matchSticksArr[i]; j++)
        {
            cout << "I";
        }
        cout << endl;
    }
}

// Let us remove sticks from the rows
bool removeSticks(int row, int stickCount)
{
    if (matchSticksArr[row] < stickCount)
    {
        cout << endl
             << line;
        cout << "You cannot get matchstick from another row" << endl;
        cout << line;
        return false;
    }
    matchSticksArr[row] -= stickCount;
    return true;
}

// Check that we remove sticks from same row or not
bool checkStatus()
{
    int sum = 0;

    for (int i = 0; i < matchSticksArr.size(); i++)
    {
        sum += matchSticksArr[i];
    }

    return sum == 1;
}

void gameBoardTwoPlayer()
{
    // Ask to player for number of match stick, and get input from player
    cout << endl;
    cout << chooseMatchNumber;
    cin >> numberOfMatchSticks;
    cout << line;

    // Player infos
    cout << "Please enter the first player's name: ";
    cin >> firstPlayer;
    cout << "Please enter the second player's name: ";
    cin >> secondPlayer;

    // Prepare initial game board
    cout << line << gameBoardNotification << numberOfMatchSticks << " row" << endl;
    cout << line;
    initMatchSticks(numberOfMatchSticks);

    cout << "Initial Game Board" << endl;
    cout << endl;
    matchesForPlayers();
    cout << endl;
    cout << line;

    while (true)
    {
        // Let us choose how many sticks we want to remove
        int grabMatches;

        // Every time loop will change the status of turn
        yourTurn = !yourTurn;

        // Decision of player turn
        playerTurn = yourTurn ? firstPlayer : secondPlayer;

        // Select row and number of sticks to remove 'em from selected row
        cout << line;
        cout << "Which row would u like to use " << playerTurn << "?" << endl;
        cout << yourChoice;
        cin >> selectedRow;

        cout << "How many matches would u like to get " << playerTurn << "?" << endl;
        cout << yourChoice;
        cin >> grabMatches;
        cout << line;

        bool result = removeSticks(selectedRow, grabMatches);

        // Change the turn of player
        if (!result)
        {
            yourTurn = !yourTurn;
        }

        // Finish the game if there is a loser
        if (checkStatus())
        {
            string loser = yourTurn ? secondPlayer : firstPlayer;
            cout << line;
            cout << "You lose the game " << loser << endl;
            cout << line;
            break;
        }

        // Display current game board
        cout << endl;
        cout << "Current Game Board" << endl;
        matchesForPlayers();
        cout << endl;
    }
}