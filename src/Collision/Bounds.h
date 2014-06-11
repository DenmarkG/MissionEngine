#pragma once

class Vector2;

class Bounds
{
public:
	Bounds();
	Bounds(Vector2* position, float size);
	~Bounds();

	Vector2* GetMin() const { return m_min; };
	Vector2* GetMax() const { return m_max; };
	float GetSize() const { return m_size; };

	void SetMinMax(Vector2* min, Vector2* max);

	void UpdateBounds(Vector2* position);

private:
	void UpdateMax();
	void UpdateMin();

	float m_size;
	Vector2* m_position;
	Vector2* m_max;
	Vector2* m_min;
};