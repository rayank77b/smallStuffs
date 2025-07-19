#include <iostream>

using namespace std;

class A {
    public:
        int a;
    protected:
        int a2;
    private:
        int a3;
};

class B: A{

};

int main() {
    cout<<"start.."<<endl;

    A a;

    B b;
    cout<<b.a<<endl;
    return 0;
}