#pragma once

#include "Transform.h"
#include "Component.h"
#include "structs.h"

class ActorHitBoxComponent :
    public BaseComponent
{
public:
	void Render() const override {};
	void Update(const float ) override{};

	void SetPosition(float x, float y, float z = 0);
	void SetPosition(glm::vec3 pos);

private:
	dae::Transform m_transform;
	Rect m_square;
	
	bool m_isBound;
};

