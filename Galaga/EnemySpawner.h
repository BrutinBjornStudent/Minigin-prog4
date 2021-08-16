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
	
	EnemySpawner(glm::vec2 startCenterPos, glm::vec2 SizeOfEnemy, glm::vec2 WindowSize, dae::Scene& currentScene, const std::string& file);

	void Update(const float ) override;
	void Render() const override {};

	void SpawnEnemys();

	void TestSpawn();

private:
	std::vector<dae::GameObject*> nm_pEnemys;
	dae::Scene& nm_pCurrentScene;
	
	std::vector<GridPos> m_Gridpositions;
	std::vector<GridPos> m_FirstWave;
	std::vector<GridPos> m_SecondWave;
	std::vector<GridPos> m_thirdWave;
	std::vector<GridPos> m_ForthWave;
	std::vector<GridPos> m_FifthWave;

	std::vector<std::vector<GridPos>> m_Waves;

	glm::vec2 m_SizeOfEnemy;
	glm::vec2 m_GameSize;
	glm::vec2 m_startCenter;



	
	bool m_RunSpawnLoop;
	int m_HasSpawnedCount;
	int m_ToSpawn;
	int m_CurrentWave = 0;
	
	float m_SpawnDelay = 0.5f;
	float m_ELapsedSpawnDelay = 0.f;

	float m_NextWaveDelay = 2.f;
	float m_ElapsedNextWave = 0.f;
	
};

