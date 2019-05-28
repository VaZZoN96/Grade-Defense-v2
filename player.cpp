#include "player.h"
#include <iostream>

Player::Player()
{

}

void Player::mouseHandling(float x, float y)
{
	button_pushed_ = 1;
	x_button_ = x;
	y_button_ = y;
}

void Player::reset_button_pushed()
{
	button_pushed_ = 0;
}

int Player::get_button_pushed()
{
	return button_pushed_;
}

sf::Vector2f Player::get_mouse_cords()
{
	return sf::Vector2f(x_button_, y_button_);
}
