#include "StdAfx.h"
#include "Score1.h"
#include "Game.h"

int score1 = 0;

Score1::Score1()
{
	Load("images/numbers/num0.png");
	assert(IsLoaded());

	GetSprite().setOrigin(GetSprite().getLocalBounds().width / 2, GetSprite().getLocalBounds().height / 2);
}


Score1::~Score1() {
	
}

void Score1::Draw(sf::RenderWindow & rw) {
	VisibleGameObject::Draw(rw);
}

void Score1::goalUpd1(int score1ID) {
	switch (score1ID) {
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


