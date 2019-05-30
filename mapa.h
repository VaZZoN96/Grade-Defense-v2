#ifndef MAPA_H
#define MAPA_H

#include "map_tile.h"
#include "ui.h"
#include <iostream>

class Mapa
{
public:
	Mapa(std::vector<sf::Texture> &textures, UI &ui, std::vector<std::shared_ptr<Map_tile>> &tiles);
	void ver1();
	void step(sf::RenderWindow &window);
private:
	std::vector<sf::Texture> &textures_;
	std::vector<std::shared_ptr<Map_tile>> &tiles_;
	UI &ui_;
};

#endif // MAPA_H
