#include "Bounds.h"
#include "..\Vector\Vector2.h"

Bounds::Bounds()
{
	m_size = 1;
	m_position = new Vector2();
	float halfSize = m_size / 2;

	m_max = new Vector2(halfSize, halfSize);
	m_min = new Vector2(-halfSize, -halfSize);
}

Bounds::Bounds(Vector2* position, float size)
{
	m_position = new Vector2(position->Get_X(), position->Get_Y());
	m_size = size;
	
	float halfSize = m_size / 2;

	m_max = new Vector2(m_position->Get_X() + halfSize, m_position->Get_Y() + halfSize);
	m_min = new Vector2(m_position->Get_X() - halfSize, m_position->Get_Y() - halfSize);
}

Bounds::~Bounds()
{
	delete m_max;
	m_max = nullptr;

	delete m_min;
	m_min = nullptr;

	delete m_position;
	m_position = nullptr;
}

void Bounds::SetMinMax(Vector2* min, Vector2* max)
{
	m_min->Set_X(min->Get_X());
	m_min->Set_Y(min->Get_Y());

	m_max->Set_X(max->Get_X());
	m_max->Set_Y(max->Get_Y());
}

void Bounds::UpdateBounds(Vector2* position)
{
	m_position->Set_X(position->Get_X());
	m_position->Set_Y(position->Get_Y());
	UpdateMax();
	UpdateMin();
}

void Bounds::UpdateMax()
{
	float halfSize = m_size / 2;
	m_max->Set_X(m_position->Get_X() + halfSize);
	m_max->Set_Y(m_position->Get_Y() + halfSize);
}

void Bounds::UpdateMin()
{
	float halfSize = m_size / 2;
	m_min->Set_X(m_position->Get_X() - halfSize);
	m_min->Set_Y(m_position->Get_Y() - halfSize);

}