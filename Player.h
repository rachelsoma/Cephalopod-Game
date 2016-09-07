#ifndef PLAYER_H
#define PLAYER_H


class Player {
  public:
};
//Human Player inherets from player
class HumanPlayer: public Player{
  public:
int numRows;
int numCols;
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
  int *a;
  int row;
  int col;
  cout << "Where would you like to place your die?";
  do {
    cout << "Choose a row: ";
    cin >> row;
  } while (row < 1 || row > numRows);
  row = row - 1;

  do {
    cout << "Choose a col: ";
    cin >> col;
  } while (col < 1 || col > numCols +1);
  col = col - 1;

// check seat
  if (*a != 0) { //checks if seat is taken or not **make own function**
    *a = 1;
  } else {
    cout << "That move is invalid" << endl;
  }
};


#endif // PLAYER_H
