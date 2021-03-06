#pragma once
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include <list>

class Settings {
	public:
		sf::Texture image, tex1_0, tex1_1, tex2_0, tex2_1, tex2_2, tex3_0, tex3_1, tex3_2, tex4_0, tex4_1, tex4_2, tex5_0, tex5_1, tex5_2;
		sf::Sprite sprite, sprite1, sprite2, sprite3, sprite4, sprite5, sprite6;
		enum SettingResult { Nothing, Back, Exit, Music, Difficulty, BallSpeed, BallColor, Player1Speed, Player2Speed };
		struct SettingItem {
		public:
			sf::Rect<int> rect;		
			SettingResult action;
		};

		SettingResult Show(sf::RenderWindow& window);
		
		void updateButton(int id);

	private:
		SettingResult GetMenuResponse(sf::RenderWindow& window);
		SettingResult HandleClick(int x, int y);
		std::list<SettingItem> _settingItems;

		
};
