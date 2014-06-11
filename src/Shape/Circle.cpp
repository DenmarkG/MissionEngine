#include "Circle.h"
#include "../Vector/Vector2.h"

Circle::Circle()
{
	m_position = new Vector2();
	m_radius = 1;
}

Circle::Circle(Vector2* position)
{
	m_position = position;
	m_radius = 1;
}

Circle::Circle(Vector2* position, float radius)
{
	m_position = position;
	m_radius = radius;
}

Circle::~Circle()
{
	delete m_position;
	m_position = nullptr;
}

void Circle::SetRadius()
{

}