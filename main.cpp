#include <iostream>
#include "ConnectFourBoard.h"
using namespace std;
/**
/ This is a two player game that allows you to drop tokens into a 6x7 grid
/ the object of the game is to get four in a row(vertical, horizontal or
/ diagonally.
/
/ Coder: Dillon van Rensburg
/ Date: 04/12/2020
**/


int main()
{
	int col;
	int turn =0;
	int full =0;
	int play =0;
	int a;

	ConnectFour c4;
	while(play ==0){
		c4.restart();
		cout<< "\nLETS PLAY CONNECT 4"<<endl<<endl;
		c4.printBoard();
		cout<< "Player 1 : r \nPlayer 2 : b"<< endl;
		while(full!=42){
			if (turn == 0){
				cout<<"Player 1 Turn.You are using (r).\nPlease enter a column number(0-6):";
				do{
					cin>> col;
				}
				while(!c4.dropMove(col,'r'));
					
				
				if(c4.checkWin('r')){
					cout<<endl;
					cout<< "~~~~~~PLAYER 1 WINS!!~~~~~~\n";
					c4.printBoard();
					play=1;
					break;
				}
				turn=1;
			}
			else{
				cout<<"Player 2 Turn.You are using (b).\nPlease enter a column number(0-6):";
				do{
					cin>> col;
				}
				while(!c4.dropMove(col,'b'));
				if(c4.checkWin('b')){
					cout<<endl;
					cout<< "~~~~~~PLAYER 2 WINS!!~~~~~~\n";
					c4.printBoard();
					play = 1;
					break;
				}
				turn=0;
			}
			full+=1;
			c4.printBoard();
			if (full ==42){
				play= 1;
				cout<<"DRAW" << endl;
			}
		
		
		}
		cout<<" DO you wish to play again? enter 1(yes) or 2(no):"<<endl;
		cin>> a;
		
		while(a != 1 && a != 2){
			cout<<" Invaild input, enter 1 to play agin or 2 to exit:";
			cin>>a;
		}
		if ( a== 1)
			play =0;
		else if (a==2)
			exit;
				
	}
	return 0;
}

