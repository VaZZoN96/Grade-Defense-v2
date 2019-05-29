#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

enum Button_function { new_game, options,
					   machine, rocket, light, laser, flame, gauss, slower, emp,
					   att, attspeed, range, rot};

class Button : public sf::RectangleShape
{
public:
	Button(float x, float y, int width, int height, Button_function func);
	virtual ~Button();
	Button_function get_button_function();
private:
	float x_;
	float y_;
	sf::FloatRect bounds = getGlobalBounds();
	Button_function func_;
};

#endif // BUTTON_H
