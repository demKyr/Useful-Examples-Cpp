// https://www.w3schools.com/cpp/cpp_list.asp
// List: Doubly linked list that allows non-contiguous memory allocation.
// Can add/remove/change elements at any position.
// must be accessed through iterators or with a for-each loop
// search, insertion, and deletion operations complexity: O(n) 
// adding/removing elements at the beginning or end complexity: O(1)

#include<iostream>
#include <list>

using namespace std;

int main(){
    list<int> numbers = {1, 2, 3, 4, 5};
    numbers.push_back(6); // adding an element at the end
    numbers.push_front(0); // adding an element at the front
    numbers.pop_back(); // removing the last element
    numbers.pop_front(); // removing the first element
    numbers.front() = 3; // changing the first element
    numbers.remove(3); // removing all occurrences of element with value 3
    cout<<"size: "<<numbers.size()<<endl; // prints 4
    for(auto num:numbers) 
        cout << num << " "; // prints 1 2 4 5
    cout<<endl;
    // iterate with iterator
    for(list<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
        cout << *it << " "; // prints 1 2 4 5
    cout<<endl;

    numbers.clear(); // removes all elements
    cout<<"size: "<<numbers.size()<<endl; // prints 0
    cout<<"Is list empty? "<<numbers.empty()<<endl; // prints 1 (true)

    return 0;
}