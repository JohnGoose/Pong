#include "SplashState.h"
#include "Constants.h"
#include <sstream>
#include "resources/Resources.h"
#include <iostream>
#include "MainMenu.h"

namespace Goose
{
	SplashState::SplashState(GameDataRef data) : _data(data)
	{

	}

	void SplashState::Initialize()
	{
		std::string assetPath = Resources::getAssetPath();

		if (!m_tex.loadFromFile(assetPath + "Supercell.jpg"));
			std::cerr << "Unable to load Texture" << std::endl;

		m_sprite.setTexture(m_tex);
		m_sprite.setPosition((WindowWidth - m_sprite.getGlobalBounds().width) / 2.f,
			(WindowHeight - m_sprite.getGlobalBounds().height) / 2.f);
	}

	void SplashState::HandleInput()
	{
		sf::Event event;

		while (_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				_data->window.close();
			}
		}
	}

	void SplashState::Update(float dt)
	{
		if (_clock.getElapsedTime().asSeconds() > SplashStateTimer)
		{
			_data->machine.AddState(StateRef(new MainMenuState(_data)), true);
			// std::cout << "Main Menu" << std::endl;
		}
	}

	void SplashState::Draw(float dt)
	{
		sf::RectangleShape backgroundFill(sf::Vector2f(WindowWidth, WindowHeight));
		backgroundFill.setFillColor(sf::Color::Black);

		_data->window.clear();

		_data->window.draw(backgroundFill);
		_data->window.draw(m_sprite);

		_data->window.display();
	}


}