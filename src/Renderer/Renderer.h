#pragma once

#include <vector>

class Actor2D;
class Vector2;
class Collider; //for debug drawing colliders

//this class handles all rendering for the game

struct Color
{
	Color(float red = 0, float green = 0, float blue = 0, float alpha = 255);
	float r, g, b, a;
};

class Renderer
{
public:
	//static arena constants
	const static float WORLD_WIDTH;
	const static float WORLD_HEIGHT;
	const static int WORLD_DIVISIONS;
	const static float WORLD_DIVISION_SIZE;
	const static float BACKGROUND_ZDEPTH;

	~Renderer();

	static void DrawWorld();
	static void DrawTriangle(Vector2* position, Color* color);
	static void DrawQuad(Vector2* position, Color* color);
	static void DrawQuad(Vector2* position, Color* color, float size);
	static void DrawCollider(const Collider& collider);

	//list of all all actors to draw
	//[rez] also didn't have time to refactor this
	static std::vector<Actor2D*> m_allActors;

private:
	void DrawArena();
	//void DrawStaticObjects();
	//void DrawEntities(); //an entity will be anything not static in the world

	//for the singleton pattern
	static Renderer* m_instance;
	static Renderer& GetInstance();
	Renderer();
};