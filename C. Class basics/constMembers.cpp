// const member functions: a member function that is not allowed to modify the object https://www.geeksforgeeks.org/cpp/const-member-functions-c/
// const member attributes: member attributes that cannot be modified after initialization
// const class objects (instances): objects that cannot be modified after initialization

#include <iostream>
using namespace std;

class Demo {
    private:
        int x; 
        
    public:
        const int y = 20; // const member variable must be initialized at declaration or in constructor initializer list
        void set_data(int a) { x = a; }

        Demo() : x(0) {}
        Demo(int a) : x(a) {}

        int get_data()
        // int get_data() const // this line would cause an error
        {
            ++x;        // this line attempts to modify the value of x, which is not allowed in a const member function
            return x;
        }

        // const member functions DO NOT MODIFY the object
        // const member functions can be called on const and not const objects
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
    cout << d.get_data() << endl; // prints 11
    cout << d.get_data_const() << endl; // prints 11
    cout << d.y << endl; // prints 20
    // d.y = 30; // this line would cause an error
    cout << endl;

    const Demo d1(7); // const object (instance) of class Demo
    // d1.set_data(10); // this line would cause an error
    cout << d1.get_data_const() << endl; // prints 7
    // cout << d1.get_data() << endl; // this line would cause an error
    cout << endl;

    return 0;
}