#include "Shape.h"

class Vector2;

class Rect : public Shape
{
public:
	//constructor stuffs
	Rect();
	Rect(Vector2* position);
	Rect(Vector2* poisition, float width, float height);
	~Rect();

	//getters/setters
	float GetWidth() const { return m_width; }
	float GetHeight() const { return m_height; }

	void SetWidth(float newWidth);
	void SetHeight(float newHeight);

	bool isSquare() const { return m_height == m_width; }

	virtual Bounds* CalculateBounds();

private:
	float m_width;
	float m_height;
};