#ifndef UI_H
#define UI_H

#include "button.h"

#include "tower.h"

#include <iostream>

enum Menu { none, mai, battle, tower, build };

class UI
{
public:
	UI();
	void mouseHandling(float x, float y);
	void reset_mouse_button_pushed();
	int get_mouse_button_pushed();
	sf::Vector2f get_mouse_cords();

	void main_menu(); //Prepare main menu
	void main_menu_show();
	void tower_menu(); //Prepare tower menu
	void tower_menu_show();
	void build_menu(); //Prepare build menu
	void build_menu_show();
	void step(sf::RenderWindow &window);
	Menu get_scene();
	Menu get_active();
private:
	int button_pushed_ = 0;
	float x_button_ = 0;
	float y_button_ = 0;
	Menu scene_ = mai;
	Menu active_ = mai;
	std::vector<std::unique_ptr<Button>> buttons_main_;
	std::vector<std::unique_ptr<Button>> buttons_tower_;
	std::vector<std::unique_ptr<Button>> buttons_build_;
};

#endif // UI_H
