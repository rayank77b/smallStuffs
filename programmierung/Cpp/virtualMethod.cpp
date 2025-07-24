#include <iostream>
using namespace std;


/**
 * https://www.geeksforgeeks.org/cpp/virtual-function-cpp/
 * A virtual function (also known as virtual methods) is a member function 
 * that is declared within a base class and is re-defined (overridden) 
 * by a derived class. 
 * 
 * When you refer to a derived class object using 
 * a pointer or a reference to the base class, you can call a virtual 
 * function for that object and execute the derived class's version 
 * of the method.
 * 
 * A virtual function (also known as virtual methods) 
 * is a member function that is declared within a base class and is 
 * re-defined (overridden) by a derived class. When you refer to a 
 * derived class object using a pointer or a reference to the base class, 
 * you can call a virtual function for that object and execute 
 * the derived class's version of the method.
 */

class Base {
public:
    // Virtual function, will be overrided by a derived class
    virtual void display() {
        cout << "Base class display" << endl;
    }
};

class Derived : public Base {
public:
    // Overriding the virtual 
    // function in the derived class
    void display() {
        cout << "Derived class display" << endl;
    }
};

class BaseAbstract {
public:
    // Pure virtual function
    virtual void display() = 0;
};

class D : public BaseAbstract {
public:
    void d2() {  
        cout << "D class d2" << endl;
    }
    void display() {  // if no display() definated, thus D will be Abstract
        cout << "D class display" << endl;
    }
};

class A {
public:
    void display() {    // no virtual, will not overrided by derived class
        cout << "A class display" << endl;
    }
};

class B : public A {
public:
    void display() {
        cout << "B class display" << endl;
    }
};

int main() {
    Base* basePtr;
    Base baseObj;
    Derived derivedObj;

    // BaseAbstract baseAbs;      // abstract class cant be objects
    
    // Base class pointer pointing 
    // to derived class object
    basePtr = &derivedObj;
    
    // Calling the virtual function
    basePtr->display();    // Derived class display  (wegen virtual)
    derivedObj.display();  // Derived class display
    baseObj.display();     // Base class display

    BaseAbstract* bAPtr;
    D d;
    bAPtr = &d;
    bAPtr->display();       // D class display
    d.display();            // D class display
    d.d2();                 // D class d2


    A *aPtr;
    B bOjb;

    aPtr = &bOjb;
    aPtr->display();    // A class display
    bOjb.display();     // B class display

    return 0;
}