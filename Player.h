#ifndef PLAYER_H
#define PLAYER_H


class Player {

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



#endif // PLAYER_H
