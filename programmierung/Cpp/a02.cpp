#include <iostream>
using namespace std;

class Numbers {
 private:
  int a;
  int b;

 public:
  // Function to set values
  void setValues(int x, int y) {
    a = x;
    b = y;
  }

  // Function to add these numbers
  double addition() { return a + b; }

  // Function to display values
  void display() { cout << "a: " << a << ", b: " << b << endl; }
};

int main() {
  // Create an object of Numbers class
  Numbers num;

  // Set values
  num.setValues(10, 20);

  // Display the values
  num.display();

  // Find the addition
  int sum = num.addition();
  cout << "Sum of numbers: " << sum << endl;

  return 0;
}
