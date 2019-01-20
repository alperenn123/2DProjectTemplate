#include <animation/animation.h>

namespace Game {
	namespace Animation {

		void Init(sAnimation* animation)
		{
			if (animation->m_Sprite_Sheet != NULL)
			{
				animation->m_object.setTexture(*(animation->m_Sprite_Sheet));
			}
			else
			{
				std::cout << "Couldnt set texture to Sprite inside Animation init" << std::endl;
			}
			animation->m_frame_count = 0;
			animation->m_frame_index = 0;
		}
		
		void AddFrames(Frame* frames, uint8 frame_count, sAnimation* animation)
		{
			uint8 index = 0;
			uint8 addr_step = sizeof(frames);
			for (index = 0; index < frame_count - 1; index++)
			{
				animation->m_frames.push_back(*frames);
				frames += 1;
			}
		}
		void Update(sf::Time elapsed, sAnimation* animation)
		{
			uint8 frame_index = animation->m_frame_index;
			
			animation->m_frame_count = animation->m_frames.size();
			animation->m_frames.at(frame_index).m_frame_start_time += elapsed.asSeconds();
			
			if (animation->m_frames.at(frame_index).m_frame_start_time >= animation->m_frames.at(frame_index).m_frame_duration)
			{
				animation->m_frames.at(frame_index).m_frame_start_time = 0.0f;

				animation->m_object.setTextureRect(animation->m_frames.at(frame_index).rect);

				frame_index = (frame_index + 1) % animation->m_frame_count;
				animation->m_frame_index = frame_index;
			}

		
		}

		void SetSpriteSheet(sf::Texture* sprite_sheet,sAnimation* animation)
		{
			animation->m_Sprite_Sheet = sprite_sheet;
		}
		
	}
}
	

