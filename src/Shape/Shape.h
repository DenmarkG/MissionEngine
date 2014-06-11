#pragma once

class Vector2;
class Collider;
class Bounds;

class Shape
{
public:
	Vector2* GetPosition() const { return m_position; };

	virtual Bounds* CalculateBounds() = 0;

protected:
	Vector2* m_position;
};