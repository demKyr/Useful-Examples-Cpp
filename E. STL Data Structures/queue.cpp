// https://www.w3schools.com/cpp/cpp_queues.asp
// Queue: FiFo - First In First Out data structure
// Can only add elements at the back and remove/access elements from the front
// no iterators available
// push, pop, front, back, size, empty operations complexity: O(1)

// https://www.w3schools.com/cpp/cpp_deque.asp
// Deque: Double-Ended Queue, allows insertion and deletion of elements from both front and back
// Can add/remove/access elements from both front and back
// no iterators available
// push_front, push_back, pop_front, pop_back, front, back, size, empty operations complexity: O(1)

// https://cplusplus.com/reference/queue/priority_queue/
// Priority Queue: Similar to a regular queue but each element has a priority.
// Elements with higher priority are served before elements with lower priority.
// By default, a max-heap is implemented (highest value has highest priority).  
// priority queue operations complexity: O(log n) for push and pop, O(1) for top
// priority rule is set using comparator (less for max-heap, greater for min-heap)
#include<iostream>
#include<queue>
#include<deque>

using namespace std;

int main(){
    queue<int> q;
    q.push(1); // adding element 1
    q.push(2); // adding element 2
    q.push(3); // adding element 3
    cout<<"front element: "<<q.front()<<endl; // prints 1
    cout<<"back element: "<<q.back()<<endl; // prints 3
    q.front() = 5; // changing the front element to 5
    q.back() = 10; // changing the back element to 10
    cout<<"front element after changing: "<<q.front()<<endl; // prints 5
    cout<<"back element after changing: "<<q.back()<<endl; // prints 10
    q.pop(); // removing front element (5)
    cout<<"front element after pop: "<<q.front()<<endl; // prints 2
    cout<<"size: "<<q.size()<<endl; // prints 2
    cout<<"Is queue empty? "<<q.empty()<<endl; // prints 0 (false)
    q.pop(); // removing front element (2)
    q.pop(); // removing front element (3)
    cout<<"Is queue empty after popping all elements? "<<q.empty()<<endl; // prints 1 (true)

    deque<int> dq;
    dq.push_back(1); // adding element 1 at the back
    dq.push_back(7); // adding element 7 at the back
    dq.push_back(8); // adding element 8 at the back
    dq.push_front(2); // adding element 2 at the front
    dq.push_back(3); // adding element 3 at the back
    cout<<"front element: "<<dq.front()<<endl; // prints 2
    cout<<"back element: "<<dq.back()<<endl; // prints 3
    dq.front() = 5; // changing the front element to 5
    dq.back() = 10; // changing the back element to 10
    dq.pop_front(); // removing front element (5)
    dq.pop_back(); // removing back element (10)
    cout<<"size: "<<dq.size()<<endl; // prints 1
    dq[2] = 15; // changing element at index 2 to 15
    for(int i = 0; i < (int)dq.size(); i++)
        cout << dq[i] << " "; // prints 7 15 8
    cout<<endl;
    for(int el:dq)
        cout << el << " "; // prints 7 15 8
    cout<<endl;

    priority_queue<int, vector<int>, greater<int>> pq; // min-heap
    pq.push(5); // adding element 5
    pq.push(1); // adding element 1
    pq.push(10); // adding element 10
    pq.push(3); // adding element 3
    for (; !pq.empty(); pq.pop())
        cout << pq.top() << ' ';
    cout<<endl;
    priority_queue<int, vector<int>, less<int>> pq2; // max-heap
    pq2.push(5); // adding element 5
    pq2.push(1); // adding element 1
    pq2.push(10); // adding element 10
    pq2.push(3); // adding element 3
    for (; !pq2.empty(); pq2.pop())
        cout << pq2.top() << ' ';
    cout<<endl;

    return 0;
}