#include <list>

class Mission;

class MisssionManager
{
public:
	MisssionManager();
	~MisssionManager();

	void SetCurrentMission();
	Mission* GetCurrentMission();
	void UpdateCurrentMission();

	bool AddNewMission();

private:
	Mission* m_currentMission;
	std::list<Mission*> m_missionList;
};