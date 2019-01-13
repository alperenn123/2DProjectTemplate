#include <iostream>
#include <stdlib.h>
#include <stdint.h>
#include "Map.h"
int main()
{
	sf::RenderWindow window(sf::VideoMode(960, 540), "2DPlatform");
	window.setFramerateLimit(60);
	sf::Event event;
	Map map;
	sf::Clock clock;
	uint8_t idle_anim_index = 0;
	
	if (map.InitializeMap())
	{
		sf::Texture tBackground;
		std::vector<std::shared_ptr<sf::Texture>> txt;
		std::shared_ptr<sf::Texture> tPlayerIdle00 = std::make_shared<sf::Texture>();
		std::shared_ptr<sf::Texture> tPlayerIdle01 = std::make_shared<sf::Texture>();
		std::shared_ptr<sf::Texture> tPlayerIdle02 = std::make_shared<sf::Texture>();
		std::shared_ptr<sf::Texture> tPlayerIdle03 = std::make_shared<sf::Texture>();
		std::shared_ptr<sf::Texture> tPlayerIdle04 = std::make_shared<sf::Texture>();
		std::shared_ptr<sf::Texture> tPlayerIdle05 = std::make_shared<sf::Texture>();
		std::shared_ptr<sf::Texture> tPlayerIdle06 = std::make_shared<sf::Texture>();
		tBackground.loadFromFile("..\\..\\textures\\map_background\\game_background_960_540.png");
		tPlayerIdle00->loadFromFile("..\\..\\textures\\player\\KNIGHT\\_DIE\\_DIE_000.png");
		tPlayerIdle01->loadFromFile("..\\..\\textures\\player\\KNIGHT\\_DIE\\_DIE_001.png");
		tPlayerIdle02->loadFromFile("..\\..\\textures\\player\\KNIGHT\\_DIE\\_DIE_002.png");
		tPlayerIdle03->loadFromFile("..\\..\\textures\\player\\KNIGHT\\_DIE\\_DIE_003.png");
		tPlayerIdle04->loadFromFile("..\\..\\textures\\player\\KNIGHT\\_DIE\\_DIE_004.png");
		tPlayerIdle05->loadFromFile("..\\..\\textures\\player\\KNIGHT\\_DIE\\_DIE_005.png");
		tPlayerIdle06->loadFromFile("..\\..\\textures\\player\\KNIGHT\\_DIE\\_DIE_006.png");
		txt.push_back(tPlayerIdle00);
		txt.push_back(tPlayerIdle01);
		txt.push_back(tPlayerIdle02);
		txt.push_back(tPlayerIdle03);
		txt.push_back(tPlayerIdle04);
		txt.push_back(tPlayerIdle05);
		txt.push_back(tPlayerIdle06);
		/*tPlayerIdle->loadFromFile("..\\..\\textures\\player\\KNIGHT\\_DIE\\_DIE_000.png");
		(tPlayerIdle + 1) -> loadFromFile("..\\..\\textures\\player\\KNIGHT\\_DIE\\_DIE_006.png");
(tPlayerIdle + 2)->loadFromFile("..\\..\\textures\\player\\KNIGHT\\_DIE\\_DIE_002.png");
		(tPlayerIdle + 3)->loadFromFile("..\\..\\textures\\player\\KNIGHT\\_DIE\\_DIE_003.png");
		(tPlayerIdle + 4)->loadFromFile("..\\..\\textures\\player\\KNIGHT\\_DIE\\_DIE_004.png");
		(tPlayerIdle + 5)->loadFromFile("..\\..\\textures\\player\\KNIGHT\\_DIE\\_DIE_005.png");
		(tPlayerIdle + 6)->loadFromFile("..\\..\\textures\\player\\KNIGHT\\_DIE\\_DIE_006.png");*/
		sf::Sprite MapBackground(tBackground);
		
		sf::Sprite Player;
		Player.setPosition(100, 100);
		

		while (window.isOpen())
		{
			sf::Time time = clock.getElapsedTime();
			
			while (window.pollEvent(event))
			{
				switch (event.type)
				{
				case sf::Event::Closed: { 
					window.close(); 
					free(map.m_PlayGround);
					 }break;
				}
			}
			if (time.asSeconds() >= 0.2f)
			{
				if (idle_anim_index < 6)
					++idle_anim_index;
				else
					idle_anim_index = 0;
				time = clock.restart();
			}
			
			Player.setTexture(*(txt.at(idle_anim_index)));
			window.clear(sf::Color::Black);
			window.draw(MapBackground);
			window.draw(Player);
			window.display();
		}
	}
	return 0;
}