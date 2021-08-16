#include "EnemySpawner.h"

#include <nlohmann/json.hpp>



#include "ActorComponent.h"
#include "BeeComponent.h"
#include "BezierMoveComponent.h"
#include "GalagaConstructor.h"
#include "JsonManager.h"
#include "Scene.h"


namespace  ns
{
	struct wave
	{
		int id;
		int cells[8];
	};
}


EnemySpawner::EnemySpawner(glm::vec2 startCenterPos, glm::vec2 SizeOfEnemy, glm::vec2 WindowSize, dae::Scene& currentScene,const std::string& file)
	: m_SizeOfEnemy(SizeOfEnemy)
	, m_GameSize(WindowSize)
	, m_RunSpawnLoop(false)
	, m_HasSpawnedCount(0)
	, m_ToSpawn(8)
	, nm_pCurrentScene(currentScene)
{
	for (int height = -2; height <= 2; height++) //up to and 2
	{
		for (int witdh = -5; witdh < 5; witdh++) // up to 5
		{
			GridPos ToAdd;

			ToAdd.arrayPos = glm::ivec2(witdh, height);
			ToAdd.screenPos = glm::vec2(
				(SizeOfEnemy.x / 2) + SizeOfEnemy.x * witdh,
				SizeOfEnemy.y * height) + startCenterPos;

			m_Gridpositions.push_back(ToAdd);
		}
	}

	nlohmann::json j = JsonManager::GetInstance().LoadJsonDoc(file);
	
//	std::cout << j.dump() << std::endl;

	nlohmann::json jAr = j["Waves"];
	//TODO replace with JSON reader maybe

	for (nlohmann::json::iterator it = jAr.begin(); it != jAr.end(); ++it)
	{

		std::vector<int> integerWave;
		std::cout << *it << std::endl;


		
		nlohmann::json jCells = it.value()["Cells"];
		for (nlohmann::json::iterator it2 = jCells.begin(); it2 != jCells.end(); ++it2)
		{
			integerWave.push_back(it2->get<int>());
		}

		std::vector<GridPos> GridWave;
		for (int i = 0; i < integerWave.size(); i++)
			GridWave.push_back(m_Gridpositions[integerWave[i]]);

		m_Waves.push_back(GridWave);
		
	}
}

void EnemySpawner::Update(const float DeltaTime)
{

	if (m_RunSpawnLoop) // if is spawning
	{
		//if not finished spawning enemys of the current wave
		if (m_HasSpawnedCount < m_ToSpawn)
		{
			m_ELapsedSpawnDelay += DeltaTime; // add delay to to spawn;
			if (m_ELapsedSpawnDelay > m_SpawnDelay) // treshhold reached
			{


				auto &pos = m_Waves[m_CurrentWave][m_HasSpawnedCount];
				m_ELapsedSpawnDelay -= m_SpawnDelay;

				std::shared_ptr<dae::GameObject> newOb;
				
				if (pos.arrayPos.y == -2)
				{
					 newOb = objectConstructors::BeeEnemy("Galaga/BossGalaga.png", glm::ivec2(m_GameSize.x / 2, 0));
				}
				else if(pos.arrayPos.y <= 0)
				{
					newOb = objectConstructors::BeeEnemy("Galaga/butterfly.png", glm::ivec2(m_GameSize.x / 2, 0));		
				}
				else
				{
					newOb = objectConstructors::BeeEnemy("Galaga/bee.png", glm::ivec2(m_GameSize.x / 2, 0));
				}
				//spawn Enemy

				

				nm_pCurrentScene.AddInRun(newOb);
			
				newOb->GetComponent<BeeComponent>()->SetScreenPosition(m_Waves[m_CurrentWave][m_HasSpawnedCount]); 
				// Set Position on the grid
				m_HasSpawnedCount++;
			}
			
		} 
		else // spawned all of wave
		{
			if (m_CurrentWave == m_Waves.size() - 1) // if al waves spawend: stop
			{
				m_RunSpawnLoop = false;
			}
			
			m_ElapsedNextWave += DeltaTime; // add for delay between spawn.
			if (m_ElapsedNextWave >= m_NextWaveDelay) // reset data and go to next wave;
			{
				m_HasSpawnedCount = 0;
				m_ElapsedNextWave = 0.f;
				m_ELapsedSpawnDelay = 0.f;
				
				m_CurrentWave++; 
			}
		}
		
	}


	
}

void EnemySpawner::SpawnEnemys()
{

	m_RunSpawnLoop = true;
	m_HasSpawnedCount = 0;	
}

void EnemySpawner::TestSpawn()
{
	for (int i = 0; i < m_Gridpositions.size();i++)
	{
		auto newOb = objectConstructors::BeeEnemy("Galaga/bee.png", m_Gridpositions[i].screenPos);

		newOb->GetComponent<BeeComponent>()->SetState(BeeStates::Spawning);
		nm_pCurrentScene.Add(newOb);
	}
	
}
