#include "MG_Pawn.h"
#include "..\Vector\Vector2.h"
#include "..\Input\Input.h"
#include "..\Collision\Collider.h"
#include "..\Time\Time.h"

#include <iostream>

MG_Pawn::MG_Pawn()
{
	//obligatory default constructor
}

MG_Pawn::MG_Pawn(Vector2* position)
{
	//for debugging
	//frames = 0;

	m_moveSpeed = 5;
	m_isStatic = false;

	m_position = new Vector2(position->Get_X(), position->Get_Y());
	m_position->Set_Z(-1);
	m_position->SetZDepth(-1);

	m_color.r = 255;
	m_color.a = 255;

	m_objectKey = "Player";

	m_collider = new Collider(this);
}

MG_Pawn::~MG_Pawn()
{
	delete m_collider;
	m_collider = nullptr;

	delete m_position;
	m_position = nullptr;
}

void MG_Pawn::Update()
{
	Vector2 moveVector = Vector2(Input::GetAxis(Axis::HORIZONTAL), Input::GetAxis(Axis::VERTICAL));

	if (moveVector.GetLegnth() > 0)
	{
		Move(&moveVector);
	}

	if (m_collider)
		m_collider->SetPosition(m_position);
}

void MG_Pawn::Draw()
{
	Renderer::DrawTriangle(m_position, &m_color);
}

void MG_Pawn::Move(Vector2* direction)
{
	float step = m_moveSpeed * Time::GetTimeDelta();
	
	if (direction->GetLegnth() > 1)
		direction->Normalize();

	*m_position += *direction * step;
}