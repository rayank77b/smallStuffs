#include <iostream>     // std::cout
#include <tuple>        // std::tuple, std::make_tuple, std::tie

int main ()
{
    int myint;
    char mychar;

    std::tuple<int, float, char> mytuple;

    std::tuple<int, float, char> mytuple2 ={
        10, 3.14, 'b'
    };

    std::tuple<int, char> foo(10, 'c');
    auto bar = std::make_tuple("test", 3.1, 14, 'y');

    // packing values in the tuple
    mytuple = std::make_tuple(10, 2.6, 'a');

    // unpacking tuple into variables
    std::tie(myint, std::ignore, mychar) = mytuple;

    std::cout << "myint contains: " << myint << '\n';
    std::cout << "mychar contains: " << mychar << '\n';

    std::get<2>(bar) = 100;  // set the 3th element to 100

    std::cout<<std::get<0>(bar)<<std::endl;

  return 0;
}