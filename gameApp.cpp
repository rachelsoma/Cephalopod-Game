//Main program

#include <iostream>
#include <iomanip>

#include "cephalopod.h"
#include "Player.h"
using namespace std;

int main() {
  /*Player* players[2];
  players1 = new HumanPlayer::Player();
  players2 = new AiPlayer::Player();*/

  HumanPlayer me;
  AiPlayer you;

  Board a;

  a.boardSize(); //User selects board size

  a.makeBoard(); //make board using size selected

  a.printBoard(); //display current board with moves
//human move
  me.placeDie();
  //a.printBoard(numRows,numCols,b);

  return 0;
};
