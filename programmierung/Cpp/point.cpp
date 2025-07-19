#include <iostream>

using namespace std;

class Point {
    private:
        int x;         // object variable
        int y;
    public:
        static int cnt;     // Class variable
        Point();              // default constructor
        Point(int X, int Y): x(X), y(Y) { };  // set constructor
        Point(const Point& obj);   // copy constructor
        void myout();
        static void getcnt() {  // class method
            cout<<"Points: "<<cnt<<endl;
        }

        Point operator+(const Point& p) {
            Point tmp;
            tmp.x = this->x + p.x;
            tmp.y = this->y + p.y;
            return tmp;
        }

         friend ostream &operator<<( ostream &output, const Point &p ) { 
         output << "Point : ( " << p.x << " | " << p.y << " )";
         return output;            
      }
};

Point::Point() {
    x=0; 
    y=0;
    cnt++;
}

Point::Point(const Point& obj) {
    x=obj.x;
    y=obj.y;
    cnt++;
}

void Point::myout() {
    cout<<"Point: "<<x<<" | "<<y<<endl;
}

int Point::cnt = 0;

int main() {
    cout<<"start.."<<endl;

    Point p0;
    Point p1(1,2);

    p0.myout();
    p1.myout();

    Point p2(p1);

    p2.myout();

    p2 = p2 + p1;

    cout<<p2<<endl;
    cout<<"Points: "<<Point::cnt<<endl;
    Point::getcnt();
    return 0;
}
