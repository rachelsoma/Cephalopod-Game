//Main program

#include <iostream>
#include <iomanip>

#include "cephalopod.h"
//#include "Player.h"
using namespace std;

int main() {
  bool playOn = true;
  Board a;

 // a.boardSize(); //User selects board size

  //a.makeBoard(); //make board using size selected

  a.printBoard(); //display current board with moves
  //human move

  //**TO DO** a while loop that checks if playOn status is TRUE if not, game ends
do {

  a.placeDie(); //a human move

  a.printBoard();


 ; // tests if board is full
} while (!a.isFull());

cout << "Game over" <<endl;

  return 0;
};
