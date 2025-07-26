// Stellt sicher, dass es nur eine Instanz einer Klasse gibt, 
// und bietet globalen Zugriff darauf.

#include <iostream>

class Singleton {
public:
    static Singleton& instance() {
        static Singleton s;
        return s;
    }
    void doSomething() { std::cout<<"Singleton aktiv\n"; }
private:
    Singleton() = default;
    ~Singleton() = default;
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
};

int main() {
    Singleton::instance().doSomething();
}