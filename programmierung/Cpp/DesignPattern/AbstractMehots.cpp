#include <iostream>
#include <memory>

//Erweitert die Factory Method um die Erzeugung ganzer Familien verwandter Produkte.

// Produktfamilie
struct Button { virtual void paint() = 0; };
struct Checkbox { virtual void paint() = 0; };

struct WinButton : Button { void paint() override { std::cout<<"WinButton\n"; }};
struct MacButton : Button { void paint() override { std::cout<<"MacButton\n"; }};
struct WinCheckbox : Checkbox { void paint() override { std::cout<<"WinCheckbox\n"; }};
struct MacCheckbox : Checkbox { void paint() override { std::cout<<"MacCheckbox\n"; }};

// Abstract Factory
struct GUIFactory {
    virtual std::unique_ptr<Button> createButton() = 0;
    virtual std::unique_ptr<Checkbox> createCheckbox() = 0;
    virtual ~GUIFactory() = default;
};

struct WinFactory : GUIFactory {
    auto createButton()   -> std::unique_ptr<Button>   override { return std::make_unique<WinButton>(); }
    auto createCheckbox()-> std::unique_ptr<Checkbox> override { return std::make_unique<WinCheckbox>(); }
};

struct MacFactory : GUIFactory {
    auto createButton()   -> std::unique_ptr<Button>   override { return std::make_unique<MacButton>(); }
    auto createCheckbox()-> std::unique_ptr<Checkbox> override { return std::make_unique<MacCheckbox>(); }
};

void client(GUIFactory& f) {
    auto b = f.createButton();
    auto c = f.createCheckbox();
    b->paint(); c->paint();
}

int main() {
    WinFactory win;
    client(win); // WinButton, WinCheckbox
    MacFactory mac;
    client(mac); // MacButton, MacCheckbox
}