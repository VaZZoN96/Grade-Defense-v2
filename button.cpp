#include "button.h"

Button::Button(float x, float y, int width, int height, Button_function func)
	: sf::RectangleShape(sf::Vector2f(width,height)), x_(x), y_(y), func_(func)
{
	setPosition(x,y);
	setFillColor(sf::Color(255,0,0));
}

Button::~Button()
{}

Button_function Button::get_button_function()
{
	return func_;
}
