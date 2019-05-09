
#ifndef GOALKEEPER_H
#define GOALKEEPER_H

#include "player.h"

class Striker;

class GoalKeeper : public Player
{
public:
  GoalKeeper(int st,int dr,int ps,int def,std::string tn);
  Player* action();
private:
  bool fight(Striker* st);
};

#endif
