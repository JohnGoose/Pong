#include "MainMenu.h"
#include "GameData.h"

#include <sstream>
#include "Constants.h"

#include <iostream>
#include "resources/Resources.h"

namespace Goose
{
	MainMenuState::MainMenuState(GameDataRef data) : _data(data)
	{

	}
	// This should be Bool
	void MainMenuState::Initialize()
	{
		std::string assetPath = Resources::getAssetPath();
		sf::Text title;
		if (!m_backgroundTex.loadFromFile(assetPath + "Background.jpg"));
			std::cerr << "Unable to load Texture" << std::endl;
		
		if (!m_playButtonTex.loadFromFile(assetPath + "PlayButton.png"));
			std::cerr << "Unable to load Texture" << std::endl;

		if (!m_font.loadFromFile(assetPath + "Lavigne.ttf"));
			std::cerr << "Unable to load Font" << std::endl;

		m_background.setTexture(m_backgroundTex);
		m_playButton.setTexture(m_playButtonTex);
			

		

		//_title.setPosition((SCREEN_WIDTH / 2) -
			//(_title.getGlobalBounds().width / 2),
			//_title.getGlobalBounds().height / 2);

		m_playButton.setPosition((WindowWidth / 2) -
			(m_playButton.getGlobalBounds().width / 2),
			(WindowHeight / 2) - (m_playButton.getGlobalBounds().height / 2));
	}

	void MainMenuState::HandleInput()
	{
		sf::Event event;

		while (_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				_data->window.close();
			}
			if (_data->input.IsSpriteClicked(m_playButton, sf::Mouse::Left, _data->window))
			{

				//_data->machine.AddState(StateRef(new GameState(_data)), true);
			}
		}
	}

	void MainMenuState::Update(float dt)
	{

	}

	

	void MainMenuState::Draw(float dt)
	{
		_data->window.clear();

		sf::Text title;
		title.setFont(m_font);
		title.setString("PONG");
		title.setPosition(WindowWidth / 2 - 75, 100);
		title.setStyle(sf::Text::Bold);
		title.setCharacterSize(60);

		_data->window.draw(m_background);
		_data->window.draw(title);
		_data->window.draw(m_playButton);

		_data->window.display();
	}
}
