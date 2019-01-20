#pragma once
#include <SFML/Graphics.hpp>
#include "renderer/Renderer.h"
#include "types/Types.h"
namespace Renderer {


	typedef struct {
		char* m_window_title;
		uint16 m_screen_width;
		uint16 m_screen_height;
		sf::RenderWindow m_MainWindow;
		std::vector<sf::Sprite> m_game_objects;
	}sRenderer;


	void
	InitializeRenderer(uint16* screen_width, uint16* screen_height, char* window_title);
	void
	PushGameObject( sf::Sprite &game_object);
	void
	RenderWindow(const sf::Sprite& s1);
}