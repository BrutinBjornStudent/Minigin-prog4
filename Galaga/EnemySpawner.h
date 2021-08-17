#pragma once
#include <vector>

#include "Component.h"
#include "GameObject.h"

namespace dae {
	class Scene;
}


struct GridPos
{
	glm::ivec2 arrayPos;
	glm::vec2 screenPos;
};

class EnemySpawner final:
    public BaseComponent
{
public:
	
	EnemySpawner(glm::vec2 startCenterPos, glm::vec2 SizeOfEnemy, glm::vec2 WindowSize, const std::string& file);

	void Update(const float ) override;
	void Render() const override {};

	void SpawnEnemys();
	const std::vector<std::vector<glm::vec2>>& GetBazierPaths() { return m_BazierPaths; };
	//void TestSpawn();

private:
	glm::vec2 CalculateBridges(int currentSegment, int MaxSegments);
	
	std::vector<dae::GameObject*> nm_pEnemys;
	std::vector<GridPos> m_Gridpositions;
	
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
	
	float m_SpawnDelay = 0.5f;
	float m_ELapsedSpawnDelay = 0.f;

	float m_NextWaveDelay = 2.f;
	float m_ElapsedNextWave = 0.f;
	
};

