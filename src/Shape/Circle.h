#include "Shape.h"

class Vector2;

class Circle : public Shape
{
public:
	//constructors
	//creates a unit circle at the origin
	Circle(); 
	//creates a unit circle at the specified position
	Circle(Vector2* position);
	//creates a circle with the specified radius and position
	Circle(Vector2* position, float radius); 
	~Circle();

	//getters/setters
	float GetRadius() const { return m_radius; }
	void SetRadius();

private:
	float m_radius;
};