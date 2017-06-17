#include "StdAfx.h"
#include "Tutorial.h"

void Tutorial::Show(sf::RenderWindow & renderWindow) {
	sf::Texture image;
	if (image.loadFromFile("images/tutorial.png") != true) {
		return;
	}

	sf::Sprite sprite(image);

	renderWindow.draw(sprite);
	renderWindow.display();

	sf::Event event;
	while (true) {
		while (renderWindow.pollEvent(event)) {
			if (event.type == sf::Event::EventType::KeyPressed
				|| event.type == sf::Event::EventType::MouseButtonPressed
				|| event.type == sf::Event::EventType::Closed) {
				return;
			}
		}
	}
}