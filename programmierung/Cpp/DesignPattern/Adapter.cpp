// Ermöglicht die Zusammenarbeit von inkompatiblen 
// Interfaces durch eine Wrapper‑Klasse.

#include <iostream>
#include <string>

// Altes Interface
struct OldPrinter {
    void oldPrint(const std::string& s) {
        std::cout<<"Alte Ausgabe: "<<s<<"\n";
    }
};

// Neues Interface
struct IPrinter {
    virtual void print(const std::string&) = 0;
    virtual ~IPrinter() = default;
};

// Adapter
struct PrinterAdapter : IPrinter {
    PrinterAdapter(OldPrinter* p) : old(p) {}
    void print(const std::string& s) override {
        old->oldPrint(s);
    }
private:
    OldPrinter* old;
};

int main() {
    OldPrinter legacy;
    PrinterAdapter adapter(&legacy);
    adapter.print("Hallo Adapter");
}
