#pragma once
#include "VisibleGameObject.h"

class Score1 :
	public VisibleGameObject {
public:
	Score1();
	~Score1();

	void Draw(sf::RenderWindow& rw);
    void goalUpd1(int score1ID);

};