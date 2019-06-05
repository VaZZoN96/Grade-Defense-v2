#ifndef UNIT_H
#define UNIT_H
#include "entity.h"

enum Unit_type { normal, fast, tank };

class Unit : public Entity
{
public:
	Unit();
	virtual ~Unit();
	float get_hp();
	float get_speed();
	int get_emp();
	float get_slow();
	float get_armor();
private:
	Unit_type type_;
	float hp_;
	float speed_;
	float armor_;
	int emp_ = 0; //emp flag
	float slow_ = 0; //slow duration in seconds
};

#endif // UNIT_H
