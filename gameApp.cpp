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


  /*
  because both sets of moves are inside the loop,
  if human makes last available move computer still tried to have a go.
  IF statement is not working :/
    */
  while (!a.isFull())  {//loop continues if board has any spaces with 0 in them
// tests if board is full.
    if (!a.isFull()) {
      a.placeDie(); //a human move
      a.printBoard();
    }

    if (!a.isFull()) {
      cout << "Computer's move" <<endl;
      a.randomPlayer(); //random computer move
      a.printBoard();
    }

  }

  cout << "Game over" <<endl;
  a.winner();

  return 0;
};
