#include "tower.h"

Tower::Tower(Type type)
	: type_(type)
{
	if(type == t_machine) //Machine gun
	{
		rot_ = 0;
		range_ = 100;
		dmg_ = 100;
		cost_ = 0;
		at_speed_ = 1;
	}
	else if(type == t_rocket) //Rocket launcher
	{
		rot_ = 0;
		range_ = 0;
		dmg_ = 0;
		cost_ = 0;
		at_speed_ = 0;
	}
	else if(type == t_light) //Lightning gun
	{
		rot_ = 0;
		range_ = 0;
		dmg_ = 0;
		cost_ = 0;
		at_speed_ = 0;
		chains_ = 0;
	}
	else if(type == t_laser) //Laser gun
	{
		rot_ = 0;
		range_ = 0;
		dmg_ = 0;
		cost_ = 0;
		cont_ = 1;
	}
	else if(type == t_flame) //Flamethrower
	{
		rot_ = 0;
		range_ = 0;
		dmg_ = 0;
		cost_ = 0;
		cont_ = 1;
	}
	else if(type == t_gauss) //Gauss gun
	{
		rot_ = 0;
		range_ = 0;
		dmg_ = 0;
		cost_ = 0;
		at_speed_ = 0;
	}
	else if(type == t_slower) //Slower
	{
		range_ = 0;
		cost_ = 0;
		cont_ = 1;
	}
	else if(type == t_emp) //EMP
	{
		range_ = 0;
		dmg_ = 0;
		cost_ = 0;
		at_speed_ = 0;
	}
}

Tower::~Tower()
{}


float Tower::get_dmg()
{
	return dmg_;
}

float Tower::get_range()
{
	return range_;
}

float Tower::get_cost()
{
	return cost_;
}

float Tower::get_at_speed()
{
	return at_speed_;
}

int Tower::get_cont()
{
	return cont_;
}

int Tower::get_chains_()
{
	return chains_;
}
