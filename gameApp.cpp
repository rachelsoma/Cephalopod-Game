//Main program

#include <iostream>
#include <iomanip>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include "cephalopod.h"
//#include "Player.h"
using namespace std;

int main() {

  Board a;
  a.printBoard(); //display current board with moves

  //**TO DO** a while loop that checks if playOn status is TRUE if not, game ends
do {

  a.placeDie(); //a human move
  a.isFull();
  //a.printBoard();

  a.randomPlayer();
  a.isFull();
  a.printBoard();

} while (!a.isFull()); // tests if board is full

cout << "Game over" <<endl;

  return 0;
};
