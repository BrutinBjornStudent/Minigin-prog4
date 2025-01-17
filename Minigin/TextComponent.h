﻿#pragma once

#include <SDL_pixels.h>
#include "AllComponents.h"
#include <memory>
namespace dae
{
	class Font;
	
	class TextComponent final: public BaseComponent
	{
	public:
		TextComponent(
			const std::string& text, 
			const std::shared_ptr<Font>& font,
			RenderComponent* RendComp);
		~TextComponent() = default;
		
		void Update(float deltaTime) override;
		void Render() const override;

		void SetText(const std::string& text);
		void SetColor(const SDL_Color& color);
	
	protected:
		bool m_NeedsUpdate;
		RenderComponent* nm_pRenderComponent;
		std::string m_Text;
		std::shared_ptr<Font> m_Font;
		SDL_Color m_color;
		
	};
}

