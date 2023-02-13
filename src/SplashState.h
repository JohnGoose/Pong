#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "GameData.h"

namespace Goose
{
	class SplashState : public State
	{
	public:
		SplashState(GameDataRef data);

		void Initialize();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		sf::Clock _clock;

		sf::Sprite m_sprite;
		sf::Texture m_tex;
	};
}
