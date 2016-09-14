/*
 * cephalopod.h
 *
 *  Created on: 31Aug.,2016
 *      Author: rache_000
 */

#ifndef CEPHALOPOD_H_
#define CEPHALOPOD_H_

using namespace std;

//const int maxSize = 5; //not needed due to dynamic array

class Board {
public:
  Board();
  void printBoard();
  void placeDie();
  bool isFull();
  void randomPlayer();
  void UDLR();

protected:
  /* using _ prefix to easily ideantify private */
  int _numRows;
  int _numCols;

  typedef int *BoardPtr;
  BoardPtr *brd;
};

Board::Board() {
  int bsize;
//add verification while loop later
  cout << "Select board size: \n 1. 3x3 \n 2. 3x5 \n 3. 5x5 \n";
  cin >> bsize;

  if (bsize ==1) {
    _numRows = 3;
    _numCols = 3;
  } else
    if (bsize ==2) {
      _numRows = 3;
      _numCols = 5;
    } else {
      _numRows = 5;
      _numCols = 5;
    }
  cout << _numRows << "x" << _numCols << endl;

  cout << "Making board " << _numRows << "x" << _numCols << endl;
  brd = new BoardPtr[_numCols];
  {
    for( int i = 0; i < _numCols; ++i ) {
      // Second dimension
      brd[i] = new int[_numRows];
    }
  }
  for (int row = 0; row < _numRows; row++) {
    for (int col = 0; col < _numCols; col++)
    { brd[row][col]=0; }
  }
};

void Board::printBoard() {
  for (int col = 0; col < _numCols; col++) {
    cout << setw(5) << col + 1;
  }
  cout << endl ;

  for (int row = 0; row < _numRows; row++) {
    cout << row + 1 << " ";

    for (int col = 0; col < _numCols; col++) {
      cout << setw(3) << brd[row][col];
      if (col != 3) {
        cout << " |";
      } else
        if (col == _numCols * 3) {
          cout << endl;
        }
    }

    cout << endl;

    if (_numCols > 4) {
      cout << "  ____|____|____|____|____" << endl
           <<  "      |    |    |    |    " << endl;
    } else {
      if (_numCols != 2) {
        cout << "  ____|____|____" << endl
             <<      "      |    |    " << endl;
      }
    }
  }
  cout << endl;
};

bool Board::isFull() {
  for (int i=0; i < _numRows; i++) {
    for (int j=0; j < _numCols; j++)
      if (brd[i][j] == 0) {
        return false ;
      }
  }
  return true;
};
void Board::humanMove(){

};
void Board::placeDie() {
  int col;
  int row;

  cout << "Where would you like to place your die?" << endl;
  do {
    cout << "Choose a col: ";
    cin >> col;
  } while (col < 1 || col > _numCols); //while loop to validate input
  col = col - 1;

  do {
    cout << "Choose a row: ";
    cin >> row;
  } while (row < 1 || row > _numRows); //while loop to validate input
  row = row - 1;

// check move
  while (brd[row][col] != 0) { //while loop to validate input
    cout << "That move is invalid" << endl;
    do {
      cout << "Choose a col: ";
      cin >> col;
    } while (col < 1 || col > _numCols); //while loop to validate input
    col = col - 1;

    do {
      cout << "Choose a row: ";
      cin >> row;
    } while (row < 1 || row > _numRows);
    row = row - 1;
  }
  brd[row][col] = 1; //places a 1 on the board};
};

void Board::randomPlayer() {
  int col;
  int row;
  /* initialize random seed: */
  srand (time(NULL));

  do {
    row = rand() % _numRows;
    col = rand() % _numCols;
  } while (brd[row][col] != 0);  //checks if tile is taken or not **make own function if time**
  brd[row][col] = -1; //places a 1 on the board
};

void Board::UDLR(){
  int udlr[4] = brd[row]-1[col], brd[row]+1[col], brd[row][col]-1, brd[row][col]+1;
};

#endif /* CEPHALOPOD_H_ */
