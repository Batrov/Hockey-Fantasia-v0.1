#include "StdAfx.h"
#include "PlayerPaddle.h"
#include "Game.h"

float veloRange1 = 200;
float scalePad1 = 1;

PlayerPaddle::PlayerPaddle() :
_velocity(0),
_maxVelocity(400.0f)
{
	Load("images/paddle.png");
	assert(IsLoaded());

	GetSprite().setOrigin(GetSprite().getLocalBounds().width /2, GetSprite().getLocalBounds().height / 2);
	GetSprite().scale(scalePad1, 1);
}


PlayerPaddle::~PlayerPaddle()
{
}

void PlayerPaddle::Draw(sf::RenderWindow & rw)
{
	VisibleGameObject::Draw(rw);
}

float PlayerPaddle::GetVelocity() const
{
	return _velocity;
}

void PlayerPaddle::updPlyVelo(int modID) {
	if (modID == 0) {
		veloRange1 = 200.0f;
	}
	else if (modID == 1) {
		veloRange1 = 400.0f;
	}
	else if (modID == 2) {
		veloRange1 = 1000.0f;
	}
	_maxVelocity = veloRange1 * 2;
}

void PlayerPaddle::Update(float elapsedTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		_fast = 2;
	}
	else
	{
		_fast = 1;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)&&!maxLeft)
	{
		_velocity= -veloRange1 * _fast;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)&&!maxRight)
	{
		_velocity= veloRange1 * _fast;
	}
	else
	{
		_velocity= 0.0f;
	}

	if(_velocity > _maxVelocity)
		_velocity = _maxVelocity;

	if(_velocity < -_maxVelocity)
		_velocity = -_maxVelocity;


	sf::Vector2f pos = this->GetPosition();

	if(pos.x  < GetSprite().getLocalBounds().width/2)
	{
		maxLeft = true;
	}
	else {
		maxLeft = false;
	}
	if (pos.x > (Game::SCREEN_WIDTH - GetSprite().getLocalBounds().width / 2)) {
		maxRight = true;
	}
	else {
		maxRight = false;
	}
	GetSprite().move(_velocity * elapsedTime, 0);
}