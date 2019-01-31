#include <FrameAnim/FrameAnimation.h>

FrameAnimation::FrameAnimation(const sf::Texture& texture) :
	m_sprite(texture),
	m_currentFrame(0),
	m_duration(sf::Time::Zero),
	m_elapsedTime(sf::Time::Zero)
{
}
void FrameAnimation::setTexture(const sf::Texture& texture)
{
	m_sprite.setTexture(texture);
}

const sf::Texture* FrameAnimation::getTexture() const
{
	return m_sprite.getTexture();
}


void FrameAnimation::setDuration(sf::Time duration)
{
	m_duration = duration;
}

sf::Time FrameAnimation::getDuration() const
{
	return m_duration;
}
bool FrameAnimation::isFinished() const
{
	return m_currentFrame >= m_frames.size();
}
sf::IntRect FrameAnimation::getFrame() const
{
	return m_frames.at(m_currentFrame);
}
sf::FloatRect FrameAnimation::getLocalBounds() const
{
	sf::IntRect rect = getFrame();

	float width = static_cast<float>(std::abs(rect.width));
	float height = static_cast<float>(std::abs(rect.height));

	return sf::FloatRect(getOrigin(), sf::Vector2f(width,height));
}

sf::FloatRect FrameAnimation::getGlobalBounds() const
{
	return getTransform().transformRect(getLocalBounds());
}
void FrameAnimation::update(sf::Time dt, bool is_repeat)
{
	sf::Time timePerFrame = m_duration / static_cast<float>(m_frames.size());
	m_elapsedTime += dt;

	sf::IntRect textureRect = m_sprite.getTextureRect();
	if (m_currentFrame == 0)
	{
		textureRect = m_frames.at(0);
	}

	while (m_elapsedTime >= timePerFrame && (m_currentFrame <= m_frames.size()))
	{
		m_elapsedTime -= timePerFrame;
		if (is_repeat)
		{
			m_currentFrame = (m_currentFrame + 1) >= m_frames.size() ? (m_currentFrame + 1) % m_frames.size() : (m_currentFrame + 1);
			//m_currentFrame = (m_currentFrame + 1) % m_numFrames;

			textureRect = m_frames.at(m_currentFrame);
		}
		else
		{
			++m_currentFrame;
		}
		
	}

	m_sprite.setTextureRect(textureRect);
}

void FrameAnimation::AddFrame(sf::IntRect new_frame)
{
	m_frames.push_back(new_frame);
}

void FrameAnimation::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(m_sprite, states);
}

