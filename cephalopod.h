/*
 * cephalopod.h
 *
 *  Created on: 31Aug.,2016
 *      Author: rache_000
 */

#ifndef CEPHALOPOD_H_
#define CEPHALOPOD_H_

using namespace std;

class Board {
public:
  Board();
  void printBoard();
  void placeDie();
  bool isFull();
  void randomPlayer();
  void UDLR();
  void winner();

protected:
  /* using _ prefix to easily ideantify private */
  int _numRows;
  int _numCols;
  int col;
  int row;

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


/** \brief if there are ANY zeroes in the array function returns FALSE
 *
 * \param status 1 equals true, 0 equals false
 * \return boolean value true or false
 *
 */

bool Board::isFull() {
  int status = 1;
  for (int i=0; i < _numRows; i++) {
    for (int j=0; j < _numCols; j++)
      if (brd[i][j] == 0) {
        status = 0;
        break;
      }
  }
  if (status == 0) {
    return false;
  } else {
    return true;
  }
};

void Board::placeDie() {


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
 UDLR();
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

/** \brief Finds value of pips above, below, to the left and to the right of selected placement
 *
 * \param
 * \param
 * \return
 *
 */

void Board::UDLR() {
 // int u,d,l,r;

 /* want to create pointers to specific parts of the array
 so I can change the values without rewriting code*/
  int *u;
  *u = abs(&brd[row-1][col]); // I want u to pint to the value of brd[row-1][col]
  int *d ;
  *d = abs(&brd[row+1][col]); // same
  int *l;
  *l = abs(&brd[row][col-1]); //same
  int *r ;
  *r = abs(&brd[row][col+1]); //same

  if(row-1<0) {
    u = 0;
  }

  if (row+1>=_numRows) {
    d = 0;}

  if(col-1<0) {
    l = 0;}

  if (col>=_numCols) {
    r = 0;
  }

  int udlr[] = {u,d,l,r};
  int sum = 0;
  for (int i = 0; i < 4; i++)
  { sum = sum + udlr[i]; }

  if (sum == 0) {
    brd[row][col] = 1;//places a 1 on the board};
  } else {
    brd[row][col] = sum;
    *u=0; // want to change the value u points to to 0
    *d=0; // same
    *l=0; //same
    *r=0; //same
  } //places sum of surrounding pips on the board};
};

void Board::winner() {
  int player1=0;
  int player2=0;
  for (int i=0; i < _numRows; i++) {
    for (int j=0; j < _numCols; j++)
      if (brd[i][j] < 0) {
        player1++ ;
      } else {
      } player2++;
  }
  if (player1 > player2) {
    cout << "Player 1 wins" <<endl;
  } else {
    cout << "Player 2 wins" << endl;
  }
};
#endif /* CEPHALOPOD_H_ */
