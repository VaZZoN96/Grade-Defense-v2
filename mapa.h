#ifndef MAPA_H
#define MAPA_H

#include "map_tile.h"
#include "ui.h"
#include "player.h"
#include <iostream>

class Mapa
{
public:
	Mapa(std::vector<sf::Texture> &textures, std::vector<sf::Texture> &textures_unit, std::vector<std::shared_ptr<Unit>> &enemies, UI &ui, std::vector<std::shared_ptr<Map_tile>> &tiles, std::vector<std::shared_ptr<Tower>> &towers, Player &player);
	void ver1();
	void wave();
	void step(sf::RenderWindow &window, float time);
private:
	std::vector<sf::Texture> &textures_;
	std::vector<sf::Texture> &textures_unit_;
	std::vector<std::shared_ptr<Unit>> &enemies_;
	std::vector<std::shared_ptr<Map_tile>> &tiles_;
	std::vector<std::shared_ptr<Tower>> &towers_;
	UI &ui_;
	Player &player_;
	float time_beg_ = 0;
	int iter_ = 1;
	int curr_wave_enemies_count_ = 0;
};

#endif // MAPA_H
