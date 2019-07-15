#include "mapa.h"
#include <cmath>

Mapa::Mapa(std::vector<sf::Texture> &textures, std::vector<sf::Texture> &textures_unit, std::vector<std::shared_ptr<Unit>> &enemies, UI &ui, std::vector<std::shared_ptr<Map_tile>> &tiles, std::vector<std::shared_ptr<Tower>> &towers, Player &player)
	: textures_(textures), textures_unit_(textures_unit), enemies_(enemies), tiles_(tiles), towers_(towers), ui_(ui), player_(player)
{
	/*for(int i=0; i<20; i++)
	{
		for(int j=0; j<20; j++)
		{
			tiles_.emplace_back(std::make_unique<Map_tile>(i, j, 0, textures_[0]));
		}
	}*/
	ver1();
	wave();
}

void Mapa::ver1()
{
	tiles_.emplace_back(std::make_unique<Map_tile>(0, 0, 0, 20, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(1, 1, 0, 0, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(2, 2, 0, 0, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(3, 3, 0, 0, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(4, 4, 0, 0, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(5, 5, 0, 0, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(6, 6, 0, 20, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(7, 7, 0, 20, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(8, 8, 0, 20, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(9, 9, 0, 20, textures_));

	tiles_.emplace_back(std::make_unique<Map_tile>(10, 0, 1, 3, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(11, 1, 1, 1, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(12, 2, 1, 1, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(13, 3, 1, 1, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(14, 4, 1, 1, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(15, 5, 1, 0, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(16, 6, 1, 20, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(17, 7, 1, 20, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(18, 8, 1, 20, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(19, 9, 1, 20, textures_));

	tiles_.emplace_back(std::make_unique<Map_tile>(20, 0, 2, 20, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(21, 1, 2, 0, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(22, 2, 2, 0, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(23, 3, 2, 0, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(24, 4, 2, 1, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(25, 5, 2, 0, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(26, 6, 2, 20, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(27, 7, 2, 20, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(28, 8, 2, 20, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(29, 9, 2, 20, textures_));

	tiles_.emplace_back(std::make_unique<Map_tile>(30, 0, 3, 20, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(31, 1, 3, 20, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(32, 2, 3, 20, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(33, 3, 3, 0, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(34, 4, 3, 1, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(35, 5, 3, 0, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(36, 6, 3, 20, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(37, 7, 3, 20, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(38, 8, 3, 20, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(39, 9, 3, 20, textures_));

	tiles_.emplace_back(std::make_unique<Map_tile>(40, 0, 4, 20, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(41, 1, 4, 20, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(42, 2, 4, 20, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(43, 3, 4, 0, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(44, 4, 4, 1, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(45, 5, 4, 0, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(46, 6, 4, 0, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(47, 7, 4, 0, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(48, 8, 4, 0, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(49, 9, 4, 0, textures_));

	tiles_.emplace_back(std::make_unique<Map_tile>(50, 0, 5, 20, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(51, 1, 5, 20, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(52, 2, 5, 20, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(53, 3, 5, 0, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(54, 4, 5, 1, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(55, 5, 5, 1, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(56, 6, 5, 1, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(57, 7, 5, 1, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(58, 8, 5, 1, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(59, 9, 5, 2, textures_));

	tiles_.emplace_back(std::make_unique<Map_tile>(60, 0, 6, 20, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(61, 1, 6, 20, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(62, 2, 6, 20, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(63, 3, 6, 0, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(64, 4, 6, 0, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(65, 5, 6, 0, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(66, 6, 6, 0, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(67, 7, 6, 0, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(68, 8, 6, 0, textures_));
	tiles_.emplace_back(std::make_unique<Map_tile>(69, 9, 6, 0, textures_));
}

void Mapa::wave()
{
	enemies_.emplace_back(std::make_unique<Unit>(normal, textures_unit_));
}

void Mapa::step(sf::RenderWindow &window, float time)
{
	unsigned int id_to_erase = 100;
	time_beg_ += time;

	if(ui_.get_next_wave() == 1)
	{
		curr_wave_enemies_count_ = 20;
		ui_.set_next_wave(0);
		wave();
	}

	//if(time_beg_ >= iter_)
	//{
		/*if(curr_wave_enemies_count_ > 0)
		{
			wave();
			curr_wave_enemies_count_--;
		}*/
	//}




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
						ui_.set_active(tower);
					}
					else
					{
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

	for(unsigned int i=0; i<enemies_.size(); i++)
	{
		Unit &unit = dynamic_cast<Unit &>(*enemies_[i]);

		//if(time_beg_ >= iter_)
		//{
			for(unsigned int j=0; j<towers_.size(); j++)
			{
				Tower &tower = dynamic_cast<Tower &>(*towers_[i]);
				float first = tower.get_x() - unit.getPosition().x;
				float second = tower.get_y() - unit.getPosition().y;
				float distance = float(sqrt(pow(double(first), 2) + pow(double(second), 2)));

				if(distance <= tower.get_range())
				{
					unit.set_hp(unit.get_hp() - tower.get_dmg()*tower.get_at_speed()*time);
				}
			}
		//}
		if(tiles_[unsigned(unit.get_tile_yid() * 10 + unit.get_tile_xid())]->get_type() == 2)
		{
			player_.set_hp(player_.get_hp() - 1);
			id_to_erase = i;
		}
		//if right tile is path
		if( (tiles_[unsigned(unit.get_tile_yid() * 10 + unit.get_tile_xid() + 1)]->get_type() == 1) || (tiles_[unsigned(unit.get_tile_yid() * 10 + unit.get_tile_xid() + 1)]->get_type() == 2) )
		{
			if(unit.getPosition().x >= (unit.get_tile_xid() * 50 + 10 + 60) )
			{
				unit.set_tile_xid(unit.get_tile_xid() + 1);
			}

			unit.move(unit.get_speed()*time, 0);
		}
		//if bottom tile is path
		if( tiles_[unsigned( (unit.get_tile_yid() + 1) * 10 + unit.get_tile_xid())]->get_type() == 1)
		{
			if(unit.getPosition().y >= (unit.get_tile_xid() * 50 + 10 + 55) )
			{
				unit.set_tile_yid(unit.get_tile_yid() + 1);
			}

			unit.move(0, unit.get_speed()*time);
		}
		if(unit.get_hp() <= 1)
		{
			id_to_erase = i;
			player_.set_money(player_.get_money() + unit.get_reward());
		}
		window.draw(unit);
	}

	if(id_to_erase != 100)
	{
		enemies_.erase(enemies_.begin() + id_to_erase);
		id_to_erase = 100;
	}

	if(time_beg_ >= iter_)
	{
		std::cout<<"MONEY: "<<player_.get_money()<<" HP: "<<player_.get_hp()<<std::endl;
		iter_++;
	}
}
