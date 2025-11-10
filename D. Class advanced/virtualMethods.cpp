// https://www.geeksforgeeks.org/cpp/virtual-function-cpp/
// Virtual functions enable runtime polymorphism, calling the correct function via a base class pointer or reference
// they allow derived classes to provide their own implementation of base class functions
// i.e. Virtual functions ensure that the correct function is called for an object, 
// regardless of the type of reference (or pointer) used for the function call.

// TIP: When a derived class object is deleted through a base class pointer, a virtual destructor in the base class ensures that both the derived and base class destructors are called
// TIP: If a class has any virtual functions, its destructor should also be declared virtual

#include <iostream>

class Animal
{
    public:
        void eat() { std::cout << "I'm eating generic food.\n"; }
        virtual void enemies() { std::cout << "I have generic enemies.\n"; }
};

class Cat : public Animal
{
    public:
        void eat() { std::cout << "I'm eating a rat.\n"; }
        void enemies() { std::cout << "I have dog enemies.\n"; }
};

void funcEat(Animal *xyz) { xyz->eat(); }

void funcEnemies(Animal *xyz) { xyz->enemies(); }

int main(){
    Animal *animal = new Animal;
    Cat *cat = new Cat;

    animal->eat(); // Outputs: "I'm eating generic food."
    cat->eat();    // Outputs: "I'm eating a rat."
    funcEat(animal); // Outputs: "I'm eating generic food."
    funcEat(cat);    // Outputs: "I'm eating generic food." (not what we want)

    std::cout<<std::endl;

    animal->enemies(); // Outputs: "I have generic enemies."
    cat->enemies();    // Outputs: "I have dog enemies."
    funcEnemies(animal); // Outputs: "I have generic enemies."
    funcEnemies(cat);    // Outputs: "I have dog enemies."

    std::cout<<std::endl;

    Animal* randomAnimal;
    Cat Pourkouris;
    randomAnimal = &Pourkouris;
    randomAnimal->eat(); // Outputs: "I'm eating generic food." (not what we want)
    randomAnimal->enemies(); // Outputs: "I have dog enemies."


}