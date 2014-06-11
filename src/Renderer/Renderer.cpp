#include <windows.h>
#include <iostream>

// Open GL includes
#include "../../gl/gl.h"
#include "../../glut/glut.h"

#include "Renderer.h"
#include "../Vector/Vector2.h"
#include "../GameObject/Actor2D.h"

#include "../Collision/Collider.h"
#include "../Collision/Bounds.h"

Renderer* Renderer::m_instance = nullptr;
std::vector<Actor2D*> Renderer::m_allActors;

const float Renderer::WORLD_WIDTH = 20;
const float Renderer::WORLD_HEIGHT = 20;
const int Renderer::WORLD_DIVISIONS = 20;
const float Renderer::WORLD_DIVISION_SIZE = 1;
const float Renderer::BACKGROUND_ZDEPTH = -5;

Renderer::Renderer()
{
	//
}

Renderer::~Renderer()
{
	for (auto it = m_allActors.begin(); it != m_allActors.end(); ++it)
	{
		delete *it;
		*it = nullptr;
	}

	m_allActors.clear();

	delete m_instance;
	m_instance = nullptr;
}

void Renderer::DrawWorld()
{
	// clear stencil each time
	glClearColor(0.5f, 0.1f, 0.1f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

	m_instance->DrawArena();

	//this was here for testing purposes
	//m_instance->DrawQuad(&Vector2(), &Color(0, 0, 255, 255));
	//m_instance->DrawTriangle(&Vector2(5,5), &Color(255, 0, 0, 255) );

	//m_instance->DrawStaticObjects();
	//m_instance->DrawEntities();

	for (unsigned int i = 0; i < m_allActors.size(); ++i)
	{
		m_allActors[i]->Draw();
		
		Collider* collider = m_allActors[i]->GetCollider();
		if (collider)
			DrawCollider(*collider);
	}

	//std::cout << m_allActors.size() << std::endl;

	glutSwapBuffers();
}

void Renderer::DrawArena()
{
	// draw background quad
	float leftBounds = -(WORLD_WIDTH / 2);
	float rightBounds = WORLD_WIDTH / 2;
	float upBounds = WORLD_HEIGHT / 2;
	float lowBounds = -(WORLD_HEIGHT / 2);

	glBegin(GL_QUADS);  // we're about to render quads!

	glColor4ub(255, 255, 255, 255);

	//vertices must be rendered counter-clockwise from the top left
	glVertex3f(leftBounds, upBounds, BACKGROUND_ZDEPTH);
	glVertex3f(leftBounds, lowBounds, BACKGROUND_ZDEPTH);
	glVertex3f(rightBounds, lowBounds, BACKGROUND_ZDEPTH);
	glVertex3f(rightBounds, upBounds, BACKGROUND_ZDEPTH);

	glEnd();

	// draw grid to provide a sense of scale
	glBegin(GL_LINES);  // we're about to draw lines!
	glColor4ub(0, 255, 0, 255);

	float lineDepth = -1.4f;

	//horizontal lines
	for (int i = 0; i <= WORLD_DIVISIONS; ++i)
	{
		glVertex3f(leftBounds, WORLD_DIVISION_SIZE*i + lowBounds, lineDepth);
		glVertex3f(rightBounds, WORLD_DIVISION_SIZE*i + lowBounds, lineDepth);
	}

	//vertical lines
	for (int i = 0; i <= WORLD_DIVISIONS; ++i)
	{
		glVertex3f(WORLD_DIVISION_SIZE*i + leftBounds, upBounds, lineDepth);
		glVertex3f(WORLD_DIVISION_SIZE*i + leftBounds, lowBounds, lineDepth);
	}
	glEnd();
}

void Renderer::DrawTriangle(Vector2* position, Color* color)
{
	glBegin(GL_TRIANGLES);
	glColor4ub(color->r, color->g, color->b, color->a);

	float halfSize = .5f;

	glVertex3f(position->Get_X(), position->Get_Y() + halfSize, position->Get_Z());
	glVertex3f(position->Get_X() - halfSize, position->Get_Y() - halfSize, position->Get_Z());
	glVertex3f(position->Get_X() + halfSize, position->Get_Y() - halfSize, position->Get_Z());
	glEnd();
}

void Renderer::DrawQuad(Vector2* position, Color* color)
{
	glBegin(GL_QUADS);  // we're about to render quads!
	//vertices must be rendered counter-clockwise from the top left

	float halfSize = .5f;

	glColor4ub(color->r, color->g, color->b, color->a);
	glVertex3f(position->Get_X() - halfSize, position->Get_Y() + halfSize, -1.35f);
	glVertex3f(position->Get_X() - halfSize, position->Get_Y() - halfSize, -1.35f);
	glVertex3f(position->Get_X() + halfSize, position->Get_Y() - halfSize, -1.35f);
	glVertex3f(position->Get_X() + halfSize, position->Get_Y() + halfSize, -1.35f);
	glEnd();
}

void Renderer::DrawQuad(Vector2* position, Color* color, float size)
{
	glBegin(GL_QUADS);  // we're about to render quads!
	//vertices must be rendered counter-clockwise from the top left

	float halfSize = size / 2;

	glColor4ub(color->r, color->g, color->b, color->a);
	glVertex3f(position->Get_X() - halfSize, position->Get_Y() + halfSize, -1.35f);
	glVertex3f(position->Get_X() - halfSize, position->Get_Y() - halfSize, -1.35f);
	glVertex3f(position->Get_X() + halfSize, position->Get_Y() - halfSize, -1.35f);
	glVertex3f(position->Get_X() + halfSize, position->Get_Y() + halfSize, -1.35f);
	glEnd();
}

Renderer& Renderer::GetInstance()
{
	if (m_instance == nullptr)
		m_instance = new Renderer();

	return *m_instance;
}

void Renderer::DrawCollider(const Collider& collider)
{
	Bounds* bounds = collider.GetBounds();

	float left = bounds->GetMin()->Get_X();
	float right = bounds->GetMax()->Get_X();
	float up = bounds->GetMax()->Get_Y();
	float down = bounds->GetMin()->Get_Y();
	float size = bounds->GetSize();

	glBegin(GL_LINES);  // we're about to draw lines!
	glColor4ub(0, 0, 0, 255);

	float lineDepth = 0;
	
	//(x, y, z), left to right when creating verts
	
	//top line
	glVertex3f(left, up, lineDepth);
	glVertex3f(right, up, lineDepth);
	//bottom
	glVertex3f(left, down, lineDepth);
	glVertex3f(right, down, lineDepth);
	//left
	glVertex3f(left, up, lineDepth);
	glVertex3f(left, down, lineDepth);
	//right
	glVertex3f(right, up, lineDepth);
	glVertex3f(right, down, lineDepth);

	glEnd();
}

Color::Color(float red, float green, float blue, float alpha)
{
	r = red;
	g = green;
	b = blue;
	a = alpha;
}