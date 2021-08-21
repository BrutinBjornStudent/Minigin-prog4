#include "MiniginPCH.h"
#include "ActorComponent.h"

#include "HurtboxComponent.h"
#include "glm/geometric.hpp"

ActorComponent::ActorComponent()
	:m_velocity(0, 0)
{
	m_actorChanged = new Subject();
}

ActorComponent::~ActorComponent()
{

	delete m_actorChanged;
}

// example of changing position
void ActorComponent::Update(const float delta)
{
	glm::vec2 position = m_transform.GetPosition();
	//std::cout << position.x << ":" << position.y << ":actor pos" << std::endl;
	if (glm::length(m_velocity) > 0.f)
	{
		glm::vec2 normalVec = glm::normalize(m_velocity);
		position += m_speed * normalVec * delta;
		
	}
	m_transform.SetPosition(position.x,position.y);

	
	if (nm_pBoundRenderComp != nullptr)
	{
		nm_pBoundRenderComp->SetPosition(m_transform.GetPosition());
	}

	if (nm_pHitboxComp != nullptr)
	{
		nm_pHitboxComp->SetPosition(m_transform.GetPosition());
	}
	if (nm_pHurtBoxComp != nullptr)
		nm_pHurtBoxComp->SetPosition(m_transform.GetPosition());

	//reset volocity

	m_velocity = {0,0};
	
}

void ActorComponent::Jump() const
{
	std::cout << "actor jump" << std::endl;
}

void ActorComponent::Die() const
{
	std::cout << "actor should dies" << std::endl;
	//if (m_actorChanged)
	//	m_actorChanged->Notify( Event::player_Died);
}

void ActorComponent::Fire() const
{
	std::cout << "actor is on Fire" << std::endl;
}

void ActorComponent::Duck() const
{
	std::cout << "actor ducks" << std::endl;

	//if (m_actorChanged)
	//	m_actorChanged->Notify(Event::tile_color_change);
	
}

void ActorComponent::Fart() const
{
	std::cout << "actor stinks" << std::endl;
	//if (m_actorChanged)
	//	m_actorChanged->Notify(Event::tile_color_change);

}

void ActorComponent::SetVelocity(float x, float y)
{
	m_velocity.x += x;
	m_velocity.y += y;
	
}

void ActorComponent::Translate(float x, float y)
{
	m_transform.SetPosition(x, y);
}


