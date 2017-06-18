#pragma once
#include "VisibleGameObject.h"


class GameObjectManager
{
public:	
	GameObjectManager();
	~GameObjectManager();

	void Add(std::string name, VisibleGameObject* gameObject);
	void Remove(std::string name);
	void RemoveAll();
	int GetObjectCount() const;
	VisibleGameObject* Get(std::string name) const;
	
	void DrawAll(sf::RenderWindow& renderWindow, int ballColorID);
	void UpdateAll();

private:
	std::map<std::string, VisibleGameObject*> _gameObjects;

	sf::Clock clock;

	struct GameObjectDeallocator
	{
		void operator()(const std::pair<std::string,VisibleGameObject*> & p) const
		{
			delete p.second;
		}
	};
};