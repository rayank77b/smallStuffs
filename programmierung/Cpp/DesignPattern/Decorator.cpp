// Erweitert Objekte zur Laufzeit um Verantwortlichkeiten, 
// indem man Wrapper-Klassen verwendet.

#include <iostream>

struct Component {
    virtual void operation() = 0;
    virtual ~Component() = default;
};

struct ConcreteComponent : Component {
    void operation() override { std::cout<<"Basis-Operation\n"; }
};

struct Decorator : Component {
    Decorator(Component* c) : comp(c) {}
    void operation() override {
        comp->operation();          // Original
        extraBehavior();           // Zusatz
    }
    void extraBehavior() { std::cout<<"Zusätzliche Funktion\n"; }
private:
    Component* comp;
};

int main() {
    ConcreteComponent base;
    Decorator decorated(&base);
    decorated.operation();
    // Ausgabe:
    // Basis-Operation
    // Zusätzliche Funktion
}
