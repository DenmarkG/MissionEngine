#include "Input.h"
#include <windows.h>
#include <iostream>

Input* Input::m_instance = nullptr;
float Input::m_horizontalAxis = 0;
float Input::m_verticalAxis = 0;
Input::KeyPress Input::m_keysPressed;

void Input::CaptureInput(unsigned char key, int x, int y)
{
	switch (key)
	{
		case VK_ESCAPE:
		{
			exit(0);
			break;
		}
		case VK_SPACE:
		{
			m_keysPressed.space = true;
			break;
		}

		default:
			break;
	}

	if (key == 'w')
	{
		m_keysPressed.w = true;
	}
		
	if (key == 'a')
	{
		m_keysPressed.a = true;
	}

	if (key == 's')
	{
		m_keysPressed.s = true;
	}
	if (key == 'd')
	{
		m_keysPressed.d = true;
	}

	UpdateAxes();

	//std::cout << m_horizontalAxis << std::endl;
	//std::cout << m_verticalAxis << std::endl;
}

void Input::ReleaseInput(unsigned char key, int x, int y)
{
	switch (key)
	{
		case VK_SPACE:
		{
			m_keysPressed.space = false;
			break;
		}

		default:
			break;
	}

	if (key == 'w')
	{
		m_keysPressed.w = false;
	}

	if (key == 'a')
	{
		m_keysPressed.a = false;
	}

	if (key == 's')
	{
		m_keysPressed.s = false;
	}
	if (key == 'd')
	{
		m_keysPressed.d = false;
	}

	UpdateAxes();
}

float Input::GetAxis(Axis axis)
{
	float axisValue = 0;
	switch (axis)
	{
	case Axis::HORIZONTAL:
		axisValue = m_horizontalAxis;
		break;
	case Axis::VERTICAL:
		axisValue = m_verticalAxis;
		break;
	default:
		break;
	}

	return axisValue;
}

bool Input::GetKey(KeyCode key)
{
	return false;
}

Input& Input::GetInstance()
{
	if (m_instance == nullptr)
		m_instance = new Input();

	return *m_instance;
}

void Input::ClearBuffer()
{
	m_keysPressed.w = false;
	m_keysPressed.a = false;
	m_keysPressed.s = false;
	m_keysPressed.d = false;
	m_keysPressed.space = false;
}

void Input::UpdateAxes()
{
	//set the vertical axis
	if (m_keysPressed.w)
		m_verticalAxis = 1;
	else if (m_keysPressed.s)
		m_verticalAxis = -1;
	else
		m_verticalAxis = 0;

	//set the horizontal axis
	if (m_keysPressed.d)
		m_horizontalAxis = 1;
	else if (m_keysPressed.a)
		m_horizontalAxis = -1;
	else
		m_horizontalAxis = 0;
}

Input::Input()
{
	//empty constructor
}

