#include <iostream>
#include <string>

using namespace std;

template <typename T>
void swapV(T &t1, T &t2) {
    T tmp = t1;
    t1=t2;
    t2=tmp;
}

template <typename T1, typename T2>
class Pairme {
    T1 first;
    T2 second;
public:
    Pairme(T1 f1, T2 f2) : first(f1), second(f2) {}
    T1 getFirst() const {return first; }
    T2 getSecond() const {return second; }
    void setFirst(T1 f) { first = f; }
    void setSecond(T2 s) { second = s; } 
};

template <typename T>
class Storage {
    T value;
public:
    Storage(T v) : value(v) {}
    void describe() const {
        std::cout<<"descr: "<<value<<std::endl;
    }
};

template <>
class Storage<char> {
    char value;
public: 
    Storage(char c) : value(c) {}
    void describe() const {
        std::cout<<"char: "<<value<<" acii: "<<int(value)<<std::endl;
    }
};

int main()
{
    int x = 5, y = 10;
    double d1 = 3.14, d2 = 2.71;
    std::string s1 = "Hello", s2 = "World";

    cout<<"x: "<<x<<"  y: "<<y<<endl;
    swapV(x, y);
    cout<<"x: "<<x<<"  y: "<<y<<endl;
    swapV(d1, d2);
    swapV(s1, s2);

    std::cout << "Integers: " << x << ", " << y << std::endl;
    std::cout << "Doubles: " << d1 << ", " << d2 << std::endl;
    std::cout << "Strings: " << s1 << ", " << s2 << std::endl;

    Pairme<int, double> p1(42, 3.14);
    Pairme<string, int> p2("hello", 23);

    std::cout << p1.getFirst() << ", " << p1.getSecond() << std::endl;
    std::cout << p2.getFirst() << ", " << p2.getSecond() << std::endl;

    p1.setSecond(2.71);
    std::cout << "Updated: " << p1.getFirst() << ", " << p1.getSecond() << std::endl;

    Storage<int> intStore(42);
    Storage<char> charStore('A');
    
    intStore.describe();
    charStore.describe();

    return 0;
}