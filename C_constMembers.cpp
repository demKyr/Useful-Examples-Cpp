#include <iostream>
using namespace std;

class Demo {
    int x;

public:
    void set_data(int a) { x = a; }

    Demo() : x(0) {}
    Demo(int a) : x(a) {}

    int get_data()
    // int get_data() const // this line would cause an error
    {
        ++x;        // this line attempts to modify the value of x, which is not allowed in a const member function
        return x;
    }

    int get_data_const() const
    {
        // x = 10; // this line would cause an error
        return x;
    }


};


int main()
{
    Demo d;
    d.set_data(10);
    cout << d.get_data() << endl;
    cout << d.get_data_const() << endl;
    cout << endl;

    const Demo d1(7);
    // d1.set_data(10); // this line would cause an error
    cout << d1.get_data_const() << endl;
    cout << endl;

    return 0;
}