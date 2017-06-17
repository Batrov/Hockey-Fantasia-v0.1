#include "stdafx.h"
#include "MainMenu.h"
#include "ServiceLocator.h"

MainMenu::MenuResult MainMenu::Show(sf::RenderWindow& window)
{

	//Load menu image from file
	sf::Texture image;
	image.loadFromFile("images/Mainmenu.png");
	sf::Sprite sprite(image);

	//Setup clickable regions

	//Play menu item coordinates
	MenuItem playButton;
	playButton.rect.height = 725; //ini seharusnya width
	playButton.rect.left = 300;
	playButton.rect.top= 300;
	playButton.rect.width = 390; //ini seharusnya height
	playButton.action = Play;

	MenuItem tutorialButton;
	tutorialButton.rect.height = 725; //ini seharusnya width, tdk usah diubah
	tutorialButton.rect.left = 300; //tdk usah diubah
	tutorialButton.rect.top = 415;
	tutorialButton.rect.width = 505; //ini seharusnya height
	tutorialButton.action = Tutorial; //enum di MainMenu.h

	MenuItem settingButton;
	settingButton.rect.height = 725; //ini seharusnya width, tdk usah diubah
	settingButton.rect.left = 300; //tdk usah diubah
	settingButton.rect.top = 530;
	settingButton.rect.width = 620; //ini seharusnya height
	settingButton.action = Setting; //enum di MainMenu.h

	//Exit menu item coordinates
	MenuItem exitButton;
	exitButton.rect.height = 725;
	exitButton.rect.left = 300;
	exitButton.rect.top = 645;
	exitButton.rect.width = 735;
	exitButton.action = Exit;

	_menuItems.push_back(playButton);
	_menuItems.push_back(tutorialButton);
	_menuItems.push_back(settingButton);
	_menuItems.push_back(exitButton);

	window.draw(sprite);
	window.display();

	return GetMenuResponse(window);
}

MainMenu::MenuResult MainMenu::HandleClick(int x, int y)
{
	std::list<MenuItem>::iterator it;

	for ( it = _menuItems.begin(); it != _menuItems.end(); it++)
	{
		sf::Rect<int> menuItemRect = (*it).rect;
		if( menuItemRect.width > y 
			&& menuItemRect.top < y 
			&& menuItemRect.left < x 
			&& menuItemRect.height > x)
			{
				return (*it).action;
			}
	}

	return Nothing;
}

MainMenu::MenuResult  MainMenu::GetMenuResponse(sf::RenderWindow& window)
{
	sf::Event menuEvent;

	while(42 != 43)
	{

		while(window.pollEvent(menuEvent))
		{
			if(menuEvent.type == sf::Event::MouseButtonPressed)
			{
				if(ServiceLocator::GetAudio()->IsSongPlaying())
				//ServiceLocator::GetAudio()->StopAllSounds();

				return HandleClick(menuEvent.mouseButton.x,menuEvent.mouseButton.y);
			}
			if(menuEvent.type == sf::Event::Closed)
			{
				return Exit;
			}
		}
	}
}