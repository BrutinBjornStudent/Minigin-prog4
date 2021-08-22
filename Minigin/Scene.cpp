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
	bool RunCleanup = false;
	bool RunSort = false;
	
	for (int i = 0; i <int( m_objectsInRun.size()); ++i)
	{
		m_Objects.push_back(m_objectsInRun[i]);
		RunSort = true;
	}
	m_objectsInRun.clear();


	for(auto& object : m_Objects)
	{
		object->Update(deltatime);
		if (object->IsMarkedForDeletion())
			RunCleanup = true;
		if (object->isLayerChanged())
			RunSort = true;

	}

	

	if (RunCleanup)
	{
		for (int i = 0; i < int(m_Objects.size()); ++i)
		{
			if(m_Objects[i]->IsMarkedForDeletion())
			{
				m_Objects[i].swap(m_Objects.back());
				m_Objects.pop_back();
			}
		}
		RunSort = true;
	}
	
	if (RunSort)
	{
		std::sort(m_Objects.begin(), m_Objects.end(), []
		(const std::shared_ptr<dae::GameObject>& a, const std::shared_ptr<dae::GameObject>& b)
			{
				return a->getRenderLayer() < b->getRenderLayer();
			});
		for (auto& object : m_Objects)
		{
			object->SetLayerChanged();
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

