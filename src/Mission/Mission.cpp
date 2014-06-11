#include "Mission.h"

Mission::Mission()
{
	m_currentState = MissionState::LOCKED;
}

void Mission::UnlockMission()
{
	//
}

void Mission::BeginMission()
{
	//
}

void Mission::UpdateMission()
{
	//
}

void Mission::EndMission()
{
	//
}

bool Mission::IsComplete() const
{
	return !(m_currentState == MissionState::FAILED ||
		m_currentState == MissionState::SUCESS);
}

void Mission::UnlockDependents()
{
	for (auto it = m_ChildMissions.begin(); it != m_ChildMissions.end(); ++it)
	{
		/*it->UnlockMission();*/
	}
}