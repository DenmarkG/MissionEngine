#include "Kamikaze.h"
#include "../../Collision/Collider.h"
#include "../../Vector/Vector2.h"
#include "../../Time/Time.h"
#include "../../Collision/Trigger.h"

#include <Windows.h>
#include <iostream>

Kamikaze::Kamikaze()
{
	m_direction = new Vector2(0, -1);
	
	m_moveSpeed = 2;
	m_isStatic = false;

	SetColor(222, 18, 66, 255);

	m_objectKey = "Kamikaze";

	m_collider = new Trigger(this, 1);
}

Kamikaze::Kamikaze(float x, float y)
{

	m_direction = new Vector2(0, -1);
	m_position = new Vector2(3, 5);

	m_moveSpeed = 2;
	m_isStatic = false;

	SetColor(222, 18, 66, 255);

	m_objectKey = "Kamikaze";

	m_collider = new Trigger(this, 1);
}

Kamikaze::~Kamikaze()
{
	delete m_collider;
	m_collider = nullptr;

	delete m_position;
	m_position = nullptr;

	delete m_direction;
	m_direction = nullptr;
}

void Kamikaze::Update()
{
		Move(m_direction);
}

void Kamikaze::Move(Vector2* direction)
{
	float step = m_moveSpeed * Time::GetTimeDelta();

	*m_position += *direction * step;

	if (m_collider)
		m_collider->SetPosition(m_position);
}

void Kamikaze::Draw()
{
	Renderer::DrawQuad(m_position, &m_color);
}

void Kamikaze::OnTriggerEnter(Collider* other)
{
	GameObject* otherGO = other->GetGameOjbect();
	if (otherGO)
	{
		if (otherGO->GetKey() == "Player")
		{
			//std::cout << "Hit Player!" << std::endl;
			//exit(0);
		}
	}
}