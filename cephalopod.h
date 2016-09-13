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
  void play();
  void boardSize();
  void makeBoard();
  void printBoard();
  void initBoard();
  void placeDie();

protected:
  /* using _ prefix to easily ideantify private */
  int _numRows;
  int _numCols;

  //int board[][];
  typedef int *BoardPtr;
  BoardPtr *brd;
};


void Board::boardSize() {
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
};

void Board::makeBoard() {
  cout << "Making board " << _numRows << "x" << _numCols << endl;
  brd = new BoardPtr[_numCols];
  {
    for( int i = 0; i < _numCols; ++i )
    {
      // Second dimension
      brd[i] = new int[_numRows];
    }
  }
  brd = {0}; // fills board with value 0
};

void Board::printBoard() {

  for (int row = 0; row <= _numRows; row++) {
    for (int col = 0; col <= _numCols; col++)
    { int brd[row][col]; }
  }

  for (int col = 0; col < _numCols; col++) {
    cout << setw(5) << col + 1;
  }
  cout << endl ;

  for (int row = 0; row < _numRows; row++) {
    cout << row + 1 << " ";

    for (int col = 0; col < _numCols; col++) {
      cout << setw(3) << brd;
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

void Board::placeDie() {
int col;
int row;

  cout << "Where would you like to place your die?";
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

// check seat
  if (brd[row][col] != 0) { //checks if seat is taken or not **make own function if time**
    brd[row][col] = 1; //places a 1 on the board
  } else {
    cout << "That move is invalid" << endl;
  }
};

#endif /* CEPHALOPOD_H_ */
