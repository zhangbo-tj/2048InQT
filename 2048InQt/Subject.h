#pragma once

#include <vector>

class Observer;
class Subject
{
public:
	Subject();
	void NotifyObservers();
	void RegisterObserver(Observer* observer);

	~Subject();

private:
	std::vector<Observer*> observers_;
};

