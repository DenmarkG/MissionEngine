#pragma once

#include "Actor2D.h"

class Pawn : public Actor2D
{
public:
	Pawn();
	~Pawn();
	float GetMoveSpeed() const { return m_moveSpeed; }
	void SetMoveSpeed(float speed);

	//inherited
	virtual void Draw();
	virtual void Update();

	virtual void Move(Vector2* direction);

protected:
	float m_moveSpeed;
};