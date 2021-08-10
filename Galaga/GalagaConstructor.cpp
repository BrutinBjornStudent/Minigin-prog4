#include "GalagaConstructor.h"



#include "ActorComponent.h"
#include "AllComponents.h"
#include "BeeComponent.h"
#include "ResourceManager.h"


std::shared_ptr<dae::GameObject> objectConstructors::PlayerProjectile(const std::string& file)
{
	auto newObject = std::make_shared<dae::GameObject>();

	auto texture = new RenderComponent();
	texture->SetTexture(file);
	texture->SetSize(10, 10);
	texture->SetOffset(-5, -5);


	return newObject;
}

std::shared_ptr<dae::GameObject> objectConstructors::BeeEnemy(const std::string& file, glm::vec2 position)
{
	std::shared_ptr<dae::GameObject> newBee = std::make_shared<dae::GameObject>();
	
	auto texture = new RenderComponent();
	texture->SetTexture(file);
	//texture->SetSize(30, 30);
	//texture->SetOffset(-5, -5);
	SDL_Rect source;
	source.x = 0;
	source.y = 0;
	source.h = 16;
	source.w = 16;
	texture->SetSourceRect(source);
	texture->SetRotation(90.0);
	newBee->AddComponent(texture);


	auto sprite = new SpriteComponent(texture, source, 2,1);
	
	BeeComponent* beeComp = new BeeComponent();
	newBee->AddComponent(beeComp);

	
	ActorHitBoxComponent* hitbox = new ActorHitBoxComponent();
	newBee->AddComponent(hitbox);
	
	ActorComponent* actor = new ActorComponent();
	newBee->AddComponent(actor);
	actor->BindHitBoxComponent(hitbox);
	actor->BindRenderComponent(texture);
	actor->Translate(position.x,position.y);
	
	return newBee;
	
}



