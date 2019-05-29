#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Button : public sf::Sprite
{
public:
	Button();
	virtual ~Button();
private:
	sf::FloatRect bounds = getGlobalBounds();
};

#endif // BUTTON_H
