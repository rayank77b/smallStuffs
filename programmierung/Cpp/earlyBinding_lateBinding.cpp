#include <iostream>
using namespace std;

/**
 * Early Binding and Late Binding
 * In layman's terms, when a function is called in the code, 
 * binding decides which function gets executed based on the context 
 * such as the type of object or the function signature. 
 * 
 * Binding happens at two levels:
 *  - Early Binding: It happens when a function call is resolved 
 *    during the program's compilation. This makes it faster because 
 *    everything is decided early
 *  - Late Binding: It happens with virtual functions where the exact 
 *    function to call is decided at runtime, depending on the actual 
 *    object type. This is slower because the program has to figure 
 *    it out while running.
 */

class base {
public:
    virtual void print() {
        cout << "print base class\n";
    }

    void show() {
        cout << "show base class\n";
    }

    virtual void f2() {
        cout << "f2 base class\n";
    }
};

class derived : public base {
public:
    void print() {
        cout << "print derived class\n";
    }

    void show() {
        cout << "show derived class\n";
    }

    void f2() override {
        cout << "f2 derived override class\n";
    }
};

int main() {
    base* bptr;
    derived d;
    bptr = &d;
    base b;

    // Virtual function, 
    // binded at runtime
    bptr->print();              // print derived class
    b.print();                  // print base class

    // Non-virtual function, 
    // binded at compile time
    bptr->show();               // show base class
    b.show();                   // show base class

    // virtual function, derived override
    // binded at runtime
    bptr->f2();                 // f2 derived override class
    b.f2();                     // f2 base class

    return 0;
}