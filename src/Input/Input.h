#pragma once

enum KeyCode
{
	INVALID_KEY,
	W,
	A,
	S,
	D,
	SPACE
};

enum Axis
{
	INVALID_AXIS,
	HORIZONTAL,
	VERTICAL
};

class Input
{
public:

	static void CaptureInput(unsigned char key, int x, int y);
	static void Input::ReleaseInput(unsigned char key, int x, int y);

	static float GetAxis(Axis axis);
	static bool GetKey(KeyCode key);
	static void ClearBuffer();

private:
	struct KeyPress
	{
		bool w;
		bool a;
		bool s;
		bool d;
		bool space;
	};

	static float m_horizontalAxis;
	static float m_verticalAxis;
	static KeyPress m_keysPressed;

	static void UpdateAxes();

	//for the singleton pattern
	static Input* m_instance;
	static Input& GetInstance();
	Input();
};