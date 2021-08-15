#include "MiniginPCH.h"
#include "Scene.h"
#include "GameObject.h"
#include <algorithm>

using namespace dae;

unsigned int Scene::m_IdCounter = 0;

Scene::Scene(const std::string& name) : m_Name(name) {}

Scene::~Scene() = default;

void Scene::Add(const std::shared_ptr<GameObject>& object)
{
	m_Objects.push_back(object);
}

void Scene::AddInRun(const std::shared_ptr<GameObject>& object)
{
	m_objectsInRun.push_back(object);
}

void Scene::Update(float deltatime)
{
	for (int i = 0; i < m_objectsInRun.size(); ++i)
	{
		m_Objects.push_back(m_objectsInRun[i]);
	}
	m_objectsInRun.clear();
	
	for(auto& object : m_Objects)
	{
		object->Update(deltatime);
		
	}
	for (int i = 0; i < m_Objects.size();++i)
	{
		if(m_Objects[i]->IsMarkedForDeletion())
		{
			m_Objects[i].swap(m_Objects.back());
			m_Objects.pop_back();
		}
	}

	
	
}

void Scene::Render() const
{
	for (const auto& object : m_Objects)
	{
		object->Render();
	}
}

