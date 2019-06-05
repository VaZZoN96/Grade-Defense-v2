#ifndef TOWER_H
#define TOWER_H

#include "entity.h"
#include "map_tile.h"
#include <iostream>

enum Type { nothing, t_machine, t_rocket, t_light, t_laser, t_flame, t_gauss, t_slower, t_emp };

class Tower : public Entity
{
public:
	Tower(Type type);
	virtual ~Tower();
	float get_dmg();
	float get_range();
	float get_cost();
	float get_at_speed();
	int get_cont();
	int get_chains_();
private:
	Type type_;

	float rot_;
	float range_;
	float dmg_;
	float cost_;
	float at_speed_;
	int cont_ = 0;
	int chains_ = 0;
};

#endif // TOWER_H
