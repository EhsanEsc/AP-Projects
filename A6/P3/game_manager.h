
#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "manager.h"

class game_manager
{
public:
	void add_team_A_goalkeeper(int stamina, int dribble, int pass, int defend);
	void add_team_A_defender(int stamina, int dribble, int pass, int defend);
	void add_team_A_striker(int stamina, int dribble, int pass, int defend);
	void add_team_B_goalkeeper(int stamina, int dribble, int pass, int defend);
	void add_team_B_defender(int stamina, int dribble, int pass, int defend);
	void add_team_B_striker(int stamina, int dribble, int pass, int defend);
	void play();
	std::string get_result();
private:
	Manager manager;
};

#endif
