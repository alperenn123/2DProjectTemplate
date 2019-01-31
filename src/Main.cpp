#include <FrameAnim/FrameAnimation.h>

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
	FrameAnimation walkingAnimationLeft(walk_sprite_sheet);
	FrameAnimation walkingAnimationDown(walk_sprite_sheet);
	/*run_anim.AddFrame(sf::IntRect(0, 0, 130, 130));
	run_anim.AddFrame(sf::IntRect(130, 130, 130, 130));
	run_anim.AddFrame(sf::IntRect(0, 130, 130, 130));
	run_anim.AddFrame(sf::IntRect(130, 130, 130, 130));*/
	sf::Vector2i frame_size(32,32);
	sf::Time duration = sf::seconds(0.5f);
	walkingAnimationDown.setDuration(duration);

	walkingAnimationDown.AddFrame(sf::IntRect(0, 0, 32, 32));
	walkingAnimationDown.AddFrame(sf::IntRect(32, 0, 32, 32));
	walkingAnimationDown.AddFrame(sf::IntRect(64, 0, 32, 32));

	walkingAnimationLeft.setDuration(duration);

	walkingAnimationLeft.AddFrame(sf::IntRect(0,32,32,32));
	walkingAnimationLeft.AddFrame(sf::IntRect(32,32,32,32));
	walkingAnimationLeft.AddFrame(sf::IntRect(64,32,32,32));
	
	sf::Clock clock;
	sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Vector2f pos(0, 0);
	uint8 input_flag = 0;
	while (window.isOpen())
	{
		sf::Time deltaTime = clock.restart();
		timeSinceLastUpdate += deltaTime;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
				case sf::Event::Closed: {window.close(); }
			}
		}
		window.clear(sf::Color::Black);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			walkingAnimationLeft.update(timeSinceLastUpdate, true);
			window.draw(walkingAnimationLeft);
		}
		else
		{
			walkingAnimationDown.update(timeSinceLastUpdate, true);
			window.draw(walkingAnimationDown);

		}



		window.display();
		timeSinceLastUpdate = sf::Time::Zero;
	}
	

	return 0;
}