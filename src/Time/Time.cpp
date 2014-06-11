#include "Time.h"
#include <windows.h>

//[rez] this was the only way I could get this code to compile
//before, I got linker errors about unresolved external symbols
float Time::m_deltaTime = 0;
Time* Time::m_instance = nullptr;
//======================================

Time::Time()
{
	m_deltaTime = 0;
}

Time::~Time()
{
	delete m_instance;
	m_instance = nullptr;
}

float Time::GetTimeDelta()
{
	return m_deltaTime;
}

void Time::CalculateTimeDelta()
{
	static LARGE_INTEGER frequency;
	static double        inverseFrequency = 0;
	static __int64       currentTime = 0L;
	LARGE_INTEGER now;

	if (currentTime == 0L)
	{
		QueryPerformanceFrequency(&frequency);
		inverseFrequency = 1.0f / ((double)frequency.QuadPart);
		QueryPerformanceCounter(&now);
		currentTime = (__int64)((double)now.QuadPart * inverseFrequency * 1000);
	}

	QueryPerformanceCounter(&now);
	__int64 newcurrentTime = (__int64)((double)now.QuadPart * inverseFrequency * 1000);
	float dt = 0.001f * (newcurrentTime - currentTime);
	if (dt < 1.0f / 60.0f) // clamp between 60hz and 30hz
		dt = 1.0f / 60.0f;
	else if (dt > 1.0f / 30.0f)
		dt = 1.0f / 30.0f;
	currentTime = newcurrentTime;

	m_deltaTime = dt;
}

void Time::Update()
{
	//this update function should be called at the beginning of each frame, since
	//delta time is based on the time passed between frames
	//m_deltaTime = 0;
	CalculateTimeDelta();
}

Time& Time::GetInstance()
{
	if (m_instance == nullptr)
		m_instance = new Time();

	return *m_instance;
}