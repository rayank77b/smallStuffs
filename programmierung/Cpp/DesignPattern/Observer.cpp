// Ein Subjekt hält eine Liste von Abonnenten und benachrichtigt 
// sie bei Zustandsänderungen.

#include <vector>
#include <algorithm>
#include <iostream>

struct Observer {
    virtual void update(int state) = 0;
    virtual ~Observer() = default;
};

struct Subject {
    void attach(Observer* o) { observers.push_back(o); }
    void detach(Observer* o) { 
        observers.erase(std::remove(observers.begin(), observers.end(), o), observers.end());
    }
    void setState(int s) {
        state = s;
        notify();
    }
private:
    void notify() {
        for (auto* o : observers) o->update(state);
    }
    int state{0};
    std::vector<Observer*> observers;
};

struct ConcreteObserver : Observer {
    void update(int state) override {
        std::cout << "Observer erhalten Zustand: " << state << "\n";
    }
};

struct ConcreteObserver2 : Observer {
    void update(int state) override {
        std::cout << "Observer 2 erhalten Zustand: " << state << "\n";
    }
};

int main() {
    Subject subj;
    ConcreteObserver obs1, obs2;
    ConcreteObserver2 obs3;
    subj.attach(&obs1);
    subj.attach(&obs2);
    subj.setState(42);
    // beide Observer drucken: "Observer erhalten Zustand: 42"
    subj.detach(&obs1);
    subj.attach(&obs3);
    subj.setState(103);
    
}
