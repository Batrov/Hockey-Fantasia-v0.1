#include "StdAfx.h"
#include "PlayerPaddle2.h"
#include "Game.h"


PlayerPaddle2::PlayerPaddle2() :
	_velocity(0),
	_maxVelocity(400.0f)
{
	Load("images/paddle.png");
	assert(IsLoaded());

	GetSprite().setOrigin(GetSprite().getLocalBounds().width / 2, GetSprite().getLocalBounds().height / 2);

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

void PlayerPaddle2::Update(float elapsedTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		_fast = 2;
	}
	else
	{
		_fast = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !maxLeft)
	{
		_velocity = -200.0f * _fast;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !maxRight)
	{
		_velocity = 200.0f * _fast;
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