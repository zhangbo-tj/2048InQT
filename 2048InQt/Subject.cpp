#include "Subject.h"
#include "Observer.h"


Subject::Subject(){

}


Subject::~Subject(){

}

void Subject::NotifyObservers() {
	for (Observer* observer : observers_) {
		observer->notify();
	}
}

void Subject::RegisterObserver(Observer* observer) {
	observers_.push_back(observer);
}
