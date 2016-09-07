//Main program

#include <iostream>
#include <iomanip>

#include "cephalopod.h"
#include "Player.h"
using namespace std;

int main() {
//  Player* players[2];
// players[0] = new HumanPlayer::Player();
  //players[1] = new AiPlayer::Player();

  Game a;
  //int * b;
  //this is the pointer int, when functions expect an int I’ve passed
  //it’s value with “*b”, where they expect a pointer I’ve passed “b”.

  int numRows, numCols, bsize;
//choose size of board from a list

//add verification while loop later
  cout << "Select board size: \n 1. 3x3 \n 2. 3x5 \n 3. 5x5 \n";
  cin >> bsize;

  if (bsize==1) {
    numRows = 3;
    numCols = 3;
  }
  else if (bsize==2) {
    numRows = 3;
    numCols = 5;
  } else {
    numRows = 5;
    numCols = 5;
  }
  cout << numRows << "x" << numCols << endl;


//make board using size selected
  a.makeBoard(numRows,numCols);
  //a.printBoard();
//human move
// HumanPlayer.placeDie(numRows,numCols,*b);
  //a.printBoard(numRows,numCols,b);

  return 0;
};
