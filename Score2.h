#pragma once
#include "VisibleGameObject.h"

class Score2 :
	public VisibleGameObject {
public:
	Score2();
	~Score2();

	void Draw(sf::RenderWindow& rw);
	void goalUpd2(int score1ID);

};