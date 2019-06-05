#include "button.h"

Button::Button(float x, float y, int width, int height, Button_function func, sf::Font &font,  sf::String txt)
	: sf::RectangleShape(sf::Vector2f(width,height)), x_(x), y_(y), func_(func), font_(font)
{
	setPosition(x,y);
	setFillColor(sf::Color(255,0,0));
	text_.setPosition(x+10, y+10);
	text_.setFont(font_);
	text_.setString(txt);
	text_.setCharacterSize(12);
	text_.setFillColor(sf::Color::Black);
}

Button::~Button()
{}

Button_function Button::get_button_function()
{
	return func_;
}

Type Button::change_type(Button_function func)
{
	switch(func)
	{
		case machine: return t_machine;
		case rocket: return t_rocket;
		case light: return t_light;
		case laser: return t_laser;
		case flame: return t_flame;
		case gauss: return t_gauss;
		case slower: return t_slower;
		case emp: return t_emp;
		default: return nothing;
	}
}

sf::Text Button::get_text()
{
	return text_;
}
