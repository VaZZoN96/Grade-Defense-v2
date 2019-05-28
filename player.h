#ifndef PLAYER_H
#define PLAYER_H

#include "tower.h"
#include "base.h"
#include <iostream>

class Player
{
public:
	Player();
	void mouseHandling(float x, float y);
	void reset_button_pushed();
	int get_button_pushed();
	sf::Vector2f get_mouse_cords();
private:
	int button_pushed_ = 0;
	float x_button_ = 0;
	float y_button_ = 0;
};

#endif // PLAYER_H
