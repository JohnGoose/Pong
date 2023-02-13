#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include "Game.h"
#include "resources/Resources.h"
#include <memory>
#include <iostream>
#include "GameData.h"
#include "SplashState.h"
#include "Constants.h"

int main()
{
	Goose::GameData(WindowWidth, WindowHeight, "Not Pong");

	return (0);
}