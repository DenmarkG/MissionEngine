#include "Cubie.h"
#include "..\Vector\Vector2.h"
#include "..\Collision\Collider.h"

Cubie::Cubie()
{
	m_position = new Vector2(2, 2);

	m_moveSpeed = 0;

	SetColor(255, 102, 0, 255);

	m_objectKey = "Cubie";

	m_collider = new Collider(this);

	m_isStatic = true;
}

Cubie::Cubie(float x, float y)
{
	m_position = new Vector2(x, y);

	m_moveSpeed = 0;

	SetColor(255, 102, 0, 255);

	m_objectKey = "Cubie";

	m_collider = new Collider(this);

	m_isStatic = true;
}

Cubie::~Cubie()
{
	delete m_position;
	m_position = nullptr;

	delete m_collider;
	m_collider = nullptr;
}

void Cubie::Update()
{
	//
}

void Cubie::Draw()
{
	Renderer::DrawQuad(m_position, &m_color);
}

void Cubie::Move()
{
	//this little cubie is not going to market =/
}