#pragma once
#include <SFML/Graphics.hpp>
#include "types/Types.h"
#include "renderer/Renderer.h"
#include <iostream>
namespace Game {

	namespace Animation {

		typedef struct {
			sf::IntRect rect;
			float m_frame_duration;
			float m_frame_start_time;
		}Frame;

		typedef struct
		{
			sf::Texture* m_Sprite_Sheet;
			std::vector<Frame> m_frames;
			sf::Sprite m_object;
			uint8 m_frame_index;
			uint8 m_frame_count;
		}sAnimation;

		void Init(sAnimation* animation);
		void SetSpriteSheet(sf::Texture* sprite_sheet, sAnimation* animation);
		void AddFrames(Frame* frames, uint8 frame_count, sAnimation* animation);
		void Update(sf::Time elapsed,sAnimation* animation);

	}
}