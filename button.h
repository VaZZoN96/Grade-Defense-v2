#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "tower.h"

enum Button_function { new_game, options,
					   machine, rocket, light, laser, flame, gauss, slower, emp,
					   att, attspeed, range, rot};

class Button : public sf::RectangleShape
{
public:
	Button(float x, float y, int width, int height, Button_function func, sf::Font &font, sf::String txt);
	virtual ~Button();
	Button_function get_button_function();
	Type change_type(Button_function func);
	sf::Text get_text();
private:
	float x_;
	float y_;
	sf::FloatRect bounds = getGlobalBounds();
	Button_function func_;
	sf::Text text_;
	sf::Font &font_;
};

#endif // BUTTON_H
