#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "PlayerPaddle.h"
#include "AIPaddle.h"
#include "GameBall.h"
#include "GameObjectManager.h"

class Game
{
public:
	static int Start();
	static sf::RenderWindow& GetWindow();
	const static sf::Event& GetInput();
	const static GameObjectManager& GetGameObjectManager();

	const static int SCREEN_WIDTH = 1024;
	const static int SCREEN_HEIGHT = 768;

private:
	static bool IsExiting();
	static void GameLoop();
	
	static void ShowSplashScreen();
	static void ShowMenu();
	static void ShowSetting();
	static void ShowTutorial();

	enum GameState { Uninitialized, ShowingSplash, Paused, 
					ShowingMenu, Playing, Exiting, SetGame, OpenTutorial };

	static GameState _gameState;
	static sf::RenderWindow _mainWindow;
	
	static GameObjectManager _gameObjectManager;
};
