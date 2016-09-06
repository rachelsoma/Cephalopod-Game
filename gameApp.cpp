//Main program

#include <iostream>
#include<iomanip>

#include "cephalopod.h"

using namespace std;



int main() {
  Game a;

  int numRows, numCols, bsizeIn,board;
//choose size of board from a list
  a.boardSize(numRows,numCols,bsizeIn);

//make board using size selected
  a.makeBoard(*a,numRows&,numCols&);
  a.printBoard(numRows,numCols,a);
//human move
  a.placeDie(numRows,numCols,a);

  a.printBoard(numRows,numCols,a);

  return 0;
};
