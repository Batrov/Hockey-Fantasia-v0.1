#include "StdAfx.h"
#include "PlayerPaddle2.h"
#include "Game.h"

float veloRange2 = 200;
float scalePad2 = 1;

PlayerPaddle2::PlayerPaddle2() :
	_velocity(0),
	_maxVelocity(400.0f)
{
	Load("images/paddle.png");
	assert(IsLoaded());

	GetSprite().setOrigin(GetSprite().getLocalBounds().width / 2, GetSprite().getLocalBounds().height / 2);
	GetSprite().scale(scalePad2,1);
}


PlayerPaddle2::~PlayerPaddle2()
{
}

void PlayerPaddle2::Draw(sf::RenderWindow & rw)
{
	VisibleGameObject::Draw(rw);
}

float PlayerPaddle2::GetVelocity() const
{
	return _velocity;
}

void PlayerPaddle2::updPlyVelo(int modID) {
	if (modID == 0) {
		veloRange2 = 200.0f;
	}
	else if (modID == 1) {
		veloRange2 = 400.0f;
	}
	else if (modID == 2) {
		veloRange2 = 1000.0f;
	}
	_maxVelocity = veloRange2 * 2;
}

void PlayerPaddle2::sclPad2(int modID) {
	if (modID == 0) {
		scalePad2 = 2;
	}
	else if (modID == 1) {
		scalePad2 = 1;
	}
	else if (modID == 2) {
		scalePad2 = 0.5;
	}
	GetSprite().scale(scalePad2, 1);
}

void PlayerPaddle2::Update(float elapsedTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		_fast = 2;
	}
	else
	{
		_fast = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !maxLeft)
	{
		_velocity = -veloRange2 * _fast;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !maxRight)
	{
		_velocity = veloRange2 * _fast;
	}
	else
	{
		_velocity = 0.0f;
	}

	if (_velocity > _maxVelocity)
		_velocity = _maxVelocity;

	if (_velocity < -_maxVelocity)
		_velocity = -_maxVelocity;


	sf::Vector2f pos = this->GetPosition();

	if (pos.x  < GetSprite().getLocalBounds().width / 2)
	{
		maxLeft = true;
	}
	else {
		maxLeft = false;
	}
	if (pos.x >(Game::SCREEN_WIDTH - GetSprite().getLocalBounds().width / 2)) {
		maxRight = true;
	}
	else {
		maxRight = false;
	}
	GetSprite().move(_velocity * elapsedTime, 0);
}