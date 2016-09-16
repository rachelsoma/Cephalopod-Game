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
  void humanMove();
  void computerMove();
  void chooseMove();
  bool isFull();
  void randomPlayer();
  void UDLR(int,int,int);
  //void placeDie(int,int,int);
  void placeDie(int,int,int,int);
  void capture(int,int);
  void winner();

protected:
  /* using _ prefix to easily ideantify private */
  int _numRows;
  int _numCols;
  //int col;
  //int row;

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

void Board::humanMove(){
      chooseMove(); //a human move
//      placeDie(inRow,inCol);
      printBoard();
};

void Board::computerMove(){
      randomPlayer(); //random computer move
//      placeNegDie(inRow,inCol);
      printBoard();
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

void Board::chooseMove() {
  int row,col;

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
  UDLR(row,col, 1);
  //placeDie(row,col,sum,1);
  capture(row,col);
// brd[row][col] = 1;//places a 1 on the board};
};

void Board::randomPlayer() {
  int col,row;
  /* initialize random seed: */
  srand (time(NULL));

  do {
    row = rand() % _numRows;
    col = rand() % _numCols;
  } while (brd[row][col] != 0);  //checks if tile is taken or not **make own function if time**
UDLR(row, col, -1);
capture(row,col);
/*
  //brd[row][col] = -1; //places a 1 on the board
 int sum = 0;
  if (sum == 0) {
    brd[row][col] = -1;//places a 1 on the board};
  } else
    if (sum>6) {
      brd[row][col] = -1;
      //capture(inRow,inCol);
    } else {
      brd[row][col] = -(sum); //places sum of surrounding pips on the board
      capture(row,col);
    }
    */
};

/** \brief Finds value of pips above, below, to the left and to the right of selected placement
 *
 * \param
 * \param
 * \return
 *
 */

void Board::UDLR(int inRow,int inCol, int player) {
  //int u,d,l,r;
  int udlr[4];

  // set U
  if(inRow-1<0) { //checking within array bounds
    udlr[0] = 0;
  } else { udlr[0] = abs(brd[inRow-1][inCol]);}

  //set D
  if (inRow+1>=_numRows) {
    udlr[1] = 0;
  } else {udlr[1] = abs(brd[inRow+1][inCol]);}

  //set L
  if(inCol-1<0) {
    udlr[2] = 0;
  } else {udlr[2] = abs(brd[inRow][inCol-1]);}
  // set R
  if (inCol+1>=_numCols) {
    udlr[3] = 0;
  } else {udlr[3] = abs(brd[inRow][inCol+1]);}

  int sum = 0;
  for (int i = 0; i < 4; i++) {
    sum = sum + udlr[i];
    cout << udlr[i] << " ";
  }
  cout << "From UDLR-  sum:" << sum <<" inCol:" << inCol << " _numCols" << _numCols<< endl;
  placeDie(inRow,inCol,sum, player);
};
/*
void Board::placeDie(int inRow,int inCol,int inSum) { //place die
//int sum =0;
cout << "inSum in:" << inSum;
  if (inSum == 0) {
    brd[inRow][inCol] = 1;//places a 1 on the board};
  } else if (inSum>6) { //no capturing
      brd[inRow][inCol] = 1;
      //capture(inRow,inCol);
    } else {
      brd[inRow][inCol] = inSum; //places sum of surrounding pips on the board
      capture(inRow,inCol);
    }
    cout << "inSum out:" << inSum;
};
*/
void Board::placeDie(int inRow,int inCol,int inSum, int player) { //place die
cout << "inSum in:" << inSum;
  if (inSum == 0) {
    brd[inRow][inCol] = player;//places a -1 on the board}
  } else
    if (inSum>6) {
      brd[inRow][inCol] = player;
      //capture(inRow,inCol);
    } else {
      brd[inRow][inCol] = inSum*player; //places sum of surrounding pips on the board
      capture(inRow,inCol);
    }
};



void Board::capture(int inRow, int inCol) {

  if(inRow-1>=0) { //check if in bounds
    brd[inRow-1][inCol] = 0; //captures U
  }
  if (inRow+1<_numRows) {//check if in bounds
    brd[inRow+1][inCol] = 0; //captured D
  }
  if(inCol-1>=0) {//check if in bounds
    brd[inRow][inCol-1] = 0; //captures L
  }
  if (inCol+1<_numCols) {//check if in bounds
    brd[inRow][inCol+1] = 0; //captures R
  }
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
