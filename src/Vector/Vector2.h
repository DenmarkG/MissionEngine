#ifndef Vector2_H
#define Vector2_H

class Vector2
{
public:
	Vector2();
	Vector2(float x, float y);
	Vector2(const Vector2& source); //overloading the copy constructor for assingments
	~Vector2();
	//===================================================================
	//returns the length of this vector
	virtual float GetLegnth() const;

	//returns the distance from this vector to the vector pTo
	virtual float Distance(Vector2* pTo) const;

	//returns a vector that is the linear interpolation between from and to at time step
	virtual Vector2* Lerp(Vector2* pFrom, Vector2* pTo, float step);

	//normalizes this vector
	virtual void Normalize();

	//===================================================================
	//static functions
	//returns the normalized vector that was passed in
	static Vector2* GetNormalized(Vector2* pVector);

	//returns the distance between the two passed in vectors
	static float Distance(Vector2* pFrom, Vector2* pTo); //returns the distance between the two vectors

	//===================================================================
	//Getters and Setters
	//***NOTE*** get/set Z will return/set z to zero
	float Get_X() const { return m_x; }
	float Get_Y() const { return m_y; }
	float Get_Z() const { return m_z; }

	void Set_X(float newX){ m_x = newX; }
	void Set_Y(float newY){ m_y = newY; }
	void Set_Z(float newZ){ m_z = newZ; }
	
	//special case for setting the z depth for rendering
	void SetZDepth(float newZ){ m_z = newZ; }

	//Operator Overloading
	//Basic Operators
	Vector2 operator + (const Vector2& rhs);
	Vector2 operator - (const Vector2& rhs);
	Vector2 operator * (float scalar);

	//Compound Operators
	Vector2 operator += (const Vector2& rhs);
	Vector2 operator -= (const Vector2& rhs);
	Vector2 operator *= (float scalar);

	//Relational Operators
	bool operator==(const Vector2& rhs);
	bool operator!=(const Vector2& rhs);

	//Assignment Operator (had to look this up too)
	Vector2& operator=(const Vector2& source);
	

protected:
	float m_x, m_y, m_z;
};

//Operator Overload
//============================================

#endif