#include "Actor2D.h"
#include "../Collision/Collider.h"
#include "../Collision/CollisionVolume.h"
#include "../Vector/Vector2.h"

#include <iostream>

Actor2D::Actor2D()
{
	/*m_position = new Vector2();
	m_color.b = 255;

	m_objectKey = "";

	m_collider = new Collider(this);*/
}

Actor2D::Actor2D(float colliderSize)
{
	m_position = new Vector2();
	m_color.a = 0;
	m_collider = new CollisionVolume(this, colliderSize);
}

Actor2D::~Actor2D()
{
	//delete the position vector
	delete m_position;
	m_position = nullptr;

	delete m_collider;
	m_collider = nullptr;
}

void Actor2D::Draw()
{
	/*Renderer::DrawTriangle(m_position, &m_color);
	std::cout << "Drawing" << std::endl;*/
}

void Actor2D::Update()
{
	//
}

void Actor2D::OnTriggerEnter(Collider* other)
{
	//
}

void Actor2D::SetColor(float r, float g, float b, float a)
{
	m_color.r = r;
	m_color.g = g;
	m_color.b = b;
	m_color.a = a;
}