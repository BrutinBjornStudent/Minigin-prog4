#pragma once
#include "GameObject.h"
#include "Transform.h"
#pragma warning(push)
#pragma warning(disable:26812)
#pragma warning(disable:26819)
#include "SDL.h"
#pragma warning(pop)
#include <SDL_ttf.h>

namespace dae
{
	class Font;
	class Texture2D;

	class TextObject final : public GameObject
	{
	public:
		void Update(const float deltatime) override;
		void Render() const override;

		void SetText(const std::string& text);
		void SetPosition(float x, float y);
		void SetColor(const SDL_Color color);

		explicit TextObject(const std::string& text, const std::shared_ptr<Font>& font);

		virtual ~TextObject();
		TextObject(const TextObject& other) = delete;
		TextObject(TextObject&& other) = delete;
		TextObject& operator=(const TextObject& other) = delete;
		TextObject& operator=(TextObject&& other) = delete;
	private:
		bool m_NeedsUpdate;
		std::string m_Text;
		Transform m_Transform;
		std::shared_ptr<Font> m_Font;
		std::shared_ptr<Texture2D> m_Texture;
		SDL_Color m_Color;
	};
}
