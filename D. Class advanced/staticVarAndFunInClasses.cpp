// https://www.w3schools.com/cpp/cpp_classes.asp

// Variables declared as static are initialized only once 
// static variables in a class are shared by the objects and cannot be multiple copies of the same static variables for different objects. 
// Static variables can not be initialized using constructors.

#include <iostream>
using namespace std;

class GfG {
public:
    GfG(); //constructor 1
    GfG(int x); //constructor 2
    ~GfG(); //destructor

    // static int i = 0; // Error: ISO C++ forbids in-class initialization of non-const static member 'i'
    static int i; // static variable
    int myId; // non-static variable

    static void printMsg() { cout << "Welcome to GfG!" << endl; } // static function
};

// To define a function outside the class definition, you have to declare it inside the class and then define it outside of the class. 
// This is done by specifiying the name of the class, followed the scope resolution :: operator, followed by the name of the function:
GfG::GfG() {
    // non-static variables can be used without scope resolution operator
    myId = 0;
    cout << "And born I shall be!" << endl;
}

GfG::GfG(int x) {
    // non-static variables can be used without scope resolution operator
    myId = x;
    cout << "And born I shall be with a value " << x << "!" << endl;
}

GfG::~GfG() {
    cout << "My time has come!" << endl;
}

// Static variables must be defined outside the class
int GfG::i = 1;


int main(){
    cout<<GfG::i<<endl; // prints 1
    GfG obj1;
    GfG obj2(2);
    cout << GfG::i << " " << obj1.i << " " << obj2.i << endl; // prints 1 1 1
    obj1.i = 2;
    cout << GfG::i << " " << obj1.i << " " << obj2.i << endl; // prints 2 2 2
    obj2.i = 3;
    cout << GfG::i << " " << obj1.i << " " << obj2.i << endl; // prints 3 3 3

    cout<<endl;

    // non-static variables can be used without scope resolution operator
    cout << obj1.myId << " " << obj2.myId << endl; // prints 0 2

    cout<<endl;

    GfG::printMsg(); // prints Welcome to GfG!
    obj1.printMsg(); // prints Welcome to GfG!
    obj2.printMsg(); // prints Welcome to GfG!

    return 0;
}