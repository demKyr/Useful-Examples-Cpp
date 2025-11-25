// pass by value creates a copy of the argument, modifications do not affect the original variable
// pass by reference does not create a copy, modifications affect the original variable
// pass by pointer passes the address of the variable, modifications through dereferencing affect the original variable

// The difference between pass by reference and pass by pointer are:
// - Passed by ptr parameters can be moved/reassigned to a different memory location. Passed by ref params can't.
//      * You can change where the pointer points (change the address held by it)
//      * You  cannot change who the reference refers to. If you assign a new variable to a reference, it doesn't switch the reference. 
//      Instead, it overwrites the value of the original variable it is bound to
// - Passed by ptr parameters can be null. Passed by ref params can't. (Pointers are useful when a value is optional)

#include<iostream>

using namespace std;

void passbyval(int x){
    x = x + 10;
}

void passbyref(int &x){
    x = x + 10;
}

void passbyptr(int *x){
    *x = *x + 10;
}

void printIfExists(int* ptr) {
    if (ptr != nullptr) 
        cout << "Value exists: " << *ptr << endl;
    else
        cout << "Pointer is null (no value provided)." << endl;
}

int main(){
    int a = 5;
    cout<<"Original a: "<<a<<endl;

    passbyval(a); // pass a
    cout<<"After passbyval a: "<<a<<endl; // a remains unchanged

    passbyref(a); // pass a
    cout<<"After passbyref a: "<<a<<endl; // a is modified

    passbyptr(&a); // pass address of a
    cout<<"After passbyptr a: "<<a<<endl; // a is modified again

    int value = 100;
    printIfExists(&value); 
    printIfExists(nullptr);
    // passbyref(NULL); // This will cause a compilation error

    int x = 10;
    int y = 20;
    int* ptr = &x; // ptr points to x
    int& ref = x;  // ref is an alias for x
    cout << "Start: x=" << x << ", y=" << y << endl;
    ptr = &y; 
    *ptr = 50; // Changes y, not x
    cout << "After moving ptr to y and modifying: x=" << x << ", y=" << y << endl;
    // We CANNOT make ref point to y. 
    ref = y; // This line looks like reassigning, but it actually copies y's value into x
    cout << "After trying to 'reseat' ref: x=" << x << ", y=" << y << endl;
    ref = 999; // If we modify ref now, we are still modifying x, just with the new value.
    cout << "After modifying ref: x=" << x << ", y=" << y << endl;

    return 0;
}