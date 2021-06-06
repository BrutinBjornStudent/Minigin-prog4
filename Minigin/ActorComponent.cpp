#include "MiniginPCH.h"
#include "ActorComponent.h"
#include "glm/geometric.hpp"

ActorComponent::ActorComponent()

{
	m_actorChanged = new Subject();
}

ActorComponent::~ActorComponent()
{

	delete m_actorChanged;
}

// example of changing position
void ActorComponent::Update(float delta)
{
	glm::vec3 positon = m_transform.GetPosition();



	glm::vec3 normalVec = glm::normalize(m_velocity);
	positon += normalVec * delta;
	
	m_transform.SetPosition(positon);

	//reset volocity
	m_velocity = {0,0,0};
}

void ActorComponent::Jump() const
{
	std::cout << "actor jump" << std::endl;
}

void ActorComponent::Die() const
{
	std::cout << "actor should dies" << std::endl;
	if (m_actorChanged)
		m_actorChanged->Notify( Event::player_Died);
}

void ActorComponent::Fire() const
{
	std::cout << "actor is on Fire" << std::endl;
}

void ActorComponent::Duck() const
{
	std::cout << "actor ducks" << std::endl;

	if (m_actorChanged)
		m_actorChanged->Notify(Event::tile_color_change);
	
}

void ActorComponent::Fart() const
{
	std::cout << "actor stinks" << std::endl;
	if (m_actorChanged)
		m_actorChanged->Notify(Event::tile_color_change);

}

void ActorComponent::MoveTo(float x, float y)
{
	m_velocity.x += x;
	m_velocity.y += y;
	
}
