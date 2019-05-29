#ifndef MAPA_H
#define MAPA_H

#include "map_tile.h"
#include "ui.h"
#include <iostream>

class Mapa
{
public:
	Mapa(std::vector<sf::Texture> &textures, UI &ui);
	void ver1();
	void step(sf::RenderWindow &window);
	std::vector<std::unique_ptr<Map_tile>> const& getTiles();
private:
	std::vector<sf::Texture> &textures_;
	std::vector<std::unique_ptr<Map_tile>> tiles_;
	UI &ui_;
};

#endif // MAPA_H
