#pragma once
#include "Component.h"
#include "structs.h"
class HitBoxComponent :
    public BaseComponent
{
public:

	
	void Render() const override{};
	void Update(const float ) override{};

private:
	Rect m_rect;
};

