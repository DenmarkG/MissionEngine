#include "GameObject.h"
#include "..\Collision\Collider.h"
#include "..\Shape\Shape.h"
#include "..\Vector\Vector2.h"

GameObject::GameObject()
{
	//m_collider = new Collider(this);
}

GameObject::~GameObject()
{
	delete m_collider;
	m_collider = nullptr;
}

void GameObject::SetPosition(Vector2* newPosition)
{
	m_position->Set_X(newPosition->Get_X());
	m_position->Set_Y(newPosition->Get_Y());
}

void GameObject::SetStatic(bool isStatic)
{
	m_isStatic = isStatic;
}