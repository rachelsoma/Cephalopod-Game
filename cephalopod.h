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
  void boardSize(int,int,int);
  void makeBoard(int*,int,int);
  void humanMove();
  void placeDie(int,int,int);
  void printBoard(int,int,int);

private:
  int bsize;
  int numRows;
  int numCols;
  //int board[][];
  typedef int* BoardPtr;

};

void Game::boardSize(int,int,int) {
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

};

void Game::makeBoard(int*,int,int) {
  int index;
  cout << "Making board " << numRows << "x" << numCols << endl;

  BoardPtr *a = new BoardPtr[numRows];


  //char board[numRows][numCols];
  for (int i = 0; i < numRows; i++) {
    // arr[i][0] = i +1;
    a[i]=new int[numCols];
    }
  }


void Game::printBoard(int,int,int) {

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

//This isn't going to work until I figure out pointers
void Game::placeDie(int,int,int) {
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


#endif /* CEPHALOPOD_H_ */
