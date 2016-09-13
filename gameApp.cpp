//Main program

#include <iostream>
#include <iomanip>

#include "cephalopod.h"
#include "Player.h"
using namespace std;

int main() {
  Board a;

  a.boardSize(); //User selects board size

  a.makeBoard(); //make board using size selected

  a.printBoard(); //display current board with moves
//human move
  a.placeDie(); //a human move

  a.printBoard();

  return 0;
};
