#include "MiniginPCH.h"
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"





dae::GameObject::~GameObject()
{

	for (uint32_t i = 0; i < m_pComponents.size(); i++)
	{
		delete m_pComponents[i];
	}
	std::cout << "GameObject Destroyed" << std::endl;
}

void dae::GameObject::Update(const float deltatime)
{
	for (uint32_t i = 0; i < m_pComponents.size(); i++)
	{
		m_pComponents[i]->Update(deltatime);
	}
}


void dae::GameObject::Render() const
{
	for (uint32_t i = 0; i < m_pComponents.size(); i++)
	{
		m_pComponents[i]->Render();
	}
}


//void dae::GameObject::SetTexture(const std::string& filename)
//{
//	m_pTexture = ResourceManager::GetInstance().LoadTexture(filename);
//}
//
//void dae::GameObject::SetPosition(float x, float y)
//{
//
//	m_Transform.SetPosition(x, y, 0.0f);
//}


void dae::GameObject::AddComponent(BaseComponent* myComponent)
{

	
	m_pComponents.push_back(myComponent);
}