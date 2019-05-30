#ifndef UI_H
#define UI_H

#include "button.h"
#include "unit.h"
#include "tower.h"
#include "map_tile.h"

#include <iostream>

enum Menu { none, mai, battle, tower, build };

class UI
{
public:
	UI(std::vector<std::unique_ptr<Tower>> &towers, std::vector<std::unique_ptr<Unit>> &enemies, std::vector<std::shared_ptr<Map_tile>> &tiles);
	void mouseHandling(float x, float y);
	void reset_mouse_button_pushed();
	int get_mouse_button_pushed();
	sf::Vector2f get_mouse_cords();

	void main_menu(); //Prepare main menu
	void tower_menu(); //Prepare tower menu
	void build_menu(); //Prepare build menu
	void step(sf::RenderWindow &window);
	Menu get_scene();
	Menu get_active();
	void set_active(Menu active);
	void receive_tile(unsigned int tile_id);
private:
	int button_pushed_ = 0;
	float x_button_ = 0;
	float y_button_ = 0;
	Menu scene_ = mai;
	Menu active_ = mai;
	std::vector<std::unique_ptr<Button>> buttons_main_;
	std::vector<std::unique_ptr<Button>> buttons_tower_;
	std::vector<std::unique_ptr<Button>> buttons_build_;
	std::vector<std::unique_ptr<Tower>> &towers_;
	std::vector<std::unique_ptr<Unit>> &enemies_;
	std::vector<std::shared_ptr<Map_tile>> &tiles_;
	unsigned int tile_id_ = 0;
};

#endif // UI_H
