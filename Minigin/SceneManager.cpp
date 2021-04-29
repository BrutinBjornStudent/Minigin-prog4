#include "MiniginPCH.h"
#include "SceneManager.h"
#include "Scene.h"

void dae::SceneManager::Update(float deltaTime)
{
	for(std::shared_ptr<Scene>& scene : m_Scenes)
	{
		scene->Update(deltaTime);
	}
}

void dae::SceneManager::Render()
{
	for (std::shared_ptr<Scene>& scene : m_Scenes)
	{
		scene->Render();
	}
}

std::shared_ptr<dae::Scene> dae::SceneManager::CreateScene(const std::string& name)
{
	const auto scene = std::shared_ptr<Scene>(new Scene(name));
	m_Scenes.push_back(scene);
	return (scene);
}
