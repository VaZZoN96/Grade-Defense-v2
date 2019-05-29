#include "map_tile.h"

Map_tile::Map_tile(int xid, int yid, unsigned int type, std::vector<sf::Texture> textures)
	: xid_(xid), x_(xid*30+10), yid_(yid), y_(yid*30+10), type_(type), textures_(textures)
{
	setTexture(textures_[type_]);
	setTextureRect(sf::IntRect(0,0,25,25));
	setPosition(x_, y_);
}

Map_tile::~Map_tile()
{}

int Map_tile::get_xid()
{
	return xid_;
}

int Map_tile::get_yid()
{
	return yid_;
}

int Map_tile::get_x()
{
	return x_;
}

int Map_tile::get_y()
{
	return y_;
}

unsigned int Map_tile::get_type()
{
	return type_;
}

void Map_tile::set_type(int type)
{
	type_ = unsigned(type);
	setTexture(textures_[type_]);
}
