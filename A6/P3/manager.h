
#ifndef MANAGER_H
#define MANAGER_H

#include<iostream>
#include "player.h"
#include "striker.h"
#include "defender.h"
#include "goalkeeper.h"

class Manager
{
public:
  Manager();
  void add_player(int pos, Player* po);
  void start_game();
  std::string get_result();
private:
  Player* players[6];
  Player* ball_owner;
  int cnt_rounds=0;

  void prepare_game();
  bool is_finish_game();
  void play_round();
};

#endif
