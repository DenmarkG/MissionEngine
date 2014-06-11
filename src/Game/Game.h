#pragma once

#include <list>
#include <map>

class Pawn;
class GameObject;
class Actor2D;
class Scene;
class Cubie;
class Collider;
class Vector2;
class Kamikaze;

const size_t BUFFER = 64;


class Game
{
public:
	Game();
	~Game();

	void Run();
	
	void OneTimeInit(); //sets up all the game objects currently in the scene to render
	//bool Destroy(GameObject*);


	Pawn* GetPlayer() const { return m_player; }

private:
	void CreatePlayer(Vector2* position);
	void SpawnRandomEnemy();
	void SpawnRandomBlock();

	Cubie* m_cubie;
	Actor2D* m_worldBounds;
	Pawn* m_player;
	Scene* m_currentScene;
	//std::map<std::string, GameObject*> m_allGameObjs;
	std::map<std::string, Actor2D*> m_allActors;


	float m_initialCubieSpawnTime;
	float m_currentCubieSpawnTime;

	float m_initialKamikazeSpawnTime;
	float m_currentKamikazeSpawnTime;

	unsigned int m_enemyCount;
	unsigned int m_blockCount;
	//Kamikaze* kami;
};