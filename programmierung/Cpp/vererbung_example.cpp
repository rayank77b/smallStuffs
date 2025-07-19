#include <iostream>

class A
{
    public:
        int a;

        A(int t) :a(t)
        {
            std::cout << "A constructor set: " << t << std::endl;
        }
        virtual ~A() 
        {
            std::cout << "A destructor called." << std::endl;
        }

        virtual void show()
        {
            std::cout<<"A say "<<a<< std::endl;
        }
};

class B:public A
{
    public:
        int b;

        B(int t1, int t2 ): b(t2), A(t1)
        {            
           std::cout << "B constructor set: " << t2 << std::endl;
        }
        virtual ~B() 
        {
            std::cout << "B destructor called." << std::endl;
        }

        virtual void show()
        {
            std::cout<<"B say " << b << std::endl;
        }
};

class C:public B
{
    public:
        int c;

        C(int t1, int t2 ): c(t2), B(t1,t1)
        {
           std::cout << "C constructor set: " << t2 << std::endl;
        }
        ~C() 
        {
            std::cout << "C destructor called." << std::endl;
        }

        void show()
        {
            std::cout<<"C say " << c << std::endl;
        }
};


int main()
{
    std::cout << "start"<< std::endl;

    std::cout << std::endl << "A direkt" << std::endl;
    A *p_a = new A(15);
    p_a->show();
    delete p_a;

    std::cout << std::endl << "B direkt" << std::endl;
    B *p_b = new B(1, 25);
    p_b->show();
    delete p_b;

    std::cout << std::endl << "A direkt" << std::endl;
    C *p_c = new C(-3,-4);
    p_c->show();
    delete p_c;

    std::cout << std::endl << "B indirekt p_a" << std::endl;
    p_a = new B(2,35);
    p_a->show();
    delete p_a;

    std::cout << std::endl << "C indirekt p_a" << std::endl;
    p_a = new C(-1,-2);
    p_a->show();
    delete p_a;

    std::cout << std::endl << "C indirekt p_b" << std::endl;
    p_b = new C(-6,-7);
    p_b->show();
    delete p_b;

    return 0;
}