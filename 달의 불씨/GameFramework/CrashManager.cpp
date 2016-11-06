#include "CrashManager.h"


CrashManager::CrashManager()
{

}


CrashManager::~CrashManager()
{
}


void CrashManager::CheckStack(Physical *phy){
	phyList.push_back(phy);
	phy->SetTemCollison();
	
}

void CrashManager::SetCharacter(Character *character){
	m_pCharacter = character;
	
}

void CrashManager::Update(){

}

Physical* CrashManager::CheckTest(int movement){
	list<Physical*>::iterator iter;
	int cnt = 0;
	for (iter = phyList.begin(); iter != phyList.end(); iter++){
		if (0 <= (*iter)->GetSunPosition().x && (*iter)->GetSunPosition().x <= 1024){
			if (m_pCharacter->Crush(*iter)){
				return *iter;
			}
		}
	}
	return m_pCharacter;	
}


