#include "EnemySpawner.h"

#include "ActorComponent.h"
#include "BeeComponent.h"
#include "BezierMoveComponent.h"
#include "GalagaConstructor.h"
#include "Scene.h"

EnemySpawner::EnemySpawner(glm::vec2 startCenterPos, glm::vec2 SizeOfEnemy, glm::vec2 WindowSize, dae::Scene& currentScene)
	: m_SizeOfEnemy(SizeOfEnemy)
	, m_GameSize(WindowSize)
	, m_RunSpawnLoop(false)
	, m_HasSpawnedCount(0)
	, m_ToSpawn(8)
	, m_SpawnDelay(0)
	, m_ELapsedSpawnDelay(0)
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

	//TODO replace with JSON reader maybe
	m_FirstWave.push_back(m_Gridpositions[44]);
	m_FirstWave.push_back(m_Gridpositions[45]);
	m_FirstWave.push_back(m_Gridpositions[34]);
	m_FirstWave.push_back(m_Gridpositions[35]);
	m_FirstWave.push_back(m_Gridpositions[24]);
	m_FirstWave.push_back(m_Gridpositions[25]);
	m_FirstWave.push_back(m_Gridpositions[14]);
	m_FirstWave.push_back(m_Gridpositions[15]);

	m_Waves.push_back(m_FirstWave);

	m_SecondWave.push_back(m_Gridpositions[23]);
	m_SecondWave.push_back(m_Gridpositions[26]);
	m_SecondWave.push_back(m_Gridpositions[13]);
	m_SecondWave.push_back(m_Gridpositions[16]);
	m_SecondWave.push_back(m_Gridpositions[3]);
	m_SecondWave.push_back(m_Gridpositions[4]);
	m_SecondWave.push_back(m_Gridpositions[5]);
	m_SecondWave.push_back(m_Gridpositions[6]);
	m_Waves.push_back(m_SecondWave);
	
	m_thirdWave.push_back(m_Gridpositions[11]);
	m_thirdWave.push_back(m_Gridpositions[12]);
	m_thirdWave.push_back(m_Gridpositions[21]);
	m_thirdWave.push_back(m_Gridpositions[22]);
	m_thirdWave.push_back(m_Gridpositions[17]);
	m_thirdWave.push_back(m_Gridpositions[18]);
	m_thirdWave.push_back(m_Gridpositions[27]);
	m_thirdWave.push_back(m_Gridpositions[28]);
	m_Waves.push_back(m_thirdWave);

	m_ForthWave.push_back(m_Gridpositions[32]);
	m_ForthWave.push_back(m_Gridpositions[33]);
	m_ForthWave.push_back(m_Gridpositions[36]);
	m_ForthWave.push_back(m_Gridpositions[37]);
	m_ForthWave.push_back(m_Gridpositions[42]);
	m_ForthWave.push_back(m_Gridpositions[43]);
	m_ForthWave.push_back(m_Gridpositions[46]);
	m_ForthWave.push_back(m_Gridpositions[47]);
	m_Waves.push_back(m_ForthWave);

	m_FifthWave.push_back(m_Gridpositions[30]);
	m_FifthWave.push_back(m_Gridpositions[31]);
	m_FifthWave.push_back(m_Gridpositions[40]);
	m_FifthWave.push_back(m_Gridpositions[41]);
	m_FifthWave.push_back(m_Gridpositions[38]);
	m_FifthWave.push_back(m_Gridpositions[39]);
	m_FifthWave.push_back(m_Gridpositions[48]);
	m_FifthWave.push_back(m_Gridpositions[49]);
	m_Waves.push_back(m_FifthWave);
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
