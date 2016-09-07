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

class Game {
public:
  void play();
  void boardSize();
  void makeBoard();
  void printBoard();

private:
  /* using _ prefix to easily ideantify private */
  int _numRows;
  int _numCols;

  //int board[][];
  typedef int *BoardPtr;
  BoardPtr *brd;
};

class Board {
};

void Game::boardSize() {
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

void Game::makeBoard() {

  cout << "Making board " << _numRows << "x" << _numCols << endl;
  brd = new BoardPtr[_numCols];
  {
    for( int i = 0; i < _numCols; ++i ) {
      // Second dimension
      brd[i] = new int[_numRows];
    }
  }
};


void Game::printBoard() {

  int *a;

  for (int row = 0; row <= _numRows; row++) {
    for (int col = 0; col <= _numCols; col++)
    { int *a[row][col]; }
  }

  for (int col = 0; col < _numCols; col++) {
    cout << setw(5) << col + 1;
  }
  cout << endl ;

  for (int row = 0; row < _numRows; row++) {
    cout << row + 1 << " ";

    for (int col = 0; col < _numCols; col++) {
      cout << setw(3) << *a;
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


#endif /* CEPHALOPOD_H_ */
