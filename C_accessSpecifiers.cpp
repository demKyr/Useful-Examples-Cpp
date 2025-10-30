// https://www.w3schools.com/cpp/cpp_access_specifiers.asp
// https://www.w3schools.com/cpp/cpp_encapsulation.asp

#include<iostream>
using namespace std;

class MyClass {
    int z = 1;   // all members of a class are private if you don't specify an access specifier

  private:   
    int y = 1;
    void initialise(){
        x = 1;
        y = 1;
        z = 1;
    }   

  public:    
    int x = 1;   
    int getY() { return y; }
    void setY(int num) { y = num; }
    int getZ();
    void setZ(int num);
    void swapValues(){
        int temp = x;
        x = y;
        y = z;
        z = temp;
    }
    void callInitialise(){ initialise(); }
};

int MyClass::getZ() {
  return z;
}

void MyClass::setZ(int num) {
  z = num;
//   this->z = num; // equivalent to z = num;
}

int main() {
    MyClass myObj;
    myObj.x = 25;  
    //   myObj.y = 50;  // Not allowed (private)
    myObj.setY(50);
    //   myObj.z = 100; // Not allowed (private)
    myObj.setZ(100);
    cout<<myObj.x<<" "<<myObj.getY()<<" "<<myObj.getZ()<<endl; // prints 25 50 100

    myObj.swapValues();
    cout<<myObj.x<<" "<<myObj.getY()<<" "<<myObj.getZ()<<endl; // prints 50 25 100

    // myObj.initialise(); // Not allowed (private)
    myObj.callInitialise(); // allowed
    cout<<myObj.x<<" "<<myObj.getY()<<" "<<myObj.getZ()<<endl; // prints 1 1 1

    return 0;
}