
#pragma once
class Observer
{
public:
	Observer();

	virtual void notify() = 0;

	~Observer();
};

