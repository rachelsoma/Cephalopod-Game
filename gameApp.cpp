//Main program

#include <iostream>
#include<iomanip>

#include "cephalopod.h"
#include "Player.h"
using namespace std;



int main() {
  Player* players[2];
  players[0] = new HumanPlayer::Player();
  players[1] = new AiPlayer::Player();
  Game a;
  int * b;
	//this is the pointer int, when functions expect an int I’ve passed
	//it’s value with “*b”, where they expect a pointer I’ve passed “b”.

  int numRows, numCols, bsizeIn,board;
//choose size of board from a list
  a.boardSize(numRows,numCols,bsizeIn);

//make board using size selected
  a.makeBoard(numRows,numCols,b);
  a.printBoard(numRows,numCols,b);
//human move
 // HumanPlayer.placeDie(numRows,numCols,*b);
  //a.printBoard(numRows,numCols,b);



  return 0;
};
