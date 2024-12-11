#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>

using namespace std;

const int SIZE = 3;
void printBoard(int board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == 0) {
                cout << "_ ";
            } else {
                cout << board[i][j] << " ";
            }
        }
		cout << endl; 
    }
}
bool isWinner(int board[SIZE][SIZE]) {
    int count = 1;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] != count && !(i == SIZE - 1 && j == SIZE - 1)) {
                return false;
            }
            count++;
        }
    }
    return true;
}
void swapValues(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
void shuffleBoard(int board[SIZE][SIZE]) {
    srand(static_cast<unsigned int>(time(NULL)));
    for (int i = SIZE - 1; i > 0; --i) {
        for (int j = SIZE - 1; j > 0; --j) {
            int randomRow = rand() % (i + 1);
            int randomCol = rand() % (j + 1);
            swapValues(board[i][j], board[randomRow][randomCol]);
        }
    }
}

int main() {
    int puzzleBoard[SIZE][SIZE];
    int count = 1;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            puzzleBoard[i][j] = count++;
        }
    }
    puzzleBoard[SIZE - 1][SIZE - 1] = 0; 
    shuffleBoard(puzzleBoard);
    cout << "Welcome to the Puzzle Game!\n";
  
    printBoard(puzzleBoard);
	while (!isWinner(puzzleBoard)) {
		cout << "Press 0 to quit: ";
        char move = _getch(); 
        int row, col;
        bool found = false;
        for (row = 0; row < SIZE; ++row) {
            for (col = 0; col < SIZE; ++col) {
                if (puzzleBoard[row][col] == 0) {
                    found = true;
                    break;
                }
            }
            if (found) {
                break;
            }
        }

        switch (move) {
            case 'W': case 'w': 
                if (row > 0) {
                    swapValues(puzzleBoard[row][col], puzzleBoard[row - 1][col]);
                }
                break;
            case 'S': case 's': 
                if (row < SIZE - 1) {
                    swapValues(puzzleBoard[row][col], puzzleBoard[row + 1][col]);
                }
                break;
            case 'A': case 'a': 
                if (col > 0) {
                    swapValues(puzzleBoard[row][col], puzzleBoard[row][col - 1]);
                }
                break;
            case 'D': case 'd': 
                if (col < SIZE - 1) {
                    swapValues(puzzleBoard[row][col], puzzleBoard[row][col + 1]);
                }
                break;   
            case '0': 
                cout << "Quitting the game. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid move. Please use W, A, S, D to move or 0 to quit.\n";
        }
        
        system("cls"); 
        printBoard(puzzleBoard);
    }
   	cout << "!!! You won.\n";
   	cout << "Press 0 to quit: ";
	cin.ignore();	
    return 0;
}

