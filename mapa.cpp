#include "mapa.h"

Mapa::Mapa(std::vector<sf::Texture> &textures, UI &ui)
	: textures_(textures), ui_(ui)
{
	/*for(int i=0; i<20; i++)
	{
		for(int j=0; j<20; j++)
		{
			tiles_.emplace_back(std::make_unique<Map_tile>(i, j, 0, textures_[0]));
		}
	}*/
	ver1();
}

void Mapa::ver1()
{
	tiles_.emplace_back(std::make_unique<Map_tile>(0, 1, 3, textures_));

	tiles_.emplace_back(std::make_unique<Map_tile>(1, 0, 0, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(2, 0, 0, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(3, 0, 0, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(4, 0, 0, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(5, 0, 0, textures_));

	tiles_.emplace_back(std::make_unique<Map_tile>(1, 1, 1, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(2, 1, 1, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(3, 1, 1, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(4, 1, 1, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(5, 1, 0, textures_));

	tiles_.emplace_back(std::make_unique<Map_tile>(1, 2, 0, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(2, 2, 0, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(3, 2, 0, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(4, 2, 1, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(5, 2, 0, textures_));

	tiles_.emplace_back(std::make_unique<Map_tile>(3, 3, 0, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(4, 3, 1, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(5, 3, 0, textures_));

	tiles_.emplace_back(std::make_unique<Map_tile>(3, 4, 0, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(4, 4, 1, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(5, 4, 0, textures_));

	tiles_.emplace_back(std::make_unique<Map_tile>(3, 5, 0, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(4, 5, 1, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(5, 5, 1, textures_));

	tiles_.emplace_back(std::make_unique<Map_tile>(3, 6, 0, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(4, 6, 0, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(5, 6, 0, textures_));

	tiles_.emplace_back(std::make_unique<Map_tile>(6, 4, 0, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(7, 4, 0, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(8, 4, 0, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(9, 4, 0, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(10, 4, 0, textures_));

	tiles_.emplace_back(std::make_unique<Map_tile>(6, 5, 1, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(7, 5, 1, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(8, 5, 1, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(9, 5, 1, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(10, 5, 2, textures_));

	tiles_.emplace_back(std::make_unique<Map_tile>(6, 6, 0, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(7, 6, 0, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(8, 6, 0, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(9, 6, 0, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(10, 6, 0, textures_));

}

void Mapa::step(sf::RenderWindow &window)
{
	if(ui_.get_mouse_button_pushed() == 1)
	{
		for(unsigned int i=0; i<tiles_.size(); i++)
		{
			Map_tile &tile = dynamic_cast<Map_tile &>(*tiles_[i]);

			sf::FloatRect tile_bounds = tile.getGlobalBounds();

			if( (ui_.get_mouse_cords().x >= tile_bounds.left) && (ui_.get_mouse_cords().x <= tile_bounds.left + tile_bounds.width) )
			{
				if(ui_.get_mouse_cords().y >= tile_bounds.top && ui_.get_mouse_cords().y <= tile_bounds.top + tile_bounds.height)
				{
					//TODO MOUSE DOING THINGS
					if(tile.get_type() == 0)
					{
						//hide tower menu
						//show build menu
					}
					else if( (tile.get_type() >= 4) && (tile.get_type() <= 11) )
					{
						//hide build menu
						//show tower menu
					}
					else
					{
						//hide build menu
						//hide tower menu
					}
				}
			}
		}
		ui_.reset_mouse_button_pushed();
	}

	for(unsigned int i=0; i<tiles_.size(); i++)
	{
		Map_tile &tile = dynamic_cast<Map_tile &>(*tiles_[i]);
		window.draw(tile);
	}
}

std::vector<std::unique_ptr<Map_tile>> const& Mapa::getTiles()
{
	return tiles_;
}
