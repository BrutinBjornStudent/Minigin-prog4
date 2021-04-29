#pragma once
#include "Singleton.h"

namespace dae
{
	class GameObject;
	class ObjectManager final : public Singleton<ObjectManager>
	{
	public:
		void Update();
		void Render();
	private:
		friend class Singleton<ObjectManager>;
		ObjectManager() = default;
		std::vector<std::shared_ptr<GameObject> > m_Objects;
	
	};
}

