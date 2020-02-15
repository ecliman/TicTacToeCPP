#include <string>
#include <iostream>
#include <stdio.h>
#include <iostream>
#include <cstdlib>

using namespace std;

char Theboard[27] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
                     ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
                     ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

const int winners[34][3] = {{1, 2, 3}, {10,11,12}, {19,20,21}, {1, 10, 19}, {2, 11, 20}, {3, 12, 21}, {4, 5, 6}, {13, 14, 15}, {22, 23, 24}, {4, 13, 22}, {5, 14, 23}, {6, 15, 24}, {7, 8, 9}, {16, 17, 18}, {25, 26, 27}, {7, 16, 25}, {8, 17, 26}, {9, 18, 27}, {1, 4, 7}, {2, 5, 8}, {10, 13, 16}, {11, 14, 17}, {12, 15, 18}, {19, 22, 25}, {20, 23, 26}, {21, 24, 27}, {1, 5, 9}, {3, 5, 7}, {10, 14, 18}, {12, 14, 16}, {19, 23, 27}, {21, 23, 25}, {1, 14, 27}, {21, 14, 7}};
const int rows = sizeof(winners) / sizeof(winners[0]);
const int cols = sizeof(winners[0]) / sizeof(winners[0][0]);
int cellNbre;
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
bool isValidComputer(int cellNbre, char board[27]);
void runGame();
int main(); 





void runGame(){
    
    cout<<"\n\n" <<endl;
            cout<<"please enter a move: "<<endl;
            cin >> cellNbre;
            if(!cin) { cin.clear(); cin.ignore(80,'\n');}
                checkIfLegal(cellNbre, Theboard);
                cout<<"\n" << endl;
                //displayBoard(Theboard);
            

            if(checkWinner(Theboard) == true){
                clearBoard(Theboard);
                cout <<"\n\n" << endl; 
                main();
            }else{
                //GetUserMove(Theboard);
                runGame();
            }
}
        
    

//greeting method
void greetAndInstruct()
{
    string board[27] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10",
                        "11", "12", "13", "14", "15", "16", "17", "18", "19", "20",
                        "21", "22", "23", "24", "25", "26", "27"};
    cout << "Hello and welcome to the Tic-Tac-Toe challenge: Player against Computer." << endl;
    cout << "The board is numbered from 1 to 27 as per the following:" << endl;

    cout << "\n\nCurrent Board: \n" << endl; 
    cout << board[0] << " | " << board[1] << " | " << board[2];
    cout << "\t \t";
    cout << board[9] << " | " << board[10] << " | " << board[11];
    cout << "\t \t";
    cout << board[18] << " | " << board[19] << " | " << board[20] << "\n";
    cout << "__________"<< "\t \t"<< "__________"<< "\t \t " << "__________"<< "\n";
    cout << board[3] << " | " << board[4] << " | " << board[5] << "\t \t"  << board[12] << " | " << board[13] << " | " << board[14] << "\t \t" << board[21] << " | " << board[22] << " | " << board[23] << "\n";
    cout << "__________" << "\t \t"<< "__________"<< "\t \t" << "__________" << "\n";
    cout << board[6] << " | " << board[7] << " | " << board[8] << "\t \t" << board[15] << " | " << board[16] << " | " << board[17] << "\t \t" << board[24] << " | " << board[25] << " | " << board[26] << "\n";
    cout << "__________" << "\t \t" << "__________"<< "\t \t"<< "__________" << "\n";

    cout << endl;
    cout << "Player starts first. Simply input the number of the cell you want to occupy. Player’s move is marked with X. Computer’s move is marked with O." << endl;
    cout << "Start?(y/n):" << endl;
}
//Displaying the board method
void displayBoard(char board[27])
{
    cout <<"\n" <<endl;
    cout << board[0] << " | " << board[1] << " | " << board[2];
    cout << "\t \t";
    cout << board[9] << " | " << board[10] << " | " << board[11];
    cout << "\t \t";
    cout << board[18] << " | " << board[19] << " | " << board[20] << "\n";
    cout << "__________"<< "\t \t"<< "__________"<< "\t \t " << "__________"<< "\n";
    cout << board[3] << " | " << board[4] << " | " << board[5] << "\t \t"  << board[12] << " | " << board[13] << " | " << board[14] << "\t \t" << board[21] << " | " << board[22] << " | " << board[23] << "\n";
    cout << "__________" << "\t \t"<< "__________"<< "\t \t" << "__________" << "\n";
    cout << board[6] << " | " << board[7] << " | " << board[8] << "\t \t" << board[15] << " | " << board[16] << " | " << board[17] << "\t \t" << board[24] << " | " << board[25] << " | " << board[26] << "\n";
    cout << "__________" << "\t \t" << "__________"<< "\t \t"<< "__________" << "\n";
    cout<<"\n \n" <<endl;
}


//checkWinner method
bool checkWinner(char board[27])
{
    //char letter;
    int GameOver = ActualWin(board, 'x','o'); //overloaded checkWinner
    if(ActualWin(board, 'x','o') == false){
        return false;  
    }
    return true; 

}


bool checkIfLegal(int cellNbre, char board[27]){ //check if a mark can be placed

        if(board[cellNbre-1] == 'x' || board[cellNbre-1] == 'o' || cellNbre <= 0 || cellNbre >27){
            cout<<"space already taken or invalid move, please try another move: " << endl; 
            cin >> cellNbre; 
            if(!cin) { cin.clear(); cin.ignore(80,'\n');}
            checkIfLegal(cellNbre, board);
            }else{
                //cout << "token placed in pos: " << board[cellNbre]<< endl;
                board[cellNbre-1] = 'x';
                computerMove(board); //let the computer play if the move is allowed, computerMove() calls getUser which continues the loop
                displayBoard(board);
                
            }
            return true; 
       
    }



void computerMove(char board[])
{
    bool isFirstMove = false;
    int arr[3];

       if (isFirstMove == false){
        getCompFirstMoves(board,isFirstMove); //random generate for first move
}
    
    for (int i = 0; i < rows; i++) // loop through winners
    {
        for (int j = 0; j < cols; j++)
        {
            arr[j] = winners[i][j];
        }
        int x = arr[0];
        int y = arr[1];
        int z = arr[2];
        if (board[x-1] == board[y-1]) 
        { //find all available winning moves or blocks aka best move possible
            if (board[x-1] == 'x'){
                if (isValidComputer(z-1, board) == true){
                    board[z-1] = 'o';
                    displayBoard(board); 
                }
            }
            else if (board[x-1] == 'o'){
                if (isValidComputer(z-1, board) == true){
                    displayBoard(board);
                }
            }
        }
        else if (board[x-1] == board[z-1]){
            if (board[x-1] == 'x'){
                if (isValidComputer(y-1, board) == true){
                    board[y-1] = 'o';
                    displayBoard(board);
                }
            }
            else if (board[x-1] == 'o'){
                if (isValidComputer(y-1, board) == true){
                    board[y-1] = 'o';
                    displayBoard(board);
                }
            }
        }
        else if (board[y-1] == board[z-1]){
            if (board[y-1] == 'x'){
                if (isValidComputer(x-1, board) == true){
                    board[x-2] = 'o';
                    displayBoard(board);
                    
                }
            }
            else if (board[y-1] == 'o'){
                if (isValidComputer(x-1, board) == true){
                    board[x-1] = 'o';
                    displayBoard(board);
                }
            }
        }
    }
    isFirstMove = true; 
    
}
//******************************************//
//              HELPER METHODS              //
//*****************************************//
//User's turn
void GetUserMove(char board[])
{
    cout << "please enter a move" << endl; 
    int userMove;
    cin >> userMove;
    if(!cin) { cin.clear(); cin.ignore(80,'\n');}
    checkIfLegal(userMove, board); 
}
//check if the computer's move is valid
bool isValidComputer(int cellNbre, char board[27]){
    if ((cellNbre < 0 || cellNbre > 27) ||
        (board[cellNbre] == 'o' || board[cellNbre] == 'x')){
        return false;
    }
    //board[cellNbre] = 'o';
    return true;
    
}

bool ActualWin(char board[27], char letterX, char letterO) //not permitted to overload checkWinner, so made a helper
{
    int index[3];
    //winners loop to find if a winning combination is present on the board
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            index[j] = winners[i][j];
        }
        int x = index[0];
        int y = index[1];
        int z = index[2];
        
        if (board[x-1] == board[y-1] && board[y-1] == board[z-1]){ //if the value in any of the cellls = x, user wins
            if (board[x-1] == letterX){ 
                cout<<"User Wins" <<endl;
                cout<<"\n\n" <<endl;
                clearBoard(board);
                main();
                return true;
            }
            if(board[x-1] == letterO){
                cout<<"Computer Wins" <<endl; //if the value in any of the cellls = o, comp wins
                cout<<"\n\n" <<endl;
                clearBoard(board);
                return true; 
                //else neither wins, return false
            }
        }
    }
    return false; 
    
}



void getCompFirstMoves(char board[], bool isFirstMove){ //generate a random first move,  update the ifFirstMove boolean
     srand((unsigned)time(0));                          // so that this only executes (random move) once.
        int cellNbre = (rand() % 27) + 1;
        cellNbre--;

        if(isValidComputer(cellNbre, Theboard) == false)
        {
            cellNbre = (rand() % 27);
            //cellNbre--;
            getCompFirstMoves(board,isFirstMove);
        }
            if(isValidComputer(cellNbre, Theboard)==true){
                board[cellNbre] = 'o';
                isFirstMove = true; 
    }
}



void clearBoard(char board[]){ //reset the board
     memset(board, ' ', 27);
     main();
}