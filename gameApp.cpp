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

  //**TO DO** add a while loop that checks if any array values are 0, if not, game ends
do {
  a.placeDie(); //a human move

  a.printBoard();

} while (playOn = true);


  return 0;
};
