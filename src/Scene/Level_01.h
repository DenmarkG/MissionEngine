#pragma once
#include <list>
#include"Scene.h"

class GameObject;

class Level_01 : public Scene
{
public:
	Level_01();
	~Level_01();

	virtual std::list<GameObject*>* LoadScene();
};