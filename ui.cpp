#include "ui.h"

UI::UI()
{

}

void UI::mouseHandling(float x, float y)
{
	button_pushed_ = 1;
	x_button_ = x;
	y_button_ = y;
}

void UI::reset_mouse_button_pushed()
{
	button_pushed_ = 0;
}

int UI::get_mouse_button_pushed()
{
	return button_pushed_;
}

sf::Vector2f UI::get_mouse_cords()
{
	return sf::Vector2f(x_button_, y_button_);
}

void UI::main_menu()
{
	buttons_main_.emplace_back(std::make_unique<Button>(400, 183, 400, 100, new_game));
	buttons_main_.emplace_back(std::make_unique<Button>(400, 417, 400, 100, options));
}

void UI::tower_menu()
{
	buttons_build_.emplace_back(std::make_unique<Button>(800, 50, 150, 50, att));
	buttons_build_.emplace_back(std::make_unique<Button>(975, 50, 150, 50, attspeed));
	buttons_build_.emplace_back(std::make_unique<Button>(800, 125, 150, 50, range));
	buttons_build_.emplace_back(std::make_unique<Button>(975, 125, 150, 50, rot));
}

void UI::build_menu()
{
	buttons_build_.emplace_back(std::make_unique<Button>(800, 50, 150, 50, machine));
	buttons_build_.emplace_back(std::make_unique<Button>(975, 50, 150, 50, rocket));
	buttons_build_.emplace_back(std::make_unique<Button>(800, 125, 150, 50, light));
	buttons_build_.emplace_back(std::make_unique<Button>(975, 125, 150, 50, laser));
	buttons_build_.emplace_back(std::make_unique<Button>(800, 200, 150, 50, flame));
	buttons_build_.emplace_back(std::make_unique<Button>(975, 200, 150, 50, gauss));
	buttons_build_.emplace_back(std::make_unique<Button>(800, 275, 150, 50, slower));
	buttons_build_.emplace_back(std::make_unique<Button>(975, 275, 150, 50, emp));
}

void UI::step(sf::RenderWindow &window)
{
	std::cout<<active_<<std::endl;
	if(active_ == mai)
	{
		for(unsigned int i=0; i<buttons_main_.size(); i++)
		{
			Button &buttons = dynamic_cast<Button &>(*buttons_main_[i]);

			if(get_mouse_button_pushed() == 1)
			{
				if(get_mouse_cords().x >= buttons.getGlobalBounds().left && get_mouse_cords().x <= buttons.getGlobalBounds().left + buttons.getGlobalBounds().width)
				{
					if(get_mouse_cords().y >= buttons.getGlobalBounds().top && get_mouse_cords().y <= buttons.getGlobalBounds().top + buttons.getGlobalBounds().height)
					{
						if(buttons.get_button_function() == new_game)
						{
							scene_ = battle;
							active_ = none;
						}
						else if(buttons.get_button_function() == options)
						{

						}
					}
				}
			}

			window.draw(buttons);
		}
	}
	else if(active_ == tower)
	{
		for(unsigned int i=0; i<buttons_tower_.size(); i++)
		{
			Button &buttons = dynamic_cast<Button &>(*buttons_tower_[i]);
			window.draw(buttons);
		}
	}
	else if(active_ == build)
	{
		//receive tile x and y and create tower correspondend to button function
		for(unsigned int i=0; i<buttons_build_.size(); i++)
		{
			Button &buttons = dynamic_cast<Button &>(*buttons_build_[i]);
			window.draw(buttons);
		}
	}
}

Menu UI::get_scene()
{
	return scene_;
}

Menu UI::get_active()
{
	return active_;
}

void UI::set_active(Menu active)
{
	active_ = active;
}
