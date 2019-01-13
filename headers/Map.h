#pragma once

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#define MAP_WIDTH 960
#define MAP_HEIGHT 540
typedef struct {
	sf::Sprite** m_PlayGround;
	bool InitializeMap();
	void SetObject(sf::Sprite* object, int xPos, int yPos);
	sf::Sprite GetObject(int xPos, int yPos);
}Map;
