#include "CollisionManager.h"
#include "Collider.h"
#include "CollisionVolume.h"

#include "..\GameObject\GameObject.h"

#include <iostream>

CollisionManager* CollisionManager::m_instance = nullptr;
CollisionVolume* CollisionManager::m_worldBounds = nullptr;
std::list<Collider*> CollisionManager::m_activeColliders;

CollisionManager& CollisionManager::GetInstance()
{
	if (m_instance == nullptr)
		m_instance = new CollisionManager();

	return *m_instance;
}

CollisionManager::CollisionManager()
{
	//
}

CollisionManager::~CollisionManager()
{
	for (auto it = m_activeColliders.begin(); it != m_activeColliders.end(); ++it)
	{
		delete *it;
		*it = nullptr;
	}

	m_activeColliders.clear();
	
	delete m_instance;
	m_instance = nullptr;

}

void CollisionManager::Update()
{
	for (auto it = m_activeColliders.begin(); it != m_activeColliders.end(); ++it)
	{
		Collider* current = *it;

		//check the current object against the world bounds
		if (m_worldBounds)
		{
			if (current->IsColliding(m_worldBounds))
			{
				m_worldBounds->HandleCollision(current);
			}
		}

		for (auto it2 = m_activeColliders.begin(); it2 != m_activeColliders.end(); ++it2)
		{
			Collider* other = *it2;
			if (other && other != current)
			{
				if (current->IsColliding(other))
				{
					//std::cout << "colliding" << std::endl;
					current->HandleCollision(other);
				}
			}
		}
	}
}

void CollisionManager::AddCollider(Collider* collider)
{
	if (collider)
		m_activeColliders.push_back(collider);
}

void CollisionManager::SetWorldBounds(CollisionVolume* collider)
{
	m_worldBounds = collider;
}