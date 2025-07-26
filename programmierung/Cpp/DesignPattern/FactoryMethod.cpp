#include <iostream>
#include <memory>

//Definiert eine Schnittstelle zur Erzeugung von Objekten, 
// überlässt aber den Unterklassen die Entscheidung, 
// welche Klasse instanziiert wird.

// Produkt-Schnittstelle
struct Product {
    virtual void use() = 0;
    virtual ~Product() = default;
};

// Konkrete Produkte
struct ConcreteProductA : Product {
    void use() override { std::cout << "Product A verwendet\n"; }
};
struct ConcreteProductB : Product {
    void use() override { std::cout << "Product B verwendet\n"; }
};

// Creator mit Factory Method
struct Creator {
    virtual std::unique_ptr<Product> factoryMethod() const = 0;
    void operation() {
        auto prod = factoryMethod();
        prod->use();
    }
    virtual ~Creator() = default;
};

struct ConcreteCreatorA : Creator {
    std::unique_ptr<Product> factoryMethod() const override {
        return std::make_unique<ConcreteProductA>();
    }
};

struct ConcreteCreatorB : Creator {
    std::unique_ptr<Product> factoryMethod() const override {
        return std::make_unique<ConcreteProductB>();
    }
};

int main() {
    std::unique_ptr<Creator> creator = std::make_unique<ConcreteCreatorA>();
    creator->operation(); // gibt aus: "Product A verwendet"
    creator = std::make_unique<ConcreteCreatorB>();
    creator->operation(); // gibt aus: "Product B verwendet"
}