#include <iostream>
#include <string>
using namespace std;

    class TicTacToe  {
    private:
        char board[3][3];
    public:
        TicTacToe() = default;
        ~TicTacToe() = default;
        TicTacToe(const TicTacToe&) = delete;
        TicTacToe(TicTacToe&& other) = delete;
        TicTacToe& operator=(const TicTacToe& other) = delete;
        TicTacToe& operator=(TicTacToe&& other) = delete;



        void SetBoard()
        {
            int n = 1;
            int i = 0;
            int j = 0;

            for (i = 0; i < 3; i++)
            {
                for (j = 0; j < 3; j++)
                {
                    board[i][j] = '0' + n; //Cast the n to a character
                    n++;
                }
            }
        }  

        void PrintBoard()
        {
            int i = 0;
            int j = 0;
          
            for (i = 0; i < 3; i++)
            {
                for (j = 0; j < 3; j++)
                {
                    if (j < 2)
                    {
                        cout << board[i][j] << "  |  ";
                    }
                    else
                    {
                        cout << board[i][j] << endl;
                    }
                }
            }
        }

        void PlayerTurn(char num, char Player)
        {
            int i = 0;
            int j = 0;

            bool WrongMove = true; //If true player has made a wrong move
            for (i = 0; i < 3; i++)
            {
                for (j = 0; j < 3; j++)
                { //Mark square with X or O if WrongMove is not true
                    if (board[i][j] == num)
                    {
                        board[i][j] = Player; 
                        WrongMove = false;    
                    }
                }
            }
            if (WrongMove == true) { cout << "You can only set in free places!!!!!\n"; }
        } //End Player Move


        bool CheckResult(char Player, bool GameOver)
        {
            system("CLS");
            for (int i = 0; i < 3; i++) // rows
            {
                if (board[i][0] == board[i][1] && board[i][1] ==
                    board[i][2]) GameOver = true;
            }
            for (int i = 0; i < 3; i++) //column
            {
                if (board[0][i] == board[1][i] && board[1][i] ==
                    board[2][i]) GameOver = true;
            }
            // Diagonals
            if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
            {
                GameOver = true;
            }
            if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
            {
                GameOver = true;
            }
            if (GameOver == true)
            {
                cout << "Player " << Player << " wins!\n\n";
                cout << "-----------------------" << endl;
                cout << "|   CONGRATULATIONS " << Player << " |\n";
                cout << "-----------------------" << endl << endl;
            }
           
            return GameOver;
        } //End Check


        bool CheckDraw(bool GameOver)
        {
            int n = 1;
            int i = 0;
            int j = 0;
            int counter = 0;

            for (i = 0; i < 3; i++)
            {
                for (j = 0; j < 3; j++)
                {
                    //Check to see if the board is full
                    if (board[i][j] == '0' + n)
                    {
                        counter++;
                    }
                    n++;
                }
            }
            if (counter < 1)
            {
                cout << "No one won :(, keep playing :)!\n\n";
                GameOver = true;
            }
            return GameOver;
        }
};


int main()
{
    bool done = false, GameOver = false;
    char Player = 'O', num;

    cout << "-=WELCOME TO=-\n";
    cout << "-=Tic-Tac-Toe=-\n";
    cout << "-------------" << endl;

    TicTacToe myGame;
    myGame.SetBoard();
    do
    {
        if (Player == 'X')
        {
            Player = 'O';
        }
        else
        {
            Player = 'X';
        }
        myGame.PrintBoard();
        cout << "\nPlayer \"" << Player << "\", it's your turn: ";
        cin >> num;
        cout << "\n";

        myGame.PlayerTurn(num, Player);
        GameOver = myGame.CheckResult(Player, GameOver);
        GameOver = myGame.CheckDraw(GameOver);
        //if game over, starting over
        if (GameOver == true)
        {
            myGame.SetBoard();
            GameOver = false;
        }
    } while (!done);

    system("pause");
    return 0;
}