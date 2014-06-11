#pragma once

class Time
{
public:
	~Time();
	static float GetTimeDelta();
	static void Update();

private:
	static void CalculateTimeDelta();

	static float m_deltaTime;

	//For the singleton
	static Time* m_instance;
	static Time& GetInstance();
	Time();
};