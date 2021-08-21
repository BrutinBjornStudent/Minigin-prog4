#pragma once
#include <SDL_pixels.h>
#include <glm/detail/type_vec.hpp>

#include "Singleton.h"

struct SDL_Window;
struct SDL_Renderer;
struct SDL_Rect;
namespace dae
{
	class Texture2D;
	/**
	 * Simple RAII wrapper for the SDL renderer
	 */
	class Renderer final : public Singleton<Renderer>
	{
	public:
		void Init(SDL_Window* window);
		void Render();
		void Destroy();

		void RenderTexture(const Texture2D& texture, float x, float y, const double angle = 0) const;
		void RenderTexture(const Texture2D& texture, float x, float y, int width, int height ,const double angle = 0) const;
		void RenderTexture(const Texture2D& texture, float x, float y, int width, int height, const SDL_Rect& srcRect, const double angle = 0) const;

		
		void RenderRect(const SDL_Rect* rectangle) const;
		void RenderRect(const SDL_Rect* rectangle, const SDL_Color color) const;

		void RenderFullRect(const SDL_Rect* rect, const SDL_Color color) const;
		
		glm::ivec2 GetWindowSize() const;
		SDL_Renderer* GetSDLRenderer() const { return m_Renderer; }
	private:

		SDL_Renderer* m_Renderer{};
		SDL_Window* m_pWindow = nullptr;


		bool m_ShowDemo{ true };
	};


}

