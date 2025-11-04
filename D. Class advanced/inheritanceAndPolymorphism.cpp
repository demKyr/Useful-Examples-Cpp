// https://www.w3schools.com/cpp/cpp_inheritance.asp
// https://www.w3schools.com/cpp/cpp_polymorphism.asp

// Inheritance: inheriting attributes and methods from one class to another
// Polymorphism: when one class is inherited by another class, and the derived class has its own implementation of the method

#include <iostream>
using namespace std;

// Base class
class Vehicle {
    public:
        string brand = "Nissan";
        virtual void honk() {
            cout << "Tuut, tuut! \n" ;
        }
};

// Another base class
class ColourfulObject{
    public:
        string colour = "red";
};

// Derived class
class Car: public Vehicle {
    public:
        string model = "GTR";
        void honk() {
            cout << "Tuut, tuut in GTR! \n" ;
        }
};

// Derived class
class Pickup: public Vehicle {
    public:
        string model = "Navara";
        void honk() {
            cout << "Tuut, tuut in Navara! \n" ;
        }
};

// derived class with multiple and multilevel inheritance
class specificCar: public Car, public ColourfulObject {
    public:
        string licensePlate = "XXX123";
        specificCar() { }
        specificCar(string brand, string model, string licensePlate, string colour) {
            this->brand = brand;
            this->model = model;
            this->licensePlate = licensePlate;
            this->colour = colour;
        }
};


int main() {
    Vehicle aVehicle;
    aVehicle.honk();
    cout << aVehicle.brand << endl; // Outputs: Nissan

    Car aCar;
    aCar.honk();
    cout << aCar.brand + " " + aCar.model << endl; // Outputs: Nissan GTR

    Pickup aPickup;
    aPickup.honk();
    cout << aPickup.brand + " " + aPickup.model << endl; // Outputs: Nissan Navara

    specificCar aSpecificCar;
    aSpecificCar.honk();
    cout << aSpecificCar.brand + " " + aSpecificCar.model + " " + aSpecificCar.licensePlate << " " << aSpecificCar.colour << endl; // Outputs: Nissan GTR XXX123 red

    specificCar aVerySpecificCar("Toyota", "Yaris", "YYY456", "blue");
    cout << aVerySpecificCar.brand + " " + aVerySpecificCar.model + " " + aVerySpecificCar.licensePlate << " " << aVerySpecificCar.colour << endl; // Outputs: Toyota Yaris YYY456 blue

    return 0;
}