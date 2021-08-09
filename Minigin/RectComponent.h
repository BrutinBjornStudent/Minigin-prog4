#pragma once
#include <SDL_rect.h>

#include "Component.h"

class RectComponent :
    public BaseComponent
{
public:

	RectComponent();

	void SetRectangle(SDL_Rect rectangle) { m_Rectangle = rectangle; };
	void SetPosition(int x, int y) { m_Rectangle.x = x; m_Rectangle.y = y; };
	void SetSize(int width, int height) { m_Rectangle.w = width; m_Rectangle.h = height; }
	
	void Render() const override;
	void Update(const float ) override {};
protected:
	SDL_Rect m_Rectangle;
};

