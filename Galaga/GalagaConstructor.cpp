#include "GalagaConstructor.h"



#include "ActorComponent.h"
#include "AllComponents.h"
#include "BeeComponent.h"
#include "BulletComponent.h"
#include "HitBoxComponent.h"
#include "HitBoxManager.h"
#include "HurtboxComponent.h"


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
	HurtBox->SetSize(glm::ivec2(30,30));
	HurtBox->SetOffset(-15, -15);
	HurtBox->SetPosition(float(position.x),float(position.y),0);
	newObject->AddComponent(HurtBox);
	
	BulletComponent* bulletLogic = new BulletComponent(position , glm::vec2(0.f,-10.f),texture,HurtBox,*newObject);
	newObject->AddComponent(bulletLogic);
	return newObject;


	
}

std::shared_ptr<dae::GameObject> objectConstructors::BeeEnemy(const std::string& file, glm::ivec2 position)
{
	auto newBee = std::make_shared<dae::GameObject>();
	
	auto texture = new RenderComponent();
	texture->SetTexture(file);
	texture->SetSize(30, 30);
	texture->SetOffset(-15, -15);
	texture->SetRotation(180.0);

	newBee->AddComponent(texture);


	SDL_Rect source;
	source.x = 0;
	source.y = 0;
	source.h = 16;
	source.w = 16;
	auto sprite = new SpriteComponent(texture, source, 2,1);
	newBee->AddComponent(sprite);

	auto hitbox = new HitBoxComponent(position,glm::ivec2(30,30));
	hitbox->SetSize(glm::vec2(30, 30));
	hitbox->SetOffset(-15, -15);
	dae::HitBoxManager::GetInstance().addHitBox(hitbox);

	newBee->AddComponent(hitbox);
	
	
	auto actor = new ActorComponent();
	newBee->AddComponent(actor);

	actor->BindRenderComponent(texture);
	actor->BindHitBoxComponent(hitbox);
	actor->Translate(float(position.x),float(position.y));
	
	
	auto beeComp = new BeeComponent(*newBee);
	newBee->AddComponent(beeComp);

	beeComp->LinkSpriteComp(sprite);
	beeComp->BindHitBoxComponent(hitbox);
	
	return newBee;
	
}



