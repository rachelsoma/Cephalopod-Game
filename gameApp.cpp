//Main program

#include <iostream>
#include<iomanip>

#include "cephalopod.h"

using namespace std;



int main() {
  Game a;
  int * b;
	//this is the pointer int, when functions expect an int I’ve passed
	//it’s value with “*b”, where they expect a pointer I’ve passed “b”.

  int numRows, numCols, bsizeIn,board;
//choose size of board from a list
  a.boardSize(numRows,numCols,bsizeIn);

//make board using size selected
  a.makeBoard(numRows,numCols,b);
  a.printBoard(numRows,numCols,*b);
//human move
  a.placeDie(numRows,numCols,*b);

  a.printBoard(numRows,numCols,*b);

  return 0;
};
