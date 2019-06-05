#include "unit.h"

Unit::Unit()
{
	if(type_ == normal)
	{
		hp_ = 100;
		speed_ = 0;
		armor_ = 0;
	}
	else if(type_ == fast)
	{
		hp_ = 0;
		speed_ = 0;
		armor_ = 0;
	}
	else if(type_ == tank)
	{
		hp_ = 0;
		speed_ = 0;
		armor_ = 0;
	}
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
