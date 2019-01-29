#include <FrameAnim/FrameAnimation.h>
#include "renderer/Renderer.h"

int main()
{
	uint16 screen_width	 = 640;
	uint16 screen_height = 480;
	char* window_title = "2D GAME";
	sf::Texture walk_sprite_sheet;
	walk_sprite_sheet.loadFromFile("..\\..\\textures\\player\\sprite_sheet.png");
	sf::RenderWindow window(sf::VideoMode(screen_width, screen_height), window_title);
	window.setFramerateLimit(60);
	sf::Event event;
	FrameAnimation* current_anim;
	FrameAnimation walkingAnimationRight(&walk_sprite_sheet);
	FrameAnimation walkingAnimationDown(&walk_sprite_sheet);
	/*run_anim.AddFrame(sf::IntRect(0, 0, 130, 130));
	run_anim.AddFrame(sf::IntRect(130, 130, 130, 130));
	run_anim.AddFrame(sf::IntRect(0, 130, 130, 130));
	run_anim.AddFrame(sf::IntRect(130, 130, 130, 130));*/
	
	walkingAnimationDown.AddFrame(sf::IntRect(32, 0, 32, 32));
	walkingAnimationDown.AddFrame(sf::IntRect(64, 0, 32, 32));
	walkingAnimationDown.AddFrame(sf::IntRect(32, 0, 32, 32));
	walkingAnimationDown.AddFrame(sf::IntRect(0, 0, 32, 32));

	walkingAnimationRight.AddFrame(sf::IntRect(32, 64, 32, 32));
	walkingAnimationRight.AddFrame(sf::IntRect(64, 64, 32, 32));
	walkingAnimationRight.AddFrame(sf::IntRect(32, 64, 32, 32));
	walkingAnimationRight.AddFrame(sf::IntRect(0, 64, 32, 32));
	current_anim = &walkingAnimationDown;
	sf::Clock clock;
	sf::Vector2f pos(0, 0);
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
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			current_anim = &walkingAnimationRight;

		}
		else
		{
			current_anim = &walkingAnimationDown;
		}
		current_anim->Update(elapsed);
		current_anim->Draw(&window);
		window.display();
		window.clear(sf::Color::Black);
	}


	return 0;
}