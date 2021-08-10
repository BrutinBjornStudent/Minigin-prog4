#pragma once
#include "Component.h"
#include "RenderComponent.h"


// manages sprites
class SpriteComponent :
    public BaseComponent
{
public:

	SpriteComponent(RenderComponent* renderRef,SDL_Rect Startsource, int xsprites, int yprites);
	void Update(const float deltatime) override;

	void Render() const override {};
	void SetXSprite(int x);
	void setYSprite(int y);

private:

	RenderComponent* nm_pRenderComp;

	SDL_Rect m_source;

	int m_maxxSprites;
	int m_currentX;
	
	int m_maxySprites;
	int m_currentY;

	int m_spriteheight;
	int m_spritewidth;

	bool m_needsUpdate;

	
	
	
};

