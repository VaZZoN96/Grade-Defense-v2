#ifndef PLAYER_H
#define PLAYER_H

#include "tower.h"
#include "base.h"
#include <iostream>

class Player
{
public:
	Player();
	int get_money();
	void set_money(int money);
	int get_hp();
	void set_hp(int hp);
private:
	int money_ = 500;
	int hp_ = 100;
};

#endif // PLAYER_H
