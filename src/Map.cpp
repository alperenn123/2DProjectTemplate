#include "Map.h"

bool Map::InitializeMap()
{
	m_PlayGround = (sf::Sprite**)malloc(sizeof(sf::Sprite*)*MAP_WIDTH*MAP_HEIGHT);
	bool flag = false;
	if (m_PlayGround == nullptr)
	{
		flag = false;
	}
	else
	{
		flag = true;
	}
	return flag;
}

void Map::SetObject(sf::Sprite* object, int xPos, int yPos)
{
	m_PlayGround[xPos][yPos] = *object;
}
sf::Sprite Map::GetObject(int xPos,int yPos)
{
	return m_PlayGround[xPos][yPos];
}