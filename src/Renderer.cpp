#include "renderer/Renderer.h"
namespace Renderer {


	static sRenderer renderer;
	void
	InitializeRenderer(uint16* screen_width, uint16* screen_height, char* window_title)
	{
		renderer.m_screen_width = *screen_width;
		renderer.m_screen_height = *screen_height;
		renderer.m_window_title = window_title;

		renderer.m_MainWindow.create
		(
			sf::VideoMode(renderer.m_screen_width, renderer.m_screen_height), renderer.m_window_title
		);
	}
	void
	PushGameObject( sf::Sprite &game_object)
	{
		renderer.m_game_objects.push_back(game_object);
	}

	void
	RenderWindow(const sf::Sprite& s1)
	{
		sf::Event event;
		while (renderer.m_MainWindow.isOpen())
		{
			while (renderer.m_MainWindow.pollEvent(event))
			{
				switch (event.type)
				{
					case sf::Event::Closed: {renderer.m_MainWindow.close(); }
				}
			}
			renderer.m_MainWindow.clear(sf::Color::Black);
			if (!renderer.m_game_objects.empty())
			{
				for (auto &game_object : renderer.m_game_objects)
				{
					renderer.m_MainWindow.draw(game_object);
				}
			}

			renderer.m_MainWindow.display();
		}
	}
}