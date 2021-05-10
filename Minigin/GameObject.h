#pragma once
#include "Transform.h"
#include "SceneObject.h"
#include "Component.h"
#include "Texture2D.h"
#include <vector>

#include "RenderComponent.h"


namespace dae
{
	
	class GameObject
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

		//void SetTexture(const std::string& filename);
		//void SetPosition(float x, float y);
		
		void SetRenderComponent(RenderComponent* rendComp);

		
		template <typename T>
		T* GetComponent();
		void AddComponent(BaseComponent * myComponent);

	protected:
		Transform m_Transform;
		Texture2D* m_pTexture = nullptr;

		RenderComponent* m_pRenderComponent = nullptr;
		std::vector<BaseComponent*> m_pComponents;
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
