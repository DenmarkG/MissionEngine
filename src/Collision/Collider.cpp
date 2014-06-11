#include "..\GameObject\GameObject.h"
#include "Collider.h"
#include "Bounds.h"
#include "..\Shape\Rect.h"
#include "..\Vector\Vector2.h"

#include <iostream>
#include <math.h>

Collider::Collider()
{
	//obligatory default constructor
}

Collider::Collider(GameObject* owner)
{
	m_gameObject = owner;

	//this was done this way for readability
	Vector2* position = m_gameObject->GetPosition();
	m_position = new Vector2(position->Get_X(), position->Get_Y() );

	//the default bound size for all objects is 1
	m_bounds = new Bounds(m_position, 1);
	m_collisionShape = new Rect(m_position);
	SetBoundsFromShape();
}

Collider::Collider(GameObject* owner, float boundSize)
{
	m_gameObject = owner;

	Vector2* position = m_gameObject->GetPosition();
	m_position = new Vector2(position->Get_X(), position->Get_Y());

	m_bounds = new Bounds(m_position, boundSize);
	m_collisionShape = new Rect(m_position, boundSize, boundSize);
	SetBoundsFromShape();
}

Collider::~Collider()
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

void Collider::ForceOwnerInside()
{
	m_bounds->UpdateBounds(m_position);
	m_gameObject->SetPosition(m_position);
}

void Collider::HandleCollision(Collider* other)
{
	if (!m_gameObject->IsStatic())
	{
		Vector2 max = *m_bounds->GetMax();
		Vector2 min = *m_bounds->GetMin();

		Vector2 max_other = *(other->GetBounds()->GetMax());
		Vector2 min_other = *(other->GetBounds()->GetMin());

		Bounds* otherBounds = other->GetBounds();

		float optimalDistance = (m_bounds->GetSize() / 2) + (other->GetBounds()->GetSize() / 2);
		float xOffset = max.Get_X() - max_other.Get_X();
		float yOffset = max.Get_Y() - max_other.Get_Y();

		if (!m_gameObject->IsStatic())
		{
			//move the collider to the bounds of the other object
			if (abs(xOffset) > abs(yOffset))
			{
				if (xOffset > 0) //move right
				{
					m_position->Set_X((m_position->Get_X() + optimalDistance - xOffset));
				}
				else if (xOffset < 0) //move left
				{
					m_position->Set_X((m_position->Get_X() - optimalDistance - xOffset));
				}
			}
			else if (abs(yOffset) > abs(xOffset))
			{
				if (yOffset > 0) //move up
				{
					m_position->Set_Y((m_position->Get_Y() + optimalDistance - yOffset));
				}
				else if (yOffset < 0) //move down
				{
					m_position->Set_Y((m_position->Get_Y() - optimalDistance - yOffset));
				}
			}
			ForceOwnerInside();
		}
	}
}

bool Collider::IsColliding(Collider* other) const
{
	Vector2 max = *m_bounds->GetMax();
	Vector2 min = *m_bounds->GetMin();

	Vector2 max_other = *(other->GetBounds()->GetMax());
	Vector2 min_other = *(other->GetBounds()->GetMin());

	//if any of these are true, then the objects are not colliding
	if (max.Get_X() < min_other.Get_X() || max_other.Get_X() < min.Get_X() ||
		max.Get_Y() < min_other.Get_Y() || max_other.Get_Y() < min.Get_Y())
	{
		return false;
	}

	return true;
}

void Collider::SetBoundsFromShape()
{
	if (m_collisionShape)
		m_collisionShape->CalculateBounds();
}

void Collider::SetPosition(Vector2* position)
{
	m_position->Set_X(position->Get_X() );
	m_position->Set_Y(position->Get_Y() );

	m_bounds->UpdateBounds(m_position);
}