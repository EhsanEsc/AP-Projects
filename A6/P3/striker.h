
#ifndef STRIKER_H
#define STRIKER_H

#include "player.h"

class GoalKeeper;
class Defender;

class Striker : public Player
{
public:
  Striker(int st,int dr,int ps,int def,std::string tn);
  Player* action();
private:
  void drible();
  bool fight(Striker* st);
  bool fight(GoalKeeper* gk);
  bool fight(Defender* df);
};

#endif
