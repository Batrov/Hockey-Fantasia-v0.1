#include "StdAfx.h"
#include "Score2.h"
#include "Game.h"

int score2 = 0;

Score2::Score2() {
	Load("images/numbers/num0.png");
	assert(IsLoaded());

	GetSprite().setOrigin(GetSprite().getLocalBounds().width / 2, GetSprite().getLocalBounds().height / 2);
}


Score2::~Score2() {

}

void Score2::Draw(sf::RenderWindow & rw) {
	VisibleGameObject::Draw(rw);
}

void Score2::goalUpd2(int score2ID) {
	switch (score2ID) {
	case 0:
		Load("images/numbers/num0.png");
		break;
	case 1:
		Load("images/numbers/num1.png");
		break;
	case 2:
		Load("images/numbers/num2.png");
		break;
	case 3:
		Load("images/numbers/num3.png");
		break;
	case 4:
		Load("images/numbers/num4.png");
		break;
	case 5:
		Load("images/numbers/num5.png");
		break;
	case 6:
		Load("images/numbers/num6.png");
		break;
	case 7:
		Load("images/numbers/num7.png");
		break;
	}
}


