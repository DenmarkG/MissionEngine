#pragma once

#include "..\..\GameObject\Pawn.h"

class Vector2;

class Kamikaze : public Pawn
{
public:
	Kamikaze();
	Kamikaze(float x, float y);
	~Kamikaze();

	Vector2* GetDirection() const { return m_direction; };
	
	//inherited virtual functions
	virtual void Update();
	virtual void Move(Vector2* direction);
	virtual void Draw();
	virtual void OnTriggerEnter(Collider* other);

private:
	Vector2* m_direction;
};