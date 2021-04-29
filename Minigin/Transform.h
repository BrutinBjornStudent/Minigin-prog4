#pragma once
//#pragma warning(push)
#pragma warning (disable:4201)
#include <glm/vec3.hpp>
//#pragma warning(pop)

#include "Component.h"

namespace dae
{
	
	class Transform final :public BaseComponent
	{
	public:
		void Update(const float ) override {};
		void Render() const override {};
		
		const glm::vec3& GetPosition() const { return m_Position; }
		void SetPosition(float x, float y, float z);

	private:
		glm::vec3 m_Position;
	};
}
