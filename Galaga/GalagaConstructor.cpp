#include "GalagaConstructor.h"
#include "ObjectConstructors.h"


#include "ActorComponent.h"
#include "AllComponents.h"
#include "BeeComponent.h"
#include "BezierMoveComponent.h"
#include "BulletComponent.h"
#include "GunComponent.h"
#include "HitBoxComponent.h"
#include "HitBoxManager.h"
#include "HurtboxComponent.h"




std::shared_ptr<dae::GameObject> objectConstructors::Projectile(const std::string& file,glm::ivec2 position, CollisionID colision, glm::vec2 dir)
{
	auto newObject = std::make_shared<dae::GameObject>();

	auto texture = new RenderComponent();
	texture->SetTexture(file);
	texture->SetSize(30, 30);
	texture->SetOffset(-15, -15);
	texture->SetPosition(static_cast<float>(position.x),static_cast<float>(position.y),0);
	newObject->AddComponent(texture);

	auto HurtBox = new HurtboxComponent(position,glm::ivec2(10,10),colision);
	
	HurtBox->SetOffset(-5, -5);
	HurtBox->SetPosition(static_cast<float>(position.x),static_cast<float>(position.y),0);
	newObject->AddComponent(HurtBox);
	
	BulletComponent* bulletLogic = new BulletComponent(position , dir,texture,HurtBox,*newObject);
	newObject->AddComponent(bulletLogic);
	return newObject;


	
}

std::shared_ptr<dae::GameObject> objectConstructors::BeeEnemy(const std::string& file, glm::ivec2 position)
{
	auto newBee = std::make_shared<dae::GameObject>();

	//Texture
	auto texture = new RenderComponent();
	texture->SetTexture(file);
	texture->SetSize(30, 30);
	texture->SetOffset(-15, -15);
	texture->SetRotation(180.0);
	texture->SetPosition(static_cast<float>(position.x),static_cast<float>(position.y));
	newBee->AddComponent(texture);


	SDL_Rect source;
	source.x = 0;
	source.y = 0;
	source.h = 16;
	source.w = 16; //SpriteManager
	auto sprite = new SpriteComponent(texture, source, 2,1);
	newBee->AddComponent(sprite);


	//Hitbox 
	auto hitbox = new HitBoxComponent(position,glm::ivec2(30,30),Enemy);
	hitbox->SetSize(glm::vec2(30, 30));
	hitbox->SetOffset(-15, -15);
	dae::HitBoxManager::GetInstance().addHitBox(hitbox);
	newBee->AddComponent(hitbox);

	
	//ActorComponent
	auto actor = new ActorComponent();
	newBee->AddComponent(actor);
	actor->BindRenderComponent(texture);
	actor->BindHitBoxComponent(hitbox);
	actor->Translate(static_cast<float>(position.x),static_cast<float>(position.y));
	
	//BeeComponent
	auto beeComp = new BeeComponent(*newBee);
	newBee->AddComponent(beeComp);
	beeComp->BindActorComp(actor);
	beeComp->BindSpriteComp(sprite);
	beeComp->BindHitBoxComponent(hitbox);
	beeComp->BindSpriteComp(texture);

	//BrazierComponent
	//auto Bazier = new BezierMoveComponent;
	
	//newBee->AddComponent(Bazier);


	
	return newBee;
	
}


// creates Basic actor and adds a GunComponent, HitBoxComponent
std::shared_ptr<dae::GameObject> objectConstructors::GalagaPlayer(const std::string file, glm::ivec2 size, int lives)
{
	auto galaga = BasicActor(lives);
	galaga->GetComponent<RenderComponent>()->SetTexture(file);
	galaga->GetComponent<RenderComponent>()->SetSize(size.x,size.y);
	galaga->GetComponent<RenderComponent>()->SetOffset(-static_cast<int>(size.x / 2), -static_cast<int>(size.y / 2));


	auto gun = new GunComponent();
	gun->BindToActor(galaga->GetComponent<ActorComponent>());
	galaga->AddComponent(gun);


	const auto hitBox = new HitBoxComponent(glm::ivec2(0,0),glm::ivec2(30,30),Player);
	galaga->AddComponent(hitBox);
	dae::HitBoxManager::GetInstance().addHitBox(hitBox);
	galaga->GetComponent<ActorComponent>()->BindHitBoxComponent(hitBox);


	
	
	
	return galaga;
}



