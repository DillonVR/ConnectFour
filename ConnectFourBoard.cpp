#include "ConnectFourBoard.h"
#include <iostream>
#include <string>

using namespace std;

/**
/ This is the class implemenation for Connect Four game.
/ Includes the following:
/		ConnectFour();
/		~ConnectFour();
/		void restart();
/		bool dropMove( int col, char player);
/		bool checkWin( char player);
/		void printBoard();
/
/ Coder: Dillon van Rensburg
/ Date: 04/12/2020
**/

//Constructor
ConnectFour::ConnectFour(){
	
	restart();
}
//Destructor
ConnectFour::~ConnectFour(){
	
}
// Initialize or restart the game
void ConnectFour::restart(){
	
	for(int c =0; c < columns+1;c++)
		for(int r = 0;r <rows+1;r++)
			board[c][r] = ' ';
	
	for( int c =0;c<columns;c++)
		count[c]=0;
	
}
//Player makes move
bool ConnectFour::dropMove( int col, char player){
	
	//invaild move
	if ((col<0)||(col >= columns)||(count[col]>=rows)){
		cout << "Invaild move, Please use columns 0-6:";
		return false;
	}
	//valid move
	else{
		int row = count[col];
		board[row][col] =player;
		count[col]++;
		return true;
	}
}

//check if player has won
bool ConnectFour::checkWin(char player){

	for(int c=0;c<columns;c++)
	for(int r=0;r<rows;r++)
	if(board[r][c] == player){
		//check row
		int count = 0;
		for( int d=0;d<win;d++)
			if((r+d <columns)&&(board[r+d][c]==player))
				count++;
		if(count==win)
			return true;;
		
		//check Column
		count = 0;
		for( int d=0;d<win;d++)
			if((c+d <columns)&&(board[r][c+d]==player))
				count++;
		if(count==win)
			return true;

		//check diagonal
		count = 0;
		for( int d=0;d<win;d++)
			if((r+d <rows)&&(c+d<columns)&&(board[r+d][c+d]==player))
				count++;
		if(count==win)
			return true;

		//check inverse diagonal
		count = 0;
		for( int d=0;d<win;d++)
			if((r-d <0)&&(c+d<columns)&&(board[r-d][c+d]==player))
				count++;
		if(count==win)
			return true;
	}
	return false;
}

void ConnectFour::printBoard(){
	
	cout<<endl;
	//draw column numbers
	cout<<"";
	for(int c = 0;c<columns;c++)
		cout<<"  "<<c<< " ";
	cout<<"\n\n";

	//print the Board
	for(int r=rows-1;r>=0;r--){
		
		//draw column lines
		cout<<"|";
		for(int c = 0;c<columns;c++)
			cout<<board[r][c]<< "  |";
		cout<<"\n";

		//draw dashed line
		cout<<"+";
		for(int c = 0;c<columns;c++)
			cout<< "---+";
		cout<<"\n";
	}

	
	

}

