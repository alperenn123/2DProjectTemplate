#include "animation/Animation.h"
#include "renderer/Renderer.h"
using namespace Game;
int main()
{
	uint16 screen_width	 = 640;
	uint16 screen_height = 360;
	char* window_title = "2D GAME";
	sf::Texture idle_sprite_sheet;
	idle_sprite_sheet.loadFromFile("..\\..\\textures\\player\\Idle.png");
	sf::RenderWindow window(sf::VideoMode(screen_width, screen_height), window_title);
	sf::Event event;
	Animation::sAnimation animation;

	Animation::SetSpriteSheet(&idle_sprite_sheet,&animation);
	Animation::Init(&animation);
	Animation::Frame idle_frames[11];

	uint8 text_width = 88;
	uint8 text_height = 128;
	sf::IntRect l_frame;
	l_frame.height = text_height;
	l_frame.width = text_width;
	l_frame.top = 0;
	for (uint8 i = 0; i < 11; i++)
	{
		idle_frames[i].m_frame_start_time = 0.0f;
		idle_frames[i].m_frame_duration = 0.1f;
		l_frame.left = text_width * i;;
		idle_frames[i].rect = l_frame;
	}
	Animation::AddFrames(&idle_frames[0], 11, &animation);
	sf::Clock clock;
	while (window.isOpen())
	{
		sf::Time elapsed = clock.restart();
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed: {window.close(); }
			}
		}
		Animation::Update(elapsed, &animation);
		window.clear(sf::Color::Black);
		window.draw(animation.m_object);
		window.display();
	}


	return 0;
}