#ifndef UNIT_H
#define UNIT_H
#include "entity.h"

enum Unit_type { normal, fast, tank };

class Unit : public Entity
{
public:
	Unit(Unit_type type, std::vector<sf::Texture> &textures);
	virtual ~Unit();
	float get_hp();
	float get_speed();
	int get_emp();
	float get_slow();
	float get_armor();
	int get_tile_xid();
	int get_tile_yid();
	void set_tile_xid(int tile_xid);
	void set_tile_yid(int tile_yid);
	void set_hp(float hp);
	int get_reward();
private:
	Unit_type type_;
	std::vector<sf::Texture> &textures_;
	float hp_;
	float speed_;
	float armor_;
	int reward_;
	int emp_ = 0; //emp flag
	float slow_ = 0; //slow duration in seconds
	int tile_xid_ = 0;
	int tile_yid_ = 1;
};

#endif // UNIT_H
