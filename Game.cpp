#include "stdafx.h"
#include "Game.h"
#include "GameBall.h"
#include "MainMenu.h"
#include "SplashScreen.h"
#include "Tutorial.h"
#include "Settings.h"
#include "SFMLSoundProvider.h"
#include "ServiceLocator.h"

sf::SoundBuffer bufferBlip, bufferKaboom;
sf::Sound blip, kaboom;
/*buffer.loadFromFile("audio/blip.wav");
blip.setBuffer(buffer);
blip.play();
buffer.loadFromFile("audio/kaboom.wav");
kaboom.setBuffer(buffer);
kaboom.play();
buffer.loadFromFile("audio/goal.wav");
goal.setBuffer(buffer);
goal.play();*/

SFMLSoundProvider soundProvider;
float ballveloID = 1;
int ply1veloModID = 1;
int ply2veloModID = 1;
int ballColorID = 0;
int sclPadID = 1;

int Game::scoreP1 = 0;
int Game::scoreP2 = 0;
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
	player1->sclPad1(sclPadID);

	Score1 *score1 = new Score1();
	score1->SetPosition((SCREEN_WIDTH * 25/100), 600);

	PlayerPaddle2 * player2 = new PlayerPaddle2();
	player2->SetPosition((SCREEN_WIDTH/2),40);
	player2->sclPad2(sclPadID);

	Score2 *score2 = new Score2();
	score2->SetPosition((SCREEN_WIDTH * 75/100), 140);

	GameBall *ball = new GameBall();
	ball->SetPosition((SCREEN_WIDTH/2),(SCREEN_HEIGHT/2)-15);
	
	bufferBlip.loadFromFile("audio/blip.wav");
	blip.setBuffer(bufferBlip);
	bufferKaboom.loadFromFile("audio/kaboom.wav");
	kaboom.setBuffer(bufferKaboom);

	_gameObjectManager.Add("Paddle1",player1);
	_gameObjectManager.Add("Score1", score1);
	_gameObjectManager.Add("Paddle2",player2);
	_gameObjectManager.Add("Score2", score2);
	_gameObjectManager.Add("Ball",ball);

	_gameState= Game::ShowingSplash;


	while(!IsExiting())
	{
		score1->goalUpd1(scoreP1);
		score2->goalUpd2(scoreP2);
		player1->updPlyVelo(ply1veloModID);
		player2->updPlyVelo(ply2veloModID);
		ball->updVelo(ballveloID);
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
			_mainWindow.clear(sf::Color(0, 0, 0));
			if (scoreP1 == 7) {
				sf::Texture image;
				image.loadFromFile("images/arena1.png");
				sf::Sprite sprite(image);
				_mainWindow.draw(sprite);
			}
			else if (scoreP2 == 7) {
				sf::Texture image;
				image.loadFromFile("images/arena2.png");
				sf::Sprite sprite(image);
				_mainWindow.draw(sprite);
			}
			else{
				sf::Texture image;
				image.loadFromFile("images/arena.png");
				sf::Sprite sprite(image);
				_mainWindow.draw(sprite);
				_gameObjectManager.UpdateAll();
			}
			_gameObjectManager.DrawAll(_mainWindow, ballColorID);
			_mainWindow.display();
			if(currentEvent.type == sf::Event::KeyPressed)
				{
				if (currentEvent.key.code == sf::Keyboard::Escape) { 
					_gameObjectManager.Remove("Paddle1");
					_gameObjectManager.Remove("Paddle2");
					_gameObjectManager.Remove("Ball");
						_gameState = Game::ShowingMenu; 
						PlayerPaddle *player1 = new PlayerPaddle();
						player1->SetPosition((SCREEN_WIDTH / 2), 700);

						PlayerPaddle2 * player2 = new PlayerPaddle2();
						player2->SetPosition((SCREEN_WIDTH / 2), 40);

						GameBall *ball = new GameBall();
						ball->SetPosition((SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 2) - 15);

						scoreP1 = 0;
						scoreP2 = 0;

						_gameObjectManager.Add("Paddle1", player1);
						_gameObjectManager.Add("Paddle2", player2);
						_gameObjectManager.Add("Ball", ball);
					}
				}
			break;
			}
	}
	_mainWindow.clear();
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
		kaboom.play();
		break;
	case Settings::Music:
		//do something
		blip.play();
		soundProvider.ToggleSounds();
		settingPage.updateButton(1);
		break;
	case Settings::Difficulty:
		//do something
		blip.play();
		settingPage.updateButton(2);
		if (sclPadID == 0) {
			sclPadID = 1;
		}
		else if (sclPadID == 1) {
			sclPadID = 2;
		}
		else if (sclPadID == 2) {
			sclPadID = 0;
		}
		break;

	case Settings::BallSpeed:
		//do something
		blip.play();
		settingPage.updateButton(3);
		if (ballveloID == 0) {
			ballveloID = 1;
		}
		else if (ballveloID == 1) {
			ballveloID = 2;
		}
		else if (ballveloID == 2) {
			ballveloID = 0;
		}

		break;
	case Settings::BallColor:
		//do something
		blip.play();
		settingPage.updateButton(4);
		ballColorID++;
		break;
	case Settings::Player1Speed:
		//do something
		blip.play();
		settingPage.updateButton(5);
		if (ply1veloModID == 0) {
			ply1veloModID = 1;
		}
		else if (ply1veloModID == 1) {
			ply1veloModID = 2;
		}
		else if (ply1veloModID == 2) {
			ply1veloModID = 0;
		}

		break;
	case Settings::Player2Speed:
		//do something
		blip.play();
		settingPage.updateButton(6);
		if (ply2veloModID == 0) {
			ply2veloModID = 1;
		}
		else if (ply2veloModID == 1) {
			ply2veloModID = 2;
		}
		else if (ply2veloModID == 2) {
			ply2veloModID = 0;
		}

		break;
	}
	_gameObjectManager.Remove("Paddle1");
	_gameObjectManager.Remove("Paddle2");
	PlayerPaddle *player1 = new PlayerPaddle();
	player1->SetPosition((SCREEN_WIDTH / 2), 700);

	PlayerPaddle2 * player2 = new PlayerPaddle2();
	player2->SetPosition((SCREEN_WIDTH / 2), 40);


	player1->sclPad1(sclPadID);
	player2->sclPad2(sclPadID);

	_gameObjectManager.Add("Paddle1", player1);
	_gameObjectManager.Add("Paddle2", player2);
}

void Game::ShowMenu()
{
	MainMenu mainMenu;
	MainMenu::MenuResult result = mainMenu.Show(_mainWindow);
	switch(result)
	{
		case MainMenu::Exit:
			blip.play(); 
			_gameState = Exiting;
			break;
		case MainMenu::Play:
			blip.play(); 
			_gameState = Playing;
			break;
		case MainMenu::Tutorial:
			blip.play(); 
			_gameState = OpenTutorial;
			break;
		case MainMenu::Setting:
			blip.play(); 
			_gameState = SetGame;
			break;
	}
}

Game::GameState Game::_gameState = Uninitialized;
sf::RenderWindow Game::_mainWindow;
GameObjectManager Game::_gameObjectManager;