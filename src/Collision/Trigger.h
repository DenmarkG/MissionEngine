#pragma once 
#include "Collider.h"

class GameObject;

class Trigger : public Collider
{
public:
	Trigger();
	Trigger(GameObject* owner, float size);
	~Trigger();

	virtual void HandleCollision(Collider* other);
};