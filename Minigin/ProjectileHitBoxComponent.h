#pragma once

#include "Component.h"
#include "structs.h"
#include "Transform.h"


class ProjectileHitBoxComponent :
    public BaseComponent
{
public:

	void Render() const override{};
	void Update(const float deltatime) override;

	void SetPosition(float x, float y, float z = 0);
	void SetPosition(glm::vec3 pos);
private:
	dae::Transform m_transform;
	rect m_square;
};

