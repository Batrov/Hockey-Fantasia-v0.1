#include "stdafx.h"
#include "Settings.h"
#include "VisibleGameObject.h"
#include "ServiceLocator.h"

void Settings::updateButton(int id, sf::RenderWindow & window) {
	window.clear(sf::Color(0, 0, 0));
	if (id == 1) {
		tex1_0.loadFromFile("images/buttons/btn1_0.png");
		sprite1.setTexture(tex1_0);
		sprite1.move(1,1);
	}
	window.draw(sprite);
	window.draw(sprite1);
	window.display();
}

Settings::SettingResult Settings::Show(sf::RenderWindow& window) {

	//Load menu image from file
	image.loadFromFile("images/setting.png");
	sprite.setTexture(image);

	tex1_0.loadFromFile("images/buttons/btn1_0.png");
//	sprite1.setTexture(tex1_0);
	sprite1.setPosition(550, 160);

	//Setup clickable regions

	//Play menu item coordinates
	SettingItem backButton;
	backButton.rect.height = 150; //ini seharusnya width
	backButton.rect.left = 50;
	backButton.rect.top = 25;
	backButton.rect.width = 125; //ini seharusnya height
	backButton.action = Back;


	SettingItem musicButton;
	musicButton.rect.height = 1000; //ini seharusnya width
	musicButton.rect.left = 550;
	musicButton.rect.top = 160;
	musicButton.rect.width = 250; //ini seharusnya height
	musicButton.action = Music;

	SettingItem difficultyButton;
	difficultyButton.rect.height = 1000; //ini seharusnya width
	difficultyButton.rect.left = 550;
	difficultyButton.rect.top = 275;
	difficultyButton.rect.width = 365; //ini seharusnya height
	difficultyButton.action = Difficulty;

	SettingItem ballSpdButton;
	ballSpdButton.rect.height = 1000; //ini seharusnya width
	ballSpdButton.rect.left = 550;
	ballSpdButton.rect.top = 390;
	ballSpdButton.rect.width = 480; //ini seharusnya height
	ballSpdButton.action = BallSpeed;

	SettingItem ballClrButton;
	ballClrButton.rect.height = 1000; //ini seharusnya width
	ballClrButton.rect.left = 550;
	ballClrButton.rect.top = 505;
	ballClrButton.rect.width = 595; //ini seharusnya height
	ballClrButton.action = BallColor;

	SettingItem spd1Button;
	spd1Button.rect.height = 1000; //ini seharusnya width
	spd1Button.rect.left = 550;
	spd1Button.rect.top = 620;
	spd1Button.rect.width = 690; //ini seharusnya height
	spd1Button.action = Player1Speed;

	SettingItem spd2Button;
	spd2Button.rect.height = 1000; //ini seharusnya width
	spd2Button.rect.left = 550;
	spd2Button.rect.top = 690;
	spd2Button.rect.width = 770; //ini seharusnya height
	spd2Button.action = Player2Speed;
	
	_settingItems.push_back(backButton);
	_settingItems.push_back(musicButton);
	_settingItems.push_back(difficultyButton);
	_settingItems.push_back(ballSpdButton);
	_settingItems.push_back(ballClrButton);
	_settingItems.push_back(spd1Button);
	_settingItems.push_back(spd2Button);

	window.draw(sprite);
	window.display();

	return GetMenuResponse(window);
}



Settings::SettingResult Settings::HandleClick(int x, int y) {
	std::list<SettingItem>::iterator it;

	for (it = _settingItems.begin(); it != _settingItems.end(); it++) {
		sf::Rect<int> settingItemRect = (*it).rect;
		if (settingItemRect.width > y
			&& settingItemRect.top < y
			&& settingItemRect.left < x
			&& settingItemRect.height > x) {
			return (*it).action;
		}
	}

	return Nothing;
}

Settings::SettingResult  Settings::GetMenuResponse(sf::RenderWindow& window) {
	sf::Event settingEvent;

	while (42 != 43) {

		while (window.pollEvent(settingEvent)) {
			if (settingEvent.type == sf::Event::MouseButtonPressed) {
				if (ServiceLocator::GetAudio()->IsSongPlaying())
				//	ServiceLocator::GetAudio()->StopAllSounds();

				return HandleClick(settingEvent.mouseButton.x, settingEvent.mouseButton.y);
			}
			if (settingEvent.type == sf::Event::Closed) {
				return Exit;
			}
		}
	}
}

