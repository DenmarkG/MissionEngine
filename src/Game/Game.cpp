#include "Game.h"
#include "MG_Pawn.h"
#include "../GameObject/Actor2D.h"
#include "..\Renderer\Renderer.h"
#include "..\Time\Time.h"
#include "..\GameObject\Pawn.h"
#include "..\Input\Input.h"
#include "..\Vector\Vector2.h"
#include "..\Scene\Scene.h"
#include "..\Collision\Collider.h"
#include "..\Collision\CollisionManager.h"
#include "..\Collision\CollisionVolume.h"
#include "Cubie.h"
#include "../Game/Pawns/Kamikaze.h"
#include "..\Scene\Level_01.h"
#include <stdio.h>

#include "..\..\gl\gl.h"
#include "..\..\glut\glut.h"

#include <iostream>
#include <ctime>

const float Y_SPAWN_POS = Renderer::WORLD_HEIGHT;

Game::Game()
{
	m_enemyCount = 0;

	//begin seeding random time
	srand(time(0));

	m_initialCubieSpawnTime = 5;
	m_currentCubieSpawnTime = 0;

	m_initialKamikazeSpawnTime = 2;
	m_currentKamikazeSpawnTime = 0;

	m_currentScene = new Level_01();
	Vector2* playerSpawn = m_currentScene->GetPlayerSpawnPos();
	if (!playerSpawn)
	{
		playerSpawn =  &Vector2();
	}

	//m_allActors = m_currentScene->LoadScene();
	CreatePlayer(playerSpawn);
	
	m_cubie = new Cubie();
	m_allActors.insert(make_pair(m_cubie->GetKey(), m_cubie));

	//kami = new Kamikaze(-2, 2);
	//m_allActors.insert(make_pair(kami->GetKey(), kami));

	//create the world bounds
	m_worldBounds = new Actor2D(Renderer::WORLD_HEIGHT);
	m_worldBounds->SetKey("Bounds");
	CollisionManager::SetWorldBounds((CollisionVolume*)m_worldBounds->GetCollider() );

	/*SpawnRandomEnemy();
	SpawnRandomBlock();*/
}

Game::~Game()
{
	delete m_player;
	m_player = nullptr;

	delete m_currentScene;
	m_currentScene = nullptr;

	delete m_worldBounds;
	m_worldBounds = nullptr;

	for (auto it = m_allActors.begin(); it != m_allActors.end(); ++it)
	{
		delete it->second;
		it->second = nullptr;
	}

	m_allActors.clear();
}

void Game::Run()
{
	if (m_currentKamikazeSpawnTime == 0)
	{
		//SpawnRandomEnemy();
	}

	if (m_currentCubieSpawnTime == 0)
	{
		//SpawnRandomBlock();
	}
	

	for (auto it = m_allActors.begin(); it != m_allActors.end(); ++it)
	{
		it->second->Update();
	}
}

void Game::OneTimeInit()
{
	//setup objects to render
	for (auto it = m_allActors.begin(); it != m_allActors.end(); ++it)
	{
		Actor2D* current = it->second;
		Renderer::m_allActors.push_back(current);
		if (current->UseCollision())
		{
			CollisionManager::AddCollider(current->GetCollider() );
		}
	}

	//CollisionManager::AddCollider(m_worldBounds->GetCollider());
}

void Game::CreatePlayer(Vector2* position)
{
	m_player = new MG_Pawn(position);
	m_player->SetKey("Player");
	m_allActors.insert(make_pair(m_player->GetKey(), m_player));

	if (m_currentScene)
	{
		//Load the scene
	}
}

void Game::SpawnRandomEnemy()
{
	++m_enemyCount;
	int xPos = rand() % ( (int) (Renderer::WORLD_WIDTH + 1) ) - 10;

	Kamikaze* newEnemy = new Kamikaze(xPos, Y_SPAWN_POS);
	m_allActors.insert(make_pair(newEnemy->GetKey(), newEnemy));

	unsigned char newKey[BUFFER];

	sprintf_s((char*)newKey, BUFFER, "Enemy %u", m_enemyCount);

	newEnemy->SetKey(" ");

	Renderer::m_allActors.push_back(newEnemy);
	CollisionManager::AddCollider(newEnemy->GetCollider());
}

void Game::SpawnRandomBlock()
{
	++m_blockCount;
	int xPos = rand() % ( (int)(Renderer::WORLD_WIDTH + 1) ) - 10;

	Cubie* newCubie = new Cubie(xPos, Y_SPAWN_POS);
	m_allActors.insert(make_pair(newCubie->GetKey(), newCubie));

	unsigned char newKey[BUFFER];

	sprintf_s((char*)newKey, BUFFER, "Cubie %u", m_blockCount);

	newCubie->SetKey(" ");

	Renderer::m_allActors.push_back(newCubie);
	CollisionManager::AddCollider(newCubie->GetCollider());
}