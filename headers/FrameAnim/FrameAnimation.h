#pragma once
#include <SFML/Graphics.hpp>
#include "types/Types.h"
#include <iostream>



class FrameAnimation : public sf::Drawable, public sf::Transformable
{
	std::vector<sf::IntRect> m_frames;
	sf::Sprite				m_sprite;
	std::size_t				m_currentFrame;
	sf::Time				m_duration;
	sf::Time				m_elapsedTime;
public:
	FrameAnimation(const sf::Texture& texture);
	void					AddFrame(sf::IntRect new_frame);
	void 					setTexture(const sf::Texture& texture);
	const sf::Texture* 		getTexture() const;
	void 					setDuration(sf::Time duration);
	sf::Time 				getDuration() const;
	bool 					isFinished() const;
	sf::FloatRect 			getLocalBounds() const;
	sf::FloatRect 			getGlobalBounds() const;
	void 					update(sf::Time dt, bool is_repeat);
	sf::IntRect             getFrame() const;
private:
	void 					draw(sf::RenderTarget& target, sf::RenderStates states) const;

};



