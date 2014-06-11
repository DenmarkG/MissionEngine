#include "Trigger.h"
#include "..\GameObject\GameObject.h"
#include "Collider.h"
#include "Bounds.h"
#include "..\Shape\Rect.h"
#include "..\Vector\Vector2.h"

#include <iostream>
#include <math.h>

Trigger::Trigger()
{
	//obligatory default constructor
}

Trigger::Trigger(GameObject* owner, float size)
{
	if (owner)
	{
		m_gameObject = owner;
		Vector2* position = m_gameObject->GetPosition();
		m_position = new Vector2(position->Get_X(), position->Get_Y());
	}
	else
	{
		m_gameObject = nullptr;
		m_position = new Vector2();
	}
	
	m_bounds = new Bounds(m_position, size);
	m_collisionShape = new Rect(m_position, size, size);
	SetBoundsFromShape();
}

Trigger::~Trigger()
{
	delete m_position;
	m_position = nullptr;

	delete m_collisionShape;
	m_collisionShape = nullptr;

	delete m_bounds;
	m_bounds = nullptr;

	delete m_gameObject;
	m_gameObject = nullptr;
}

void Trigger::HandleCollision(Collider* other)
{
	if (m_gameObject)
	{
		m_gameObject->OnTriggerEnter(other);
	}
}