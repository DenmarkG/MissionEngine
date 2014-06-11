#include "Rect.h"
#include "..\Collision\Bounds.h"
#include "../Vector/Vector2.h"

Rect::Rect()
{
	m_position = new Vector2();
	m_width = 1;
	m_height = 1;
}

Rect::Rect(Vector2* position)
{
	m_position = position;
	m_width = 1;
	m_height = 1;
}

Rect::Rect(Vector2* position, float width, float height)
{
	m_position = position;
	m_width = width;
	m_height = height;
}

Rect::~Rect()
{
	delete m_position;
	m_position = nullptr;
}

void Rect::SetWidth(float newWidth)
{
	m_width = newWidth;
}

void Rect::SetHeight(float newHeight)
{
	m_height = newHeight;
}

Bounds* Rect::CalculateBounds()
{
	Bounds bounds;
	Vector2 min(m_position->Get_X() - (m_width / 2), m_position->Get_Y() - (m_height / 2) );
	Vector2 max(m_position->Get_X() + (m_width / 2), m_position->Get_Y() + (m_height / 2) );
	bounds.SetMinMax(&min, &max);
	return &bounds;
}