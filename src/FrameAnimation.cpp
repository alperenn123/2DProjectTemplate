#include <FrameAnim/FrameAnimation.h>

void FrameAnimation::AddFrame(sf::IntRect frame)
{
	m_frames.push_back(frame);
}
FrameAnimation::FrameAnimation(sf::Texture* texture) :
	m_frame_count(0), m_frame_index(0), m_frame_duration(0.2f), m_frame_start_time(0.0f)
{
	m_sprite.setTexture(*texture);
	m_sprite.setTextureRect(sf::IntRect(0, 0, 0, 0));
}
void FrameAnimation::Move(sf::Vector2f pos)
{
	m_sprite.move(pos);
}
sf::Vector2f FrameAnimation::GetPos() const
{
	return m_sprite.getPosition();
}
void FrameAnimation::Update(sf::Time elapsed)
{
	uint8 frame_index = m_frame_index;

	m_frame_count = (uint8)m_frames.size();
	m_frame_start_time += elapsed.asSeconds();

	if (m_frame_start_time >= m_frame_duration)
	{
		m_frame_start_time = 0.0f;

		m_sprite.setTextureRect(m_frames.at(frame_index));
		frame_index = (frame_index + 1) >= m_frame_count ? (frame_index + 1) % m_frame_count : (frame_index + 1);
		m_frame_index = frame_index;
	}
}

void FrameAnimation::Draw(sf::RenderWindow* window)
{
	window->draw(m_sprite);
}
