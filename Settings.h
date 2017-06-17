#pragma once
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include <list>

class Settings {
	public:
		sf::Texture image, tex1_0, tex1_1;
		sf::Sprite sprite, sprite1;
		enum SettingResult { Nothing, Back, Exit, Music, Difficulty, BallSpeed, BallColor, Player1Speed, Player2Speed };
		struct SettingItem {
		public:
			sf::Rect<int> rect;		
			SettingResult action;
		};

		SettingResult Show(sf::RenderWindow& window);
		
		void updateButton(int id, sf::RenderWindow& window);

	private:
		SettingResult GetMenuResponse(sf::RenderWindow& window);
		SettingResult HandleClick(int x, int y);
		std::list<SettingItem> _settingItems;

		
};
