// https://www.w3schools.com/cpp/cpp_sets.asp
// Set: Stores unique elements in ascending (or descending) order, duplicate values are ignored.
// Can add/remove elements but not change the value of an existing element.
// must be accessed through iterators or with a for-each loop
// search, removal, and insertion operations complexity: O(log n)

// Unordered Set: Stores unique elements in no particular order, duplicate values are ignored.
// search, removal, and insertion operations complexity: O(1) (on average, but O(n) in worst case)

#include<iostream>
#include <set>
#include <unordered_set>

using namespace std;

int main(){
    set<string> cars = {"Volvo", "BMW", "Ford", "Mazda"};

    for (auto car : cars) 
        cout << car << " "; // prints BMW, Ford, Mazda, Volvo (sorted order)
    cout<<endl;

    set<int> numbers = {1, 7, 3, 2, 5, 9, 9};
    numbers.insert(4); // adding an element
    numbers.insert(3); // duplicate value, will be ignored
    numbers.erase(7); // removing an element
    cout<<"size: "<<numbers.size()<<endl; // prints 5
    for (auto num : numbers) 
        cout << num << " "; // prints 1, 2, 3, 4, 5, 9 (sorted order)
    cout<<endl;
    cout<<numbers.count(3)<<endl; // prints 1 (3 is present)
    cout<<numbers.count(7)<<endl; // prints 0 (7 is not present
    numbers.clear(); // removes all elements
    cout<<"size: "<<numbers.size()<<endl; // prints 0
    cout<<numbers.empty()<<endl; // prints 1 (true)


    unordered_set<string> fruits = {"Apple", "Banana", "Orange"};
    fruits.insert("Grapes");
    fruits.erase("Banana");
    for (auto fruit : fruits) 
        cout << fruit << " "; // prints elements in no particular order
    cout<<endl;
    cout<<"size: "<<fruits.size()<<endl; // prints 3
    cout<<fruits.count("Apple")<<endl; // prints 1 (Apple is present)

    return 0;
}
