#include "MiniginPCH.h"
#include "ObjectConstructors.h"

#include "ResourceManager.h"
#include "TextComponent.h"

std::shared_ptr<dae::GameObject> objectConstructors::TextObject(const std::string& file, unsigned int size,
	const std::string& text
, float Xpos, float Ypos )
{
	auto textObject = std::make_shared<dae::GameObject>();
	RenderComponent* textRenderComp = new RenderComponent;
	textRenderComp->setPosition(Xpos, Ypos);

	auto font3 = dae::ResourceManager::GetInstance().LoadFont(file, size);
	dae::TextComponent* textComp = new dae::TextComponent(text, font3, textRenderComp);
	textObject->AddComponent(textRenderComp);
	textObject->AddComponent(textComp);
	
	return textObject;
}

std::shared_ptr<dae::GameObject> objectConstructors::RenderObject(const std::string& TexturePath
 ,  float Xpos ,  float Ypos )
{
	auto newObject = std::make_shared<dae::GameObject>();
	RenderComponent* rendercomp = new RenderComponent;
	rendercomp->SetTexture(TexturePath);
	rendercomp->setPosition(Xpos, Ypos);
	newObject->AddComponent(rendercomp);
	return newObject;
}



dae::GameObject objectConstructors::LivesBar()
{
	return dae::GameObject();
}
