#include "GunComponent.h"
#include "GalagaConstructor.h"
#include "Scene.h"
#include "SceneManager.h"

void GunComponent::Fire()
{
	if (m_ShotDelay <= m_ElapsedTime)
	{
		m_ElapsedTime = 0.f;
		auto pos = nm_pActor->GetPosition();

		auto scene = dae::SceneManager::GetInstance().GetActiveScene();
		
		auto bullet =objectConstructors::Projectile("Galaga/PlayerProjectile.png", glm::vec2(pos.x, pos.y),Enemy,glm::vec2(0,-100));

		scene->AddInRun(bullet);
	}
}

void GunComponent::Update(const float deltaTime)
{
	if (m_ShotDelay >= m_ElapsedTime)
		m_ElapsedTime += deltaTime;	
}
