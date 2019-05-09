
#ifndef DEFENDER_H
#define DEFENDER_H

#include "player.h"

class Striker;

class Defender : public Player
{
public:
  Defender(int st,int dr,int ps,int def,std::string tn);
  Player* action();
private:
  bool fight(Striker* st);
  bool fight(Defender* df);
};

#endif
