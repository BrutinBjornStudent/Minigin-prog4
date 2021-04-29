#pragma once


#include "Observer.h"
#include "algorithm"
#include "vector"

//template <class Subject>
class Subject 
{
public:
	Subject();
	
	void AddObserver(Observer* newObserver)
	{
		m_observers.push_back(newObserver);
		m_numberObservers++;
	}
	void RemoveObserver(Observer* oldObserver)
	{
		auto val = std::remove(m_observers.begin(), m_observers.end(), oldObserver);
		m_numberObservers--;

	}

	void Notify(const dae::GameObject& object, Event event)
	{
		for (int i = 0; i < m_numberObservers; i++)
		{
			m_observers[i]->onNotify(object,event);
		}
	}

private:
	std::vector<Observer*> m_observers;
	int m_numberObservers = 0;
	
};

