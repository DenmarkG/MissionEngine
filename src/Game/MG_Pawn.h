#pragma once

//[???] NOTE: this was originally called MG for Mission Guy
//I have since dropped the naming convention since the project doesn't use the
//mission system. I'd planned to refactor, but didn't get around to it.

#include "..\GameObject\Pawn.h"

class Vector2;

class MG_Pawn : public Pawn
{
public:
	MG_Pawn();
	MG_Pawn(Vector2* position);
	~MG_Pawn();

	//inherited virtual functions
	virtual void Update();
	virtual void Draw();
	virtual void Move(Vector2* direction);

private:
	int frames;
};