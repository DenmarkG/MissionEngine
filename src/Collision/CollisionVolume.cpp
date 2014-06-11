#include "CollisionVolume.h"
#include "..\GameObject\GameObject.h"
#include "Collider.h"
#include "Bounds.h"
#include "..\Shape\Rect.h"
#include "..\Vector\Vector2.h"

#include <iostream>
#include <math.h>

CollisionVolume::CollisionVolume()
{
	//obligatory default constructor
}

CollisionVolume::CollisionVolume(GameObject* owner, float size)
{
	m_gameObject = owner;
	m_position = new Vector2();

	m_bounds = new Bounds(m_position, size);
	m_collisionShape = new Rect(m_position, size, size);
	SetBoundsFromShape();
}

CollisionVolume::~CollisionVolume()
{
	delete m_position;
	m_position = nullptr;

	delete m_collisionShape;
	m_collisionShape = nullptr;

	delete m_bounds;
	m_bounds = nullptr;
}

void CollisionVolume::HandleCollision(Collider* other)
{
	Vector2 max = *m_bounds->GetMax();
	Vector2 min = *m_bounds->GetMin();

	Vector2 max_other = *(other->GetBounds()->GetMax());
	Vector2 min_other = *(other->GetBounds()->GetMin());

	float halfSize = other->GetBounds()->GetSize() / 2;

	Vector2* otherPos = other->GetPosition();

	if (max_other.Get_X() > max.Get_X())
	{
		//force left
		otherPos->Set_X(max.Get_X() - halfSize);
	}
	if (min_other.Get_X() < min.Get_X())
	{
		//force right
		otherPos->Set_X(min.Get_X() + halfSize);
	}
	if (max_other.Get_Y() > max.Get_Y())
	{
		//force down
		otherPos->Set_Y(max.Get_Y() - halfSize);
	}
	if (min_other.Get_Y() < min.Get_Y())
	{
		//force up
		otherPos->Set_Y(min.Get_Y() + halfSize);
	}

	other->GetBounds()->UpdateBounds(otherPos);
	other->GetGameOjbect()->SetPosition(otherPos);
}

bool CollisionVolume::IsColliding(Collider* other) const
{
	Vector2 max = *m_bounds->GetMax();
	Vector2 min = *m_bounds->GetMin();

	Vector2 max_other = *(other->GetBounds()->GetMax());
	Vector2 min_other = *(other->GetBounds()->GetMin());

	//if any of these are true, then the objects are not colliding
	if (max.Get_X() > max_other.Get_X() || min.Get_X() < min_other.Get_X() ||
		max.Get_Y() > max_other.Get_Y() || min.Get_Y() < min_other.Get_Y() )
	{
		return false;
	}

	return false;
}