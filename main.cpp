//Elie Climan - 260686400
//might segmentation fault every once in a while - if it does, restart the game, it doesn't happen often.
#include "functions.cpp" 
void clearBoard(char board[]);
void greetAndInstruct();
void displayBoard(char board[27]);
bool checkWinner(char board[27]);
bool ActualWin(char board[27], char letterX, char letterO);
void computerMove(char board[]);
void updateBoard(char board[], int cellNbre);
bool checkIfLegal(int cellNbre, char board[27]);
void GetUserMove(char board[]);
void getCompFirstMoves(char board[], bool x);
void runGame();

int main()
{
    greetAndInstruct();
    char userInput;
    cin >> userInput;
    cout<<"\n" << endl; 
    while(userInput != 'n' && userInput!='y'){
        cout<<"Please enter only 'n' for NO or 'y' for YES" <<endl; 
        cin>>userInput;
    }

    if (userInput =='n'){
        cout<< "game exited"<<endl; 
        exit(0);
        }else if(userInput=='y'){
            //displayBoard(Theboard);
            runGame(); 
        }
}