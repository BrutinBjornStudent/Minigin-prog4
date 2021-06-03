#include "MiniginPCH.h"
#include "QBert.h"

QBert::QBert()
{
	m_ActorChanged = new Subject();
}

QBert::~QBert()
{
	delete m_ActorChanged;
	m_ActorChanged = nullptr;
}

Subject* QBert::GetSubject() const
{
	return m_ActorChanged;
}



void QBert::Jump()
{
	std::cout << "QBert jump" << std::endl;
	
}


void QBert::Die()
{
	std::cout << "Qbert should dies" << std::endl;
//	m_ActorChanged->Notify(*this,Event::player_Died);

}

void QBert::Fire()
{
	std::cout << "Qbert is on Fire" << std::endl;
}

void QBert::Duck()
{
	std::cout << "QBert ducks" << std::endl;
}

void QBert::Fart()
{
	std::cout <<  "QBert stinks" << std::endl;
}
