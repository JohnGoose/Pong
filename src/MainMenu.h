#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "GameData.h"

namespace Goose
{
	class MainMenuState : public State
	{
	public:
		MainMenuState(GameDataRef data);

		void Initialize();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		sf::Font m_font;
		sf::Sprite m_playButton;
		sf::Sprite m_background;

		sf::Texture m_playButtonTex;
		sf::Texture m_backgroundTex;
	};
}