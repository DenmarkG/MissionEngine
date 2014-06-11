#include "Vector2.h"
#include <math.h>

Vector2::Vector2()
{
	m_x = 0;
	m_y = 0;
	m_z = 0;
}

Vector2::Vector2(float x = 0, float y = 0)
{
	m_x = x;
	m_y = y;
	m_z = 0;
}

Vector2::Vector2(const Vector2& source)
{
	m_x = source.Get_X();
	m_y = source.Get_Y();
	m_z = source.Get_Z();
}

Vector2::~Vector2()
{
	//
}

//Static Functions
//================================================================================
Vector2* GetNormalized(Vector2* pVector)
{
	float length = pVector->GetLegnth();
	pVector->Set_X(pVector->Get_X() / length);
	pVector->Set_Y(pVector->Get_Y() / length);
	
	//for use with 3D Vectors
	//pVector->Set_Z(pVector->Get_Z() / length);
	return pVector;
}

float Distance(Vector2* pFrom, Vector2* pTo)
{
	//these names may seem generic, but they come from the actual distance formula
	//this could be done in one line, but would make readability difficult
	float x1 = pFrom->Get_X();
	float y1 = pFrom->Get_Y();
	float z1 = pFrom->Get_Z();

	float x2 = pTo->Get_X();
	float y2 = pTo->Get_Y();
	float z2 = pTo->Get_Z();

	//calculate the distance based on the distance formula
	float distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2));

	//return the distance
	return distance;
}

//Non-Static Functions
//================================================================================
float Vector2::GetLegnth() const
{
	return sqrt(pow(m_x, 2) + pow(m_y, 2));
}

float Vector2::Distance(Vector2* pTo) const
{
	return sqrt(pow(pTo->Get_X() - m_x, 2) + pow(pTo->Get_Y() - m_y, 2));
}

//[#todo] Implement this method
Vector2* Vector2::Lerp(Vector2* pFrom, Vector2* pTo, float step)
{
	//step =  0 + time.deltaTime
	//step(x1) + step(1-x2) = x
	//Vector2 movedVector = Vector2();
	//m_x =
	return nullptr;
}

void Vector2::Normalize()
{
	float length = this->GetLegnth();
	this->Set_X(this->Get_X() / length);
	this->Set_Y(this->Get_Y() / length);
}

//OPERATOR OVERLOADS
//============================================
Vector2 Vector2::operator+(const Vector2& rhs)
{
	Vector2 sum(0,0);

	sum.Set_X(m_x + rhs.Get_X() );
	sum.Set_Y(m_x + rhs.Get_Y() );
	
	//since this project will only be used in two dimensions, z will not be used
	//sum.Set_Z(m_x + rhs.Get_Z());

	return sum;
}

Vector2 Vector2::operator-(const Vector2& rhs)
{
	Vector2 diff(0, 0);

	diff.Set_X(m_x - rhs.Get_X());
	diff.Set_Y(m_x - rhs.Get_Y());

	//since this project will only be used in two dimensions, z will not be used
	//sum.Set_Z(m_x + rhs.Get_Z());

	return diff;
}

Vector2 Vector2::operator*(float scalar)
{
	Vector2 prod(0, 0);

	prod.Set_X(m_x * scalar);
	prod.Set_Y(m_y * scalar);

	//since this project will only be used in two dimensions, z will not be used

	return prod;
}

Vector2 Vector2::operator += (const Vector2& rhs)
{
	m_x += rhs.Get_X();
	m_y += rhs.Get_Y();
	
	//again, not using Z here
	//m_z += rhs.Get_Z();

	return *this;
}

Vector2 Vector2::operator -= (const Vector2& rhs)
{
	m_x -= rhs.Get_X();
	m_y -= rhs.Get_Y();

	//again, not using Z here
	//m_z += rhs.Get_Z();

	return *this;
}

Vector2 Vector2::operator *= (float scalar)
{
	m_x *= scalar;
	m_y *= scalar;

	//again, not using Z here
	//m_z += rhs.Get_Z();

	return *this;
}

bool Vector2::operator== (const Vector2& rhs)
{
	return (m_x == rhs.Get_X() ) && (m_y == rhs.Get_Y() ) /*&& (m_z == rhs.Get_Z)*/;
}

bool Vector2::operator!= (const Vector2& rhs)
{
	return (m_x != rhs.Get_X() ) || (m_y != rhs.Get_Y() ) /*|| (m_z != rhs.Get_Z)*/;
}

Vector2& Vector2::operator=(const Vector2& source)
{
	//since this class has no member pointers, we can shallow copy it
	return *this;
}