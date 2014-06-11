#include "Level_01.h"
#include "..\GameObject\GameObject.h"
#include "..\GameObject\Actor2D.h"
#include "..\GameObject\Pawn.h"
#include "..\Vector\Vector2.h"

#include "..\Game\Cubie.h"\

Level_01::Level_01()
{
	//Cubie cubie;
	//m_allObjects.push_back(&cubie);
	m_playerSpawn = new Vector2();
}

Level_01::~Level_01()
{
	//
}

std::list<GameObject*>* Level_01::LoadScene()
{
	return &m_allObjects;
}