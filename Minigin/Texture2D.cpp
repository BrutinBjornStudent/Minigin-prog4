#include "MiniginPCH.h"
#include "Texture2D.h"
#pragma warning(push)
#pragma warning(disable:26812)
#pragma warning(disable:26819)
#include "SDL.h"
#pragma warning(pop)

dae::Texture2D::~Texture2D()
{
	std::cout << "Texture popped" << std::endl;
	SDL_DestroyTexture(m_Texture);
}


SDL_Texture* dae::Texture2D::GetSDLTexture() const
{
	return m_Texture;
}

dae::Texture2D::Texture2D(SDL_Texture* texture)
{
	m_Texture = texture;
}
