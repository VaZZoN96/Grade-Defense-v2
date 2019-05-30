#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "base.h"
#include "entity.h"
#include "map_tile.h"
#include "mapa.h"
#include "player.h"
#include "tower.h"
#include "unit.h"

#include <iostream>
/*
DONE


IN PROGRESS
UI class
Mapa class
Map_tile class
Button class
Tower class
UI
If built a tower then set tile type to correspondend one


TODO
Entity class
Unit class
Player class
Base class

Mouse event

Unit stats
Tower stats

Opisać typy
Change UI menus functions to creators

Procedural, random or predefined map creating
Damage dealing, money receiving, hp decreasing for units
Hp decreasing for players base
Collision detection???
*/

int main() {
	// create the window
	sf::RenderWindow window(sf::VideoMode(1200, 700), "Grade defense");
	//window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);

	//test tx
	std::vector<sf::Texture> textures;
	{
		sf::Texture tx_tile; //Tile where player can build
		if(!tx_tile.loadFromFile("texture/tile.png")){}
		textures.emplace_back(tx_tile);
		sf::Texture tx_tile_enemy; //Tile where enemy is going
		if(!tx_tile_enemy.loadFromFile("texture/tile_enemy.png")){}
		textures.emplace_back(tx_tile_enemy);
		sf::Texture tx_tile_base; //Tile where player's base is
		if(!tx_tile_base.loadFromFile("texture/tile_base.png")){}
		textures.emplace_back(tx_tile_base);
		sf::Texture tx_tile_spawn; //Tile where enemy's spawning point is
		if(!tx_tile_spawn.loadFromFile("texture/tile_spawn.png")){}
		textures.emplace_back(tx_tile_spawn);

		sf::Texture tx_tile_machine;
		if(!tx_tile_machine.loadFromFile("texture/tile_machine.png")){}
		textures.emplace_back(tx_tile_machine);

		sf::Texture tx_tile_rocket;
		if(!tx_tile_rocket.loadFromFile("texture/tile_place.png")){}
		textures.emplace_back(tx_tile_rocket);

		sf::Texture tx_tile_lightning;
		if(!tx_tile_lightning.loadFromFile("texture/tile_place.png")){}
		textures.emplace_back(tx_tile_lightning);

		sf::Texture tx_tile_laser;
		if(!tx_tile_laser.loadFromFile("texture/tile_place.png")){}
		textures.emplace_back(tx_tile_laser);

		sf::Texture tx_tile_flamethrower;
		if(!tx_tile_flamethrower.loadFromFile("texture/tile_place.png")){}
		textures.emplace_back(tx_tile_flamethrower);

		sf::Texture tx_tile_gauss;
		if(!tx_tile_gauss.loadFromFile("texture/tile_place.png")){}
		textures.emplace_back(tx_tile_gauss);

		sf::Texture tx_tile_slower;
		if(!tx_tile_slower.loadFromFile("texture/tile_place.png")){}
		textures.emplace_back(tx_tile_slower);

		sf::Texture tx_tile_stun;
		if(!tx_tile_stun.loadFromFile("texture/tile_place.png")){}
		textures.emplace_back(tx_tile_stun);
	}

	std::vector<std::unique_ptr<Tower>> towers;
	std::vector<std::unique_ptr<Unit>> enemies;
	std::vector<std::shared_ptr<Map_tile>> tiles;

	UI ui(towers, enemies, tiles);
	ui.main_menu();
	ui.build_menu();
	ui.tower_menu();
	Player player;
	Mapa mapa(textures, ui, tiles);


	//Setting a clock
	sf::Clock clock;
	sf::Time elapsed_time;

	// run the program as long as the window is open
	while (window.isOpen()) {
		elapsed_time = clock.getElapsedTime();
		//std::cout<<elapsed_time.asMicroseconds()<<" "<<1/elapsed_time.asSeconds()<<std::endl;
		clock.restart();

		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event)) {
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();

			//Keyboard and mouse
			if(event.type == sf::Event::MouseButtonReleased)
			{
				if(event.mouseButton.button == sf::Mouse::Left)
				{
					ui.mouseHandling(event.mouseButton.x, event.mouseButton.y);
				}
			}
			/*if(event.type == sf::Event::MouseButtonReleased)
				if(event.mouseButton.button == sf::Mouse::Left)
					if(event.mouseButton.x >= 10 && event.mouseButton.x <= 35)
						if(event.mouseButton.y >= 50 && event.mouseButton.y <= 75)
						{
							if(p1.get_money() >= 75)
							{
								Unit unit(p1, 1, tx_melee);
								p1_unit.push_back(unit);
							}
						}
			if(event.type == sf::Event::MouseButtonReleased)
				if(event.mouseButton.button == sf::Mouse::Left)
					if(event.mouseButton.x >= 40 && event.mouseButton.x <= 65)
						if(event.mouseButton.y >= 50 && event.mouseButton.y <= 75)
						{
							if(p1.get_money() >= 125)
							{
								Unit unit(p1, 2, tx_ranged);
								p1_unit.push_back(unit);
							}
						}
			if(event.type == sf::Event::MouseButtonReleased)
				if(event.mouseButton.button == sf::Mouse::Left)
					if(event.mouseButton.x >= 70 && event.mouseButton.x <= 95)
						if(event.mouseButton.y >= 50 && event.mouseButton.y <= 75)
						{
							if(p1.get_money() >= 200)
							{
								Unit unit(p1, 3, tx_tank);
								p1_unit.push_back(unit);
							}
						}
			if(event.type == sf::Event::MouseButtonReleased)
				if(event.mouseButton.button == sf::Mouse::Left)
					if(event.mouseButton.x >= 100 && event.mouseButton.x <= 125)
						if(event.mouseButton.y >= 50 && event.mouseButton.y <= 75)
						{
							//lvl up
						}
			//Testing
			if(event.type == sf::Event::KeyPressed)
			{
				if(event.key.code == sf::Keyboard::Num1)
				{
					Unit unit(p2, 1, tx_melee);
					p2_unit.push_back(unit);
				}
			}*/
		}

		// clear the window with black color
		window.clear(sf::Color(180, 180, 180));

		if(ui.get_scene() == mai)
		{
			ui.step(window);
		}
		else if(ui.get_scene() == battle)
		{
			ui.step(window);
			mapa.step(window);
		}

		window.display();
	}

	return 0;
}
