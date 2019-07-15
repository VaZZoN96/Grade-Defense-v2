#include "unit.h"

Unit::Unit(Unit_type type, std::vector<sf::Texture> &textures)
	: type_(type), textures_(textures)
{
	if(type_ == normal)
	{
		hp_ = 100;
		speed_ = 50;
		armor_ = 10;
		reward_ = 25;
	}
	else if(type_ == fast)
	{
		hp_ = 50;
		speed_ = 150;
		armor_ = 10;
		reward_ = 35;
	}
	else if(type_ == tank)
	{
		hp_ = 200;
		speed_ = 30;
		armor_ = 10;
		reward_ = 50;
	}
	setTexture(textures_[type_]);
	setTextureRect(sf::IntRect(0,0,30,30));
	//setPosition(0,200);
	setPosition(tile_xid_*50+10, tile_yid_*50+10+10);
}

Unit::~Unit()
{}

float Unit::get_hp()
{
	return hp_;
}

float Unit::get_speed()
{
	return speed_;
}

int Unit::get_emp()
{
	return emp_;
}

float Unit::get_slow()
{
	return slow_;
}

float Unit::get_armor()
{
	return armor_;
}


int Unit::get_tile_xid()
{
	return tile_xid_;
}

int Unit::get_tile_yid()
{
	return tile_yid_;
}

void Unit::set_tile_xid(int tile_xid)
{
	tile_xid_ = tile_xid;
}

void Unit::set_tile_yid(int tile_yid)
{
	tile_yid_ = tile_yid;
}

void Unit::set_hp(float hp)
{
	hp_ = hp;
}

int Unit::get_reward()
{
	return reward_;
}
