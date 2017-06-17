#include "stdafx.h"
#include "Game.h"
#include "GameBall.h"
#include "MainMenu.h"
#include "SplashScreen.h"
#include "Tutorial.h"
#include "Settings.h"
#include "SFMLSoundProvider.h"
#include "ServiceLocator.h"

SFMLSoundProvider soundProvider;
int Game::Start()
{
	if(_gameState != Uninitialized)
		return 1;
	
	_mainWindow.create(sf::VideoMode(SCREEN_WIDTH,SCREEN_HEIGHT,32),"Hockey Fantasia");

	ServiceLocator::RegisterServiceLocator(&soundProvider);
	soundProvider.PlaySong("audio/Soundtrack.ogg",true);

	//_mainWindow.SetFramerateLimit(60);

	PlayerPaddle *player1 = new PlayerPaddle();
	player1->SetPosition((SCREEN_WIDTH/2),700);

	AIPaddle * player2 = new AIPaddle();
	player2->SetPosition((SCREEN_WIDTH/2),40);

	GameBall *ball = new GameBall();
	ball->SetPosition((SCREEN_WIDTH/2),(SCREEN_HEIGHT/2)-15);
	
	_gameObjectManager.Add("Paddle1",player1);
	_gameObjectManager.Add("Paddle2",player2);
	_gameObjectManager.Add("Ball",ball);

	_gameState= Game::ShowingSplash;


	while(!IsExiting())
	{
		GameLoop();
	}

    return 0;
}

bool Game::IsExiting()
{
	if(_gameState == Game::Exiting) 
		return true;
	else 
		return false;
}


sf::RenderWindow& Game::GetWindow()
{
	return _mainWindow;
}

const sf::Event& Game::GetInput() 
{
	sf::Event currentEvent;
	_mainWindow.pollEvent(currentEvent);
	return currentEvent;
}

const GameObjectManager& Game::GetGameObjectManager()
{
	return Game::_gameObjectManager;
}

void Game::GameLoop()
{
	sf::Event currentEvent;
	_mainWindow.pollEvent(currentEvent);
	
	
	switch(_gameState)
	{
		case Game::ShowingMenu:
			{
				ShowMenu();
				break;
			}
		case Game::ShowingSplash:
			{
				ShowSplashScreen();
				break;
			}
		case Game::SetGame: 
			{
				ShowSetting();
				break;
			}
		case Game::OpenTutorial:
			{
				ShowTutorial();
				break;
			}
		case Game::Playing:
			{
				_mainWindow.clear(sf::Color(0,0,0));

				_gameObjectManager.UpdateAll();
				_gameObjectManager.DrawAll(_mainWindow);

				_mainWindow.display();
				if(currentEvent.type == sf::Event::Closed) _gameState = Game::Exiting;

				if(currentEvent.type == sf::Event::KeyPressed)
					{
						if(currentEvent.key.code == sf::Keyboard::Escape) ShowMenu();
					}

				break;
			}
	}
}

void Game::ShowSplashScreen()
{
	SplashScreen splashScreen;
	splashScreen.Show(_mainWindow);
	_gameState = Game::ShowingMenu;
}


void Game::ShowTutorial() 
{
	Tutorial tutorialPage;
	tutorialPage.Show(_mainWindow);
	_gameState = Game::ShowingMenu;
}


void Game::ShowSetting() {
	Settings settingPage;
	Settings::SettingResult result = settingPage.Show(_mainWindow);
	switch (result) {
	case Settings::Exit:
		_gameState = Exiting;
		break;
	case Settings::Back:
		_gameState = ShowingMenu;
		ServiceLocator::GetAudio()->PlaySound("audio/kaboom.wav");
		break;
	case Settings::Music:
		//do something
		ServiceLocator::GetAudio()->PlaySound("audio/blip.wav");
		soundProvider.ToggleSounds();
		settingPage.updateButton(1, _mainWindow);
		
		break;
	case Settings::Difficulty:
		//do something
		ServiceLocator::GetAudio()->PlaySound("audio/blip.wav");
		break;
	case Settings::BallSpeed:
		//do something
		ServiceLocator::GetAudio()->PlaySound("audio/blip.wav");
		break;
	case Settings::BallColor:
		//do something
		ServiceLocator::GetAudio()->PlaySound("audio/blip.wav");
		break;
	case Settings::Player1Speed:
		//do something
		ServiceLocator::GetAudio()->PlaySound("audio/blip.wav");
		break;
	case Settings::Player2Speed:
		//do something
		ServiceLocator::GetAudio()->PlaySound("audio/blip.wav");
		break;
	}
}

void Game::ShowMenu()
{
	MainMenu mainMenu;
	MainMenu::MenuResult result = mainMenu.Show(_mainWindow);
	switch(result)
	{
		case MainMenu::Exit:
			ServiceLocator::GetAudio()->PlaySound("audio/blip.wav");
			_gameState = Exiting;
			break;
		case MainMenu::Play:
			ServiceLocator::GetAudio()->PlaySound("audio/blip.wav");
			_gameState = Playing;
			break;
		case MainMenu::Tutorial:
			ServiceLocator::GetAudio()->PlaySound("audio/blip.wav");
			_gameState = OpenTutorial;
			break;
		case MainMenu::Setting:
			ServiceLocator::GetAudio()->PlaySound("audio/blip.wav");
			_gameState = SetGame;
			break;
	}
}

Game::GameState Game::_gameState = Uninitialized;
sf::RenderWindow Game::_mainWindow;
GameObjectManager Game::_gameObjectManager;