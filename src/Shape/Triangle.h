#include "Shape.h"

class Vector2;

class Triangle : public Shape
{
public:
	//constructors
	Triangle();
	Triangle(Vector2* position);
	Triangle(Vector2* position, float base, float height);
	~Triangle();

	//getters
	float GetBase() const { return m_base; };
	float GetHeight() const { return m_height; };

	//setters
	void SetBase(float base);
	void SetHeight(float height);

private:
	Vector2* m_position2;
	Vector2* m_position3;

	Vector2* m_v2LocalOffset;
	Vector2* m_v3LocalOffset;

	float m_base;
	float m_height;

	void CalculatePoints(Vector2* v1);
};