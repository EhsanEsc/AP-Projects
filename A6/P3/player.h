
#ifndef PLAYER_H
#define PLAYER_H

#include<string>

class Player
{
public:
  Player(int st, int dr, int ps, int def, std::string tn);
  std::string get_team();
  int get_defend();
  void tired();
  bool score_goal();

  void set_back(Player* po);
  void set_front(Player* po);
  void set_reciver(Player* po);

  Player* get_back();

  virtual Player* action() = 0;
protected:
  int stamina;
  int dribble;
  int defend;
  int pass;
  std::string team_name;

  Player* front_player;
  Player* back_player;
  Player* reciver;
};

#endif
