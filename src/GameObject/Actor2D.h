#pragma once
#include "GameObject.h"
#include "../Renderer/Renderer.h"

class Actor2D : public GameObject
{
public:
	Actor2D();
	Actor2D(float colliderSize);
	~Actor2D();
	
	//Inherited from GameObject
	virtual void Draw();
	virtual void Update();
	virtual void OnTriggerEnter(Collider* other);
protected:
	void SetColor(float r, float g, float b, float a);

	Color m_color;
};

//[#todo] in the Actor2d class, to set the z depth, add/subtract (0,0,-1) * scalar from the
//	current position