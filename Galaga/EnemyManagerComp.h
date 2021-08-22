#pragma once
#include <vector>

#include "Component.h"
#include "GameObject.h"
#include "GalagaObservers.h"
#include "Subject.h"

namespace dae {
	class Scene;
}


struct GridPos
{
	glm::ivec2 arrayPos;
	glm::vec2 screenPos;
};

class EnemyManagerComp final:
    public BaseComponent
{
public:
	
	EnemyManagerComp(glm::vec2 startCenterPos, glm::vec2 SizeOfEnemy, glm::vec2 WindowSize, const GalagaEnemyObserver ObForEnemys,const std::string& file);
	virtual ~EnemyManagerComp() { delete m_subject; }
	
	void Update(const float ) override;
	void Render() const override {};
	void IsAttacking(bool attack) { m_IsTriggeringAttack = attack; }
	
	void SpawnEnemys();
	const std::vector<std::vector<glm::vec2>>& GetBazierPaths() { return m_BazierPaths; };
	Subject* GetSubject() { return m_subject; };
	
	std::vector<glm::vec2> CreateAttackPattern(glm::vec2 StartPos);

private:
	glm::vec2 CalculateBridges(int currentSegment, int MaxSegments);
	
	std::vector<std::weak_ptr<dae::GameObject>> nm_pEnemys;

	bool m_IsTriggeringAttack = true;
	float m_TriggerEnemyAttack = 2.f;
	float m_ElapsedTriggerAttack = 0.f;

	
	std::vector<GridPos> m_Gridpositions;
	GalagaEnemyObserver m_EnemyObserver;
	Subject* m_subject;
	
	std::vector<std::vector<GridPos>> m_Waves;
	// keeps the Baziers to be used by the enemys.

	
	std::vector<std::vector<glm::vec2>> m_BaziersPoints;
	std::vector<std::vector<glm::vec2>> m_BazierPaths;
	
	
	glm::vec2 m_SizeOfEnemy;
	glm::vec2 m_GameSize;
	glm::vec2 m_startCenter;

	//Bazier values
	glm::vec2 m_Point;
	std::vector<glm::vec2> m_SegmentPoints;
	std::vector<glm::vec2> m_CurrentBridges;
	std::vector<glm::vec2> m_NewBridges;

	
	
	
	bool m_RunSpawnLoop;
	int m_HasSpawnedCount;
	int m_ToSpawn;
	int m_CurrentWave = 0;
	
	float m_SpawnDelay = 0.15f;
	float m_ELapsedSpawnDelay = 0.f;

	float m_NextWaveDelay = 1.f;
	float m_ElapsedNextWave = 0.f;
	
};

