#pragma once
#include "Transform.h"
#include "SceneObject.h"
#include "Component.h"
#include "Texture2D.h"
#include <vector>
#include <iostream>
#include "RenderComponent.h"


namespace dae
{
	
	class GameObject final
	{
	public:
		GameObject() { std::cout << "Gd contstruct" << std::endl; };
		virtual ~GameObject();

		GameObject(const GameObject& other) = default;
		GameObject(GameObject&& other) = default;
		GameObject& operator=(const GameObject& other) = default;
		GameObject& operator=(GameObject&& other) = default;

		virtual void Update( const float Deltatime) ;
		virtual void Render() const;
		
		void SetRenderLayer(int Layer)
		{
			m_RenderLayerChanged = true;
			m_RenderLayer = Layer;
		};
		bool isLayerChanged() { return m_RenderLayerChanged; };
		void SetLayerChanged(bool Changed = false) { m_RenderLayerChanged = Changed; };
		
		void MarkForDeletion(bool ShouldBeDeleted = true) { m_MarkForDeletion = ShouldBeDeleted; }
		bool IsMarkedForDeletion() { return m_MarkForDeletion; };
		
		int getRenderLayer() { return m_RenderLayer; };
		template <typename T>
		T* GetComponent();
		void AddComponent(BaseComponent * myComponent);
	protected:

		std::vector<BaseComponent*> m_pComponents;

		int m_RenderLayer = 0;
		bool m_RenderLayerChanged = false;
		bool m_MarkForDeletion = false;
		
	};


	//component list logic
	template<typename T>
	T* GameObject::GetComponent()
	{
		for (BaseComponent* bc : m_pComponents)
		{
			if (dynamic_cast<T*>(bc))
				return(T*)bc;
		}
		return nullptr;
	}

	


}
