#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <string>
#include "InputManager.h"
#include "AssetManager.h"
#include "StateManager.h"


namespace Goose
{
	struct GameStruct
	{
		StateManager machine;
		sf::RenderWindow window;
		AssetManager assets;
		InputManager input;
	};

	typedef std::shared_ptr<GameStruct>GameDataRef;

	class GameData
	{
	public:
		GameData(int width, int height, std::string title);


	private:
		const float dt = 1.0f / 60.0f;
		sf::Clock _clock;

		GameDataRef _data = std::make_shared<GameStruct>();

		void Run();
	};
}
