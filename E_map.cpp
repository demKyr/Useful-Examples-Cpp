// https://www.w3schools.com/cpp/cpp_maps.asp
// Map: Stores key-value pairs, keys are unique, values can be duplicated.
// Can add/remove elements, and change the value of an existing key.
// must be accessed through iterators or with a for-each loop
// data is sorted by keys in ascending order
// search, removal, and insertion operations complexity: O(log n)

// Unordered Map: Stores key-value pairs in no particular order, keys are unique.
// search, removal, and insertion operations complexity: O(1) (on average, but O(n) in worst case)


#include<iostream>
#include <map>
#include <unordered_map>

using namespace std;

int main(){
    map<string, int> people = { {"John", 32}, {"Adele", 45}, {"Bo", 29} };
    for(auto person:people) 
        cout << person.first << ": " << person.second << endl; // prints Adele: 45, Bo: 29, John: 32 (sorted by key)
    cout<<"John's age: "<<people["John"]<<endl; // prints 32
    people["John"] = 33; // updating value for key "John"
    people["Emma"] = 27; // adding new key-value pair
    people["Alex"] = 30; // adding new key-value pair
    people.erase("Adele"); // removing key-value pair with key "Adele"
    cout<<"size: "<<people.size()<<endl; // prints 5
    cout<<"Is Bo present? "<<people.count("Bo")<<endl; // prints 1 (Bo is present)
    cout<<"Is Adele present? "<<people.count("Adele")<<endl; // prints 0 (Adele is not present)
    people.clear(); // removes all key-value pairs
    cout<<"size: "<<people.size()<<endl; // prints 0
    cout<<"Is map empty? "<<people.empty()<<endl; // prints 1 (true)

    unordered_map<string, int> scores = { {"Alice", 90}, {"Bob", 85}, {"Charlie", 88} };
    scores["David"] = 92; // adding new key-value pair
    scores.erase("Bob"); // removing key-value pair with key "Bob"
    for(auto score:scores) 
        cout << score.first << ": " << score.second << endl; // prints elements in no particular order
    cout<<"size: "<<scores.size()<<endl; // prints 3
    cout<<"Is Alice present? "<<scores.count("Alice")<<endl; // prints 1 (Alice is present)
    return 0;
}