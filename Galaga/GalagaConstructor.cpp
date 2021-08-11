#include "GalagaConstructor.h"



#include "ActorComponent.h"
#include "AllComponents.h"
#include "BeeComponent.h"
#include "BulletComponent.h"
#include "HitBoxComponent.h"
#include "HitBoxManager.h"
#include "HurtboxComponent.h"
#include "ResourceManager.h"


std::shared_ptr<dae::GameObject> objectConstructors::PlayerProjectile(const std::string& file,glm::ivec2 position)
{
	auto newObject = std::make_shared<dae::GameObject>();

	auto texture = new RenderComponent();
	texture->SetTexture(file);
	texture->SetSize(30, 30);
	texture->SetOffset(-15, -15);
	texture->SetPosition(float(position.x),float(position.y),0);
	newObject->AddComponent(texture);

	auto HurtBox = new HurtboxComponent(position,glm::ivec2(30,30));
	HurtBox->SetOffset(-15, -15);
	HurtBox->SetSize(glm::ivec2(30,30));
	newObject->AddComponent(HurtBox);
	
	BulletComponent* bulletLogic = new BulletComponent(position , glm::vec2(0.f,-10.f),texture,HurtBox);
	newObject->AddComponent(bulletLogic);
	
	return newObject;


	
}

std::shared_ptr<dae::GameObject> objectConstructors::BeeEnemy(const std::string& file, glm::ivec2 position)
{
	std::shared_ptr<dae::GameObject> newBee = std::make_shared<dae::GameObject>();
	
	auto texture = new RenderComponent();
	texture->SetTexture(file);
	texture->SetSize(30, 30);

	SDL_Rect source;
	source.x = 0;
	source.y = 0;
	source.h = 16;
	source.w = 16;
	texture->SetSourceRect(source);
	texture->SetRotation(180.0);
	
	newBee->AddComponent(texture);


	auto sprite = new SpriteComponent(texture, source, 2,1);
	newBee->AddComponent(sprite);
	
	BeeComponent* beeComp = new BeeComponent();
//	beeComp->LinkRenderComp(texture);
	beeComp->LinkSpriteComp(sprite);
	newBee->AddComponent(beeComp);

	
	HitBoxComponent* hitbox = new HitBoxComponent(Rect(position.x,position.y,30,30));
	newBee->AddComponent(hitbox);
	dae::HitBoxManager::GetInstance().addHitBox(hitbox);
	
	ActorComponent* actor = new ActorComponent();
	newBee->AddComponent(actor);
	actor->BindRenderComponent(texture);
	actor->Translate(float(position.x),float(position.y));
	
	return newBee;
	
}



