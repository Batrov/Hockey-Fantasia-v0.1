#include "stdafx.h"
#include "Settings.h"
#include "VisibleGameObject.h"
#include "ServiceLocator.h"
bool musicOn = true;
int diffLevel = 1;
int ballSpdLevel = 1;
int ballClrID = 0;
int player1SpdID = 1;
int player2SpdID = 1;


void Settings::updateButton(int id) {
	switch (id) {
	case 1:
		musicOn = !musicOn;
		break;
	case 2:
		diffLevel++;
		if (diffLevel == 3) {
			diffLevel = 0;
		}
		break;
	case 3:
		ballSpdLevel++;
		if (ballSpdLevel == 3) {
			ballSpdLevel = 0;
		}
		break;
	case 4:
		ballClrID++;
		if (ballClrID == 3) {
			ballClrID = 0;
		}
		break;
	case 5:
		player1SpdID++;
		if (player1SpdID == 3) {
			player1SpdID = 0;
		}
		break;
	case 6:
		player2SpdID++;
		if (player2SpdID == 3) {
			player2SpdID = 0;
		}
		break;
	}
}

Settings::SettingResult Settings::Show(sf::RenderWindow& window) {

	//Load menu image from file
	image.loadFromFile("images/setting.png");
	sprite.setTexture(image);

	tex1_0.loadFromFile("images/buttons/btn1_0.png");
	tex1_1.loadFromFile("images/buttons/btn1_1.png");

	tex2_0.loadFromFile("images/buttons/btn2_0.png");
	tex2_1.loadFromFile("images/buttons/btn2_1.png");
	tex2_2.loadFromFile("images/buttons/btn2_2.png");

	tex3_0.loadFromFile("images/buttons/btn3_0.png");
	tex3_1.loadFromFile("images/buttons/btn3_1.png");
	tex3_2.loadFromFile("images/buttons/btn3_2.png");

	tex4_0.loadFromFile("images/buttons/btn4_0.png");
	tex4_1.loadFromFile("images/buttons/btn4_1.png");
	tex4_2.loadFromFile("images/buttons/btn4_2.png");

	tex5_0.loadFromFile("images/buttons/btn5_0.png");
	tex5_1.loadFromFile("images/buttons/btn5_1.png");
	tex5_2.loadFromFile("images/buttons/btn5_2.png");


	
	if (musicOn)	{sprite1.setTexture(tex1_1);}
	else			{sprite1.setTexture(tex1_0);}
	sprite1.setPosition(550, 160);


	switch (diffLevel) {
	case 0:
		sprite2.setTexture(tex2_0);
		break;
	case 1:
		sprite2.setTexture(tex2_1);
		break;
	case 2:
		sprite2.setTexture(tex2_2);
		break;
	}
	sprite2.setPosition(550, 275);

	switch (ballSpdLevel) {
	case 0:
		sprite3.setTexture(tex3_0);
		break;
	case 1:
		sprite3.setTexture(tex3_1);
		break;
	case 2:
		sprite3.setTexture(tex3_2);
		break;
	}
	sprite3.setPosition(550, 390);

	switch (ballClrID) {
	case 0:
		sprite4.setTexture(tex4_0);
		break;
	case 1:
		sprite4.setTexture(tex4_1);
		break;
	case 2:
		sprite4.setTexture(tex4_2);
		break;
	}
	sprite4.setPosition(550, 505);

	switch (player1SpdID) {
	case 0:
		sprite5.setTexture(tex5_0);
		break;
	case 1:
		sprite5.setTexture(tex5_1);
		break;
	case 2:
		sprite5.setTexture(tex5_2);
		break;
	}
	sprite5.setPosition(550, 620);

	switch (player2SpdID) {
	case 0:
		sprite6.setTexture(tex5_0);
		break;
	case 1:
		sprite6.setTexture(tex5_1);
		break;
	case 2:
		sprite6.setTexture(tex5_2);
		break;
	}
	sprite6.setPosition(550, 690);


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
	window.draw(sprite1);
	window.draw(sprite2);
	window.draw(sprite3);
	window.draw(sprite4);
	window.draw(sprite5);
	window.draw(sprite6);

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

