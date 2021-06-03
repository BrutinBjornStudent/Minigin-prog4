#include "MiniginPCH.h"
#include "QBertComponent.h"

QBertComponent::QBertComponent()

{
	m_actorChanged = new Subject();
}

QBertComponent::~QBertComponent()
{
	if (m_actorChanged)
	delete m_actorChanged;
}

void QBertComponent::Jump() const
{
	std::cout << "QBert jump" << std::endl;
}

void QBertComponent::Die() const
{
	std::cout << "Qbert should dies" << std::endl;
	if (m_actorChanged)
		m_actorChanged->Notify( Event::player_Died);
}

void QBertComponent::Fire() const
{
	std::cout << "Qbert is on Fire" << std::endl;
}

void QBertComponent::Duck() const
{
	std::cout << "QBert ducks" << std::endl;

	if (m_actorChanged)
		m_actorChanged->Notify(Event::tile_color_change);
	
}

void QBertComponent::Fart() const
{
	std::cout << "QBert stinks" << std::endl;
	if (m_actorChanged)
		m_actorChanged->Notify(Event::tile_color_change);

}
