#include <iostream>
using namespace std;

char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

// Display board
void displayBoard()
{
    cout << "\n";
    cout << "     |     |     " << endl;
    cout << "  " << board[0][0] << "  |  "
         << board[0][1] << "  |  "
         << board[0][2] << endl;

    cout << "_____|_____|_____" << endl;

    cout << "     |     |     " << endl;
    cout << "  " << board[1][0] << "  |  "
         << board[1][1] << "  |  "
         << board[1][2] << endl;

    cout << "_____|_____|_____" << endl;

    cout << "     |     |     " << endl;
    cout << "  " << board[2][0] << "  |  "
         << board[2][1] << "  |  "
         << board[2][2] << endl;

    cout << "     |     |     " << endl;
}

// Check winning condition
bool checkWin(char player)
{
    // Rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == player &&
            board[i][1] == player &&
            board[i][2] == player)
        {
            return true;
        }
    }

    // Columns
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == player &&
            board[1][i] == player &&
            board[2][i] == player)
        {
            return true;
        }
    }

    // Main diagonal
    if (board[0][0] == player &&
        board[1][1] == player &&
        board[2][2] == player)
    {
        return true;
    }

    // Other diagonal
    if (board[0][2] == player &&
        board[1][1] == player &&
        board[2][0] == player)
    {
        return true;
    }

    return false;
}

// Check draw
bool checkDraw()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O')
            {
                return false;
            }
        }
    }

    return true;
}

// Place player's symbol
bool makeMove(int position, char player)
{
    if (position < 1 || position > 9)
    {
        return false;
    }

    int row = (position - 1) / 3;
    int col = (position - 1) % 3;

    // Check whether position is already occupied
    if (board[row][col] == 'X' || board[row][col] == 'O')
    {
        return false;
    }

    board[row][col] = player;

    return true;
}

int main()
{
    char currentPlayer = 'X';
    int position;

    cout << "====================================" << endl;
    cout << "        TIC-TAC-TOE GAME" << endl;
    cout << "====================================" << endl;

    cout << "\nPlayer 1 = X" << endl;
    cout << "Player 2 = O" << endl;

    while (true)
    {
        displayBoard();

        cout << "\nPlayer " << currentPlayer;
        cout << ", enter position (1-9): ";
        cin >> position;

        // Handle invalid non-number input
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Invalid input! Please enter a number from 1 to 9."
                 << endl;

            continue;
        }

        // Make move
        if (!makeMove(position, currentPlayer))
        {
            cout << "Invalid move! Position is already occupied or invalid."
                 << endl;

            continue;
        }

        // Check winner
        if (checkWin(currentPlayer))
        {
            displayBoard();

            cout << "\n====================================" << endl;
            cout << "Player " << currentPlayer << " WINS!" << endl;
            cout << "====================================" << endl;

            break;
        }

        // Check draw
        if (checkDraw())
        {
            displayBoard();

            cout << "\n====================================" << endl;
            cout << "             GAME DRAW!" << endl;
            cout << "====================================" << endl;

            break;
        }

        // Change player
        if (currentPlayer == 'X')
        {
            currentPlayer = 'O';
        }
        else
        {
            currentPlayer = 'X';
        }
    }

    return 0;
}