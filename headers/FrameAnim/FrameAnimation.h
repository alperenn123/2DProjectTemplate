#pragma once
#include <SFML/Graphics.hpp>
#include "types/Types.h"
#include <iostream>



class FrameAnimation
{
	std::vector<sf::IntRect> m_frames;
	sf::Sprite m_sprite;
	uint8 m_frame_index;
	uint8 m_frame_count;
	float m_frame_duration;
	float m_frame_start_time;
public:
	FrameAnimation(sf::Texture* texture);
	void AddFrame(sf::IntRect frame);
	void Update(sf::Time elapsed);
	void Draw(sf::RenderWindow* window);
	void Move(sf::Vector2f pos);
	sf::Vector2f GetPos() const;
};



