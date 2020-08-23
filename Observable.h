#pragma once
#include "Observer.h"

class Observable
{
public:
	
	Observable(Observer* observer) {
		m_observers = observer;
		
	
	}
	// set notice for observer class
	virtual void notify(string mass)
	{
		m_observers->update(mass);
	}

protected:
	Observer* m_observers;
};