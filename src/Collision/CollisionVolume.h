#pragma once

#include "Collider.h"

class Vector2;

class CollisionVolume : public Collider
{
public:
	CollisionVolume();
	CollisionVolume(GameObject* owner, float size);
	~CollisionVolume();

	//inherited functions
	virtual void HandleCollision(Collider* other);
	virtual bool IsColliding(Collider* other) const;
};