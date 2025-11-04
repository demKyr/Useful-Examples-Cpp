// https://www.w3schools.com/cpp/cpp_stacks.asp
// Stack: LiFo - Last In First Out data structure
// Can only add/remove/access the top element
// no iterators available
// push, pop, top, size, empty operations complexity: O(1)
// You cannot add elements to the stack at the time of declaration

#include<iostream>
#include <stack>

using namespace std;

int main(){
    stack<int> stk;
    stk.push(1); // adding element 1
    stk.push(2); // adding element 2
    stk.push(3); // adding element 3
    cout<<"top element: "<<stk.top()<<endl; // prints 3
    stk.pop(); // removing top element (3)
    cout<<"top element after pop: "<<stk.top()<<endl; // prints 2
    stk.top() = 5; // changing the top element to 5
    cout<<"top element after changing: "<<stk.top()<<endl; // prints 5
    cout<<"size: "<<stk.size()<<endl; // prints 3
    cout<<"Is stack empty? "<<stk.empty()<<endl; // prints 0 (false)
    stk.pop(); // removing top element (5)
    stk.pop(); // removing top element (1)
    cout<<"Is stack empty after popping all elements? "<<stk.empty()<<endl; // prints 1 (true)
    return 0;
}