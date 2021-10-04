#include <iostream>
using namespace std;
/**
/ ConnectFourBoard class declaration
/
/ Coder: Dillon van Rensburg
/ Date: 04/12/2020
**/
const int win = 4;
const int rows = 6;
const int columns =7;

class ConnectFour{

	private:

		char board[rows][columns];
		int count[columns];

	public:
		ConnectFour();
		~ConnectFour();
		void restart();
		bool dropMove( int col, char player);
		bool checkWin( char player);
		void printBoard();
};
