#include "MissionManager.h"
#include "Mission.h"

MisssionManager::MisssionManager()
{
	m_currentMission = nullptr;
}

MisssionManager::~MisssionManager()
{
	delete m_currentMission;
	m_currentMission = nullptr;
}