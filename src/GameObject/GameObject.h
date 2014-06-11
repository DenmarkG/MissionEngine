#pragma once
#include <string>

class Collider;
class Shape;
class Vector2;

using std::string;

class GameObject
{
public:
	GameObject();
	~GameObject();

	//Public Functions
	virtual void Draw() = 0;
	virtual void Update() = 0;
	virtual void OnTriggerEnter(Collider* other) = 0;

	//Getters and Setters
	const std::string& GetKey() const { return m_objectKey; }
	void SetKey(const std::string& newKey){ m_objectKey = newKey; }

	bool UseCollision() const { return m_collider != nullptr; };
	Collider* GetCollider() const { return m_collider; };

	virtual Vector2* GetPosition() const { return m_position; };
	virtual void SetPosition(Vector2* newPosition);

	bool IsStatic() const { return m_isStatic; };
	void SetStatic(bool isStatic);
protected:
	std::string m_objectKey;

	Vector2* m_position;

	Collider* m_collider;

	bool m_isStatic;
};