#include <iostream>
#include <math.h>

using namespace std;

class Complex 
{
    private:
        double x;
        double y;
    public:
        Complex(): x(0.0), y(0.0) {}
        Complex(double a, double b): x(a),y(b) {}

        double Betrag() { return sqrt(x*x+y*y); }
        double Real() { return x;  }
        double Imag() { return y; }

        //  + operator overload
        Complex operator+(const Complex &c)
        {
            Complex tmp;
            tmp.x = this->x + c.x;
            tmp.y = this->y + c.y;
            return tmp;
        }
        // Assigment
        void operator=(const Complex &c)
        {
            x = c.x;
            y = c.y;
        }
        // output
        friend ostream& operator<<(ostream& os, const Complex &c)
        {
            if (c.x != 0.0)
            {
                if ( c.y > 0.0 )
                    os << c.x << " + " << c.y << "i";
                else if ( c.y < 0.0 )
                    os << c.x << " - " << c.y << "i";
                else 
                    os << c.x;
            } 
            else
                os <<  c.y << "i";

            return os;
        }
        
        void display()
        {
            cout << "Real: " << x << endl;
            cout << "Imag: " << y << endl;
            cout << "Betrag: " << Betrag() << endl;
        }
};

int main() 
{
    Complex c1(1.2, 3.3);
    c1.display();
    
    Complex c2(-3.0, 4.12); 
    cout << c2 << endl;

    Complex c3;
    c3 = c2+c1;
    c3.display();

    return 0;
}