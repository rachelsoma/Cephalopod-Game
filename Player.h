#ifndef PLAYER_H
#define PLAYER_H


class Player: public Board {

};
//Human Player inherets from player
class HumanPlayer: public Player{
  public:
  void humanMove();
  void placeDie();
};
//AiPlayer inherets from Player
class AiPlayer: public Player {
public:
};
//Random player inherets from Player
class RandomPlayer: public Player {
public:
};


//This isn't going to work until I figure out pointers
void HumanPlayer::placeDie() {
int col;
int row;

  cout << "Where would you like to place your die?";
   do {
    cout << "Choose a col: ";
    cin >> col;
  } while (col < 1 || col > _numCols +1);
  col = col - 1;

  do {
    cout << "Choose a row: ";
    cin >> row;
  } while (row < 1 || row > _numRows);
  row = row - 1;



// check seat
  if (brd[col][row] != 0) { //checks if seat is taken or not **make own function**
    brd[col][row] = 1; //places a 1 on the board
  } else {
    cout << "That move is invalid" << endl;
  }
};


#endif // PLAYER_H
