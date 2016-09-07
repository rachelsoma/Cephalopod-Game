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
  int bsize;
  int numRows;
  int numCols;
  //int board[][];
  typedef int* BoardPtr;

};

class Board {
};

/*
void Game::boardSize() {
  int bsizeIn;
//add verification while loop later
  cout << "Select board size: \n 1. 3x3 \n 2. 3x5 \n 3. 5x5 \n";
  cin >> bsizeIn;

  bsize = bsizeIn;

  if (bsize ==1) {
    int numRows = 3;
    int numCols = 3;
  } else
    if (bsize ==2) {
      int numRows = 3;
      int numCols = 5;
    } else {
      int numRows = 5;
      int numCols = 5;
    }


  cout << numRows << "x" << numCols << endl;

};*/

void Game::makeBoard() {

  cout << "Making board " << numRows << "x" << numCols << endl;

  BoardPtr *brd = new BoardPtr[numRows];


  //char board[numRows][numCols];
  for (int i = 0; i < numRows; i++) {
     brd[i][0] = i +1;
    brd[i]=new int[numCols];
  }
}


void Game::printBoard() {

  int *a;

  for (int row = 0; row <= numRows; row++) {
    for (int col = 0; col <= numCols; col++)
    { int *a[row][col]; }
  }

  for (int col = 0; col < numCols; col++) {
    cout << setw(5) << col + 1;
  }
  cout << endl ;

  for (int row = 0; row < numRows; row++) {
    cout << row + 1 << " ";

    for (int col = 0; col < numCols; col++) {
      cout << setw(3) << *a;
      if (col != 3) {
        cout << " |";
      } else
        if (col == numCols * 3) {
          cout << endl;
        }
    }

    cout << endl;

    if (numCols > 4) {
      cout << "  ____|____|____|____|____" << endl
           <<  "      |    |    |    |    " << endl;
    } else {
      if (numCols != 2) {
        cout << "  ____|____|____" << endl
             <<      "      |    |    " << endl;
      }
    }
  }
  cout << endl;
};


#endif /* CEPHALOPOD_H_ */
