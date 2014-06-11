#pragma once

#include <list>

class GameObject;
class Vector2;

class Scene
{
public:
	virtual std::list<GameObject*>* LoadScene() = 0;
	Vector2* GetPlayerSpawnPos() const { return m_playerSpawn; };


protected:
	std::list<GameObject*> m_allObjects;
	Vector2* m_playerSpawn;
};

