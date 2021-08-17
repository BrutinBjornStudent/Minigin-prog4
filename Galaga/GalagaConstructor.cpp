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
	texture->SetPosition(float(position.x),float(position.y),0);
	newObject->AddComponent(texture);

	auto HurtBox = new HurtboxComponent(position,glm::ivec2(10,10),colision);
	
	HurtBox->SetOffset(-5, -5);
	HurtBox->SetPosition(float(position.x),float(position.y),0);
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
	actor->Translate(float(position.x),float(position.y));
	
	//BeeComponent
	auto beeComp = new BeeComponent(*newBee);
	newBee->AddComponent(beeComp);
	beeComp->BindActorComp(actor);
	beeComp->BindSpriteComp(sprite);
	beeComp->BindHitBoxComponent(hitbox);
	beeComp->BindSpriteComp(texture);

	//BrazierComponent
	auto Bazier = new BezierMoveComponent;
	
	newBee->AddComponent(Bazier);


	
	return newBee;
	
}


// creates Basic actor and adds a GunComponent, HitBoxComponent
std::shared_ptr<dae::GameObject> objectConstructors::GalagaPlayer(const std::string file, glm::ivec2 size, int lives)
{
	auto Galaga = BasicActor(lives);
	Galaga->GetComponent<RenderComponent>()->SetTexture(file);
	Galaga->GetComponent<RenderComponent>()->SetSize(size.x,size.y);
	Galaga->GetComponent<RenderComponent>()->SetOffset(-int(size.x/2), -int(size.y/2));


	auto gun = new GunComponent();
	gun->BindToActor(Galaga->GetComponent<ActorComponent>());
	Galaga->AddComponent(gun);


	
	auto hitBox = new HitBoxComponent(glm::ivec2(0,0),glm::ivec2(30,30),Player);
	Galaga->AddComponent(hitBox);
	dae::HitBoxManager::GetInstance().addHitBox(hitBox);
	Galaga->GetComponent<ActorComponent>()->BindHitBoxComponent(hitBox);


	
	
	
	return Galaga;
}



