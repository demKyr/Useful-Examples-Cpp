// https://www.w3schools.com/cpp/cpp_pointers.asp
// https://www.w3schools.com/cpp/cpp_references.asp

// g++-14 pointersAndAddresses.cpp -o pointersAndAddresses

	#include<iostream>
	using namespace std;
	
	int main() {

		int x = 300;
        int *Y = &x; // equivalent to int* Y = &x; // Y is a pointer to x
        int *Z;
        Z = &x; // equivalent to int* Z = &x; // Z is a pointer to x
        *Y = 200; // now x = 200
        cout << x << endl; // prints 200
        cout << *Y << endl; // prints 200
        cout << *Z << endl; // prints 200
        cout << &x << endl; // prints address of x
        cout << Y << endl; // prints value of ptr Y (address of x)
        cout << &Y << endl; // prints address of ptr Y
        cout << Z << endl; // prints value of ptr Z (address of x)
        cout << &Z << endl; // prints address of ptr Z

        cout << endl;

        int a = 300;
        int &B = a; // equivalent to int& B = a; // B is a reference to a
        B = 200; // now a = 200
        cout << a << endl; // prints 200
        cout << B << endl; // prints 200
        cout << &a << endl; // prints address of a
        cout << &B << endl; // prints address of a (same as address of a)

		return 0;
	}