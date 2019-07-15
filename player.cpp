#include "player.h"
#include <iostream>

Player::Player()
{

}

int Player::get_money()
{
	return money_;
}

void Player::set_money(int money)
{
	money_ = money;
}

int Player::get_hp()
{
	return hp_;
}

void Player::set_hp(int hp)
{
	hp_ = hp;
}
