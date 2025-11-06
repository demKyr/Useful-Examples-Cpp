// https://www.geeksforgeeks.org/cpp/binary-search-algorithms-the-c-standard-template-library-stl/
// https://www.geeksforgeeks.org/cpp/upper_bound-and-lower_bound-for-vector-in-cpp-stl/

// binary_search() method can be used to check if a given value is present in the vector or not
// lower_bound() method can be used to find the first value that is EQUAL OR LARGER to given value in the vector
// upper_bound() method can be used to find the first value that is LARGER than the given value in the vector
// if the value is not present, they both return the next element that is LARGER than the given value

// binary_search(), lower_bound() and upper_bound() all work on sorted ranges only

// binary_search() returns a boolean value indicating whether the element is present or not

// lower_bound() and upper_bound() both return an iterator pointing to the position of the found element
// to get the index of the found element, we can subtract the begin() iterator from the returned iterator as (it - v.begin())
// to get the value of the found element, we can dereference the returned iterator as *it

// lower_bound() essentially returns the first position where the target can be inserted without violating the order

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    vector<int> v = {10, 20, 20, 20, 30, 40, 50};

    // Checking if 20 is present in the vector
    bool found = binary_search(v.begin(), v.end(), 20);
    if (found) {
        cout << "20 is present in the vector" << endl;
    } else {
        cout << "20 is not present in the vector" << endl;
    }

    
    // Finding lower bound of 20
    auto lower = lower_bound(v.begin(), v.end(), 20);
    cout << "Lower bound of 20 is at index: " << (lower - v.begin()) << " and it has value " << *lower << endl;
    
    // Finding upper bound of 20
    auto upper = upper_bound(v.begin(), v.end(), 20);
    cout << "Upper bound of 20 is at index: " << (upper - v.begin()) << " and it has value " << *upper << endl;

    // Finding lower bound of 21
    auto lowerT = lower_bound(v.begin(), v.end(), 21);
    cout << "Lower bound of 21 is at index: " << (lowerT - v.begin()) << " and it has value " << *lowerT << endl;

    // Finding upper bound of 21
    auto upperT = upper_bound(v.begin(), v.end(), 21);
    cout << "Upper bound of 21 is at index: " << (upperT - v.begin()) << " and it has value " << *upperT << endl;

    // it can be used to find elemnts in a part of the vector as well
    auto lower_partial = lower_bound(v.begin() + 2, v.end(), 30); // from index 2 to end
    cout << "Lower bound of 30 from index 2 is at index: " << (lower_partial - v.begin()) << " and it has value " << *lower_partial << endl;

    // binary_search using lower_bound
    auto it = lower_bound(v.begin(), v.end(), 20);
    if(*it == 20)
        cout << *it << " found at index " << (it - v.begin()) << endl;

    // find number of occurrences of 25 (even if the value is not present)
    int count = upper_bound(v.begin(), v.end(), 25) - lower_bound(v.begin(), v.end(), 25);
    cout << "Number of occurrences of 25: " << count << endl;

    // find number of elements less than 30
    int less_than_30 = lower_bound(v.begin(), v.end(), 30) - v.begin();
    cout << "Number of elements less than 30: " << less_than_30 << endl;

    // find number of elements greater than 30
    int greater_than_30 = v.end() - upper_bound(v.begin(), v.end(), 30);
    cout << "Number of elements greater than 30: " << greater_than_30 << endl;


    return 0;
}