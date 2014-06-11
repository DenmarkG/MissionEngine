#pragma once

class Shape;
class Bounds;
class Vector2;
class GameObject;
class Actor2D;

class Collider
{
public:
	Collider();
	Collider(GameObject* owner);
	Collider(GameObject* owner, float boundSize);
	~Collider();

	//Collision Stuffs
	virtual void HandleCollision(Collider* other);
	virtual bool IsColliding(Collider* other) const;
	bool IsTrigger() const { return m_isTrigger; };

	//Getting and Setting the AAbb for this collider
	Bounds* GetBounds() const { return m_bounds; };
	void SetBoundsFromShape();

	//Getters and Setters for Position
	Vector2* GetPosition() const { return m_position; };
	void SetPosition(Vector2* position);

	GameObject* GetGameOjbect() const { return m_gameObject; };

protected:
	Shape* m_collisionShape; //will be a rect for now
	Bounds* m_bounds;

	Vector2* m_position;

	GameObject* m_gameObject;

	bool m_isTrigger;

private:
	void ForceOwnerInside();
};