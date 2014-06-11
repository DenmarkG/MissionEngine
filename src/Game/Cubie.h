#include "..\GameObject\Pawn.h"

class Cubie : public Pawn
{
public:
	Cubie();
	Cubie(float x, float y);
	~Cubie();

	//inherited
	virtual void Draw();
	virtual void Update();
	virtual void Move();
};