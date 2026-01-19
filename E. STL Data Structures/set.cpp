// https://www.w3schools.com/cpp/cpp_sets.asp
// Set: Stores unique elements in ascending (or descending) order, duplicate values are ignored.
// Can add/remove elements but not change the value of an existing element.
// must be accessed through iterators or with a for-each loop
// search, removal, and insertion operations complexity: O(log n)

// Unordered Set: Stores unique elements in no particular order, duplicate values are ignored.
// search, removal, and insertion operations complexity: O(1) (on average, but O(n) in worst case)

// Multiset: Stores multiple occurrences of elements in ascending (or descending) order.
// search, removal, and insertion operations complexity: O(log n)   

// TIP: You can make a set directly from a vector

#include<iostream>
#include <set>
#include <unordered_set>
#include <vector>

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
    auto it = numbers.begin();
    advance(it, 2); // iterator to the 3rd element (0-based index)
    cout<<*it<<endl; // prints 3
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

    multiset<int> multiSet = {1, 2, 2, 3, 3, 4, 4, 4, 5};
    multiSet.insert(4); // adding another 4
    multiSet.erase(2); // removes all occurrences of 2
    auto it2 = multiSet.find(3); // finds ONE occurrence of 3
    if(it2 != multiSet.end())
        multiSet.erase(it2); // removes the found occurrence of 3
    for (auto num : multiSet) 
        cout << num << " "; // prints 1, 4, 4, 4, 4, 5 (sorted order)
    cout<<endl;

    // Creating a set from a vector
    vector<int> vec = {5, 2, 4, 3, 2, 4, 1};
    set<int> numSet(vec.begin(), vec.end()); 
    for (auto num : numSet) 
        cout << num << " "; // prints 1, 2, 3, 4, 5 (sorted order, duplicates removed)
    cout<<endl;

    return 0;
}
