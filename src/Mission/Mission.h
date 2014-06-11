#include <list>

class Mission
{
public:
	enum MissionState
	{
		LOCKED,
		UNLOCKED,
		IN_PROGRESS,
		FAILED,
		SUCESS
	};

	//pure virtual functions
	virtual void UnlockMission() = 0;
	virtual void BeginMission() = 0;
	virtual void UpdateMission() = 0;
	virtual void EndMission() = 0;
	
	bool IsComplete() const;

private:
	Mission();

	//functions
	void UnlockDependents();

	//members
	MissionState m_currentState;
	std::list<Mission*> m_ChildMissions;
};

//bool Mission::IsComplete() const
//{
//	return !(m_currentState == MissionState::FAILED ||
//		m_currentState == MissionState::SUCESS);
//}
//
//void Mission::UnlockDependents()
//{
//	for (auto it = m_ChildMissions.begin(); it != m_ChildMissions.end(); ++it)
//	{
//		it->UnlockMission();
//	}
//}