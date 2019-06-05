#include "mapa.h"

Mapa::Mapa(std::vector<sf::Texture> &textures, UI &ui, std::vector<std::shared_ptr<Map_tile>> &tiles)
	: textures_(textures), tiles_(tiles), ui_(ui)
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
	tiles_.emplace_back(std::make_unique<Map_tile>(0, 0, 1, 3, textures_));

	tiles_.emplace_back(std::make_unique<Map_tile>(1, 1, 0, 0, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(2, 2, 0, 0, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(3, 3, 0, 0, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(4, 4, 0, 0, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(5, 5, 0, 0, textures_));

	tiles_.emplace_back(std::make_unique<Map_tile>(6, 1, 1, 1, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(7, 2, 1, 1, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(8, 3, 1, 1, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(9, 4, 1, 1, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(10, 5, 1, 0, textures_));

	tiles_.emplace_back(std::make_unique<Map_tile>(11, 1, 2, 0, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(12, 2, 2, 0, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(13, 3, 2, 0, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(14, 4, 2, 1, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(15, 5, 2, 0, textures_));

	tiles_.emplace_back(std::make_unique<Map_tile>(16, 3, 3, 0, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(17, 4, 3, 1, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(18, 5, 3, 0, textures_));

	tiles_.emplace_back(std::make_unique<Map_tile>(19, 3, 4, 0, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(20, 4, 4, 1, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(21, 5, 4, 0, textures_));

	tiles_.emplace_back(std::make_unique<Map_tile>(22, 3, 5, 0, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(23, 4, 5, 1, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(24, 5, 5, 1, textures_));

	tiles_.emplace_back(std::make_unique<Map_tile>(25, 3, 6, 0, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(26, 4, 6, 0, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(27, 5, 6, 0, textures_));

	tiles_.emplace_back(std::make_unique<Map_tile>(28, 6, 4, 0, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(29, 7, 4, 0, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(30, 8, 4, 0, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(31, 9, 4, 0, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(32, 10, 4, 0, textures_));

	tiles_.emplace_back(std::make_unique<Map_tile>(33, 6, 5, 1, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(34, 7, 5, 1, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(35, 8, 5, 1, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(36, 9, 5, 1, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(37, 10, 5, 2, textures_));

	tiles_.emplace_back(std::make_unique<Map_tile>(38, 6, 6, 0, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(39, 7, 6, 0, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(40, 8, 6, 0, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(41, 9, 6, 0, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(42, 10, 6, 0, textures_));

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
						ui_.set_active(build);
						//send tile x and y and vector of tiles and i
						ui_.receive_tile(i);
					}
					else if( (tile.get_type() >= 4) && (tile.get_type() <= 11) )
					{
						//hide build menu
						//show tower menu
						ui_.set_active(tower);
					}
					else
					{
						//hide build menu
						//hide tower menu
						ui_.set_active(none);
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
