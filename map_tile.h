#ifndef MAP_TILE_H
#define MAP_TILE_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <memory>

/*
Type - Description
0 - Player can build
1 - Enemy path
2 - Player base
3 - Enemy spawning point
4 - Machine gun
5 - Rocket launcher
6 - Lightning gun
7 - Laser gun
8 - Flamethrower
9 - Gauss
10 - Slower
11 - Stun gun

id = yid * 10 + xid
*/



class Map_tile : public sf::Sprite
{
public:
	Map_tile(unsigned int id, int xid, int yid, unsigned int type, std::vector<sf::Texture> &textures);
	virtual ~Map_tile();
	int get_xid();
	int get_yid();
	int get_x();
	int get_y();
	unsigned int get_type();
	void set_type(int type);
	unsigned int get_id();
private:
	int xid_;
	int x_;
	int yid_;
	int y_;
	unsigned int type_;
	std::vector<sf::Texture> &textures_;
	unsigned int id_;
};

#endif // MAP_TILE_H
