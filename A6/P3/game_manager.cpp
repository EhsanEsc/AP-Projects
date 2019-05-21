
#include "game_manager.h"

void game_manager::add_team_A_goalkeeper(int stamina, int dribble, int pass, int defend)
{
  manager.add_player(0,new GoalKeeper(stamina, dribble, pass, defend,"A"));
}

void game_manager::add_team_A_defender(int stamina, int dribble, int pass, int defend)
{
  manager.add_player(1,new Defender(stamina, dribble, pass, defend,"A"));
}

void game_manager::add_team_A_striker(int stamina, int dribble, int pass, int defend)
{
  manager.add_player(2,new Striker(stamina, dribble, pass, defend,"A"));
}

void game_manager::add_team_B_goalkeeper(int stamina, int dribble, int pass, int defend)
{
  manager.add_player(5,new GoalKeeper(stamina, dribble, pass, defend,"B"));
}

void game_manager::add_team_B_defender(int stamina, int dribble, int pass, int defend)
{
  manager.add_player(4,new Defender(stamina, dribble, pass, defend,"B"));
}

void game_manager::add_team_B_striker(int stamina, int dribble, int pass, int defend)
{
  manager.add_player(3,new Striker(stamina, dribble, pass, defend,"B"));
}

void game_manager::play()
{
  manager.start_game();
}

std::string game_manager::get_result()
{
  return manager.get_result();
}
