#pragma once

#include <list>

class Collider;
class CollisionVolume;

class CollisionManager
{
public:
	static void Update();
	~CollisionManager();

	static void AddCollider(Collider* collider);
	static void SetWorldBounds(CollisionVolume* collider);

private:
	//std::list<Collider*>* Partition(const std::list<Collider*>& gameObjects);
	static std::list<Collider*> Partition(std::list < Collider*> activeColliders);

	static CollisionManager* m_instance;
	static CollisionManager& GetInstance();
	CollisionManager();

	static std::list<Collider*> m_activeColliders;
	static CollisionVolume* m_worldBounds;
};