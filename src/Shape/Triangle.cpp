#include "Triangle.h"
#include "../Vector/Vector2.h"

Triangle::Triangle()
{
	m_position = new Vector2();
	m_base = 1;
	m_height = 1;
}

Triangle::Triangle(Vector2* position)
{
	m_position = position;
	m_base = 1;
	m_height = 1;
}

Triangle::Triangle(Vector2* position, float base, float height)
{
	m_position = position;
	m_base = base;
	m_height = height;
}

Triangle::~Triangle()
{
	delete m_position;
	m_position = nullptr;

	delete m_position2;
	m_position2 = nullptr;

	delete m_position3;
	m_position3 = nullptr;
}

void Triangle::SetBase(float base)
{
	m_base = base;
}

void Triangle::SetHeight(float height)
{
	m_height = height;
}

void Triangle::CalculatePoints(Vector2* v1)
{
	//option one:
	float x2 = v1->Get_X() + (.5f * m_base);
	float y2 = v1->Get_Y() - (m_height);
	m_position2 = new Vector2(x2, y2);

	float x3 = x2 - m_base;
	m_position3 = new Vector2(x3, y2);

	//option two
	//m_v2LocalOffset = m_position2 - v1;
}