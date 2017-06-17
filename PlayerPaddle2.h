#pragma once
#include "VisibleGameObject.h"

class PlayerPaddle2 :
	public VisibleGameObject
{
public:
	PlayerPaddle2();
	~PlayerPaddle2();

	void Update(float elapsedTime);
	void Draw(sf::RenderWindow& rw);

	float GetVelocity() const;

private:
	float _velocity;  // -- left ++ right
	float _maxVelocity;
	int _fast = 1;
	bool maxLeft = false, maxRight = false;
};