// Definiert das Gerüst eines Algorithmus in einer Methode, 
// während Unterklassen bestimmte Schritte implementieren.

#include <iostream>
#include <string>

struct Abstract {
    void templateMethod() {
        step1();
        step2();
        hook();
    }
    virtual ~Abstract() = default;
protected:
    void step1() { std::cout<<"Schritt 1\n"; }
    virtual void step2() = 0;   // variabel
    virtual void hook() {}      // optional
};

struct Concrete : Abstract {
    void step2() override { std::cout<<"Schritt 2\n"; }
    void hook() override { std::cout<<"Optionale Erweiterung\n"; }
};

int main() {
    Concrete c;
    c.templateMethod();
}
