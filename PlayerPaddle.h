#pragma once
#include "VisibleGameObject.h"

class PlayerPaddle :
	public VisibleGameObject
{
public:
	PlayerPaddle();
	~PlayerPaddle();

	void Update(float elapsedTime);
    void Draw(sf::RenderWindow& rw);
    
    float GetVelocity() const;
	void updPlyVelo(int modID);

private:
    float _velocity;  // -- left ++ right
    float _maxVelocity;
	int _fast = 1;
	bool maxLeft = false, maxRight = false;
};