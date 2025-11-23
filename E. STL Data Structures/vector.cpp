// https://www.w3schools.com/cpp/cpp_vectors.asp
// Vector: Dynamic array that can resize itself automatically when an element is added or removed.
// Can add/remove/change elements at any position.
// must be accessed through indices, iterators, or with a for-each loop
// search, insertion, and deletion operations complexity: O(n) 
// adding/removing elements at the end complexity: O(1) amortized

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector <int> nums = {1, 2, 3, 4, 5};
    nums.push_back(6); // adding an element at the end
    nums.pop_back(); // removing the last element
    nums.insert(nums.begin() + 2, 10); // inserting 10 at index 2
    nums.erase(nums.begin() + 4); // removing element at index 4
    cout<<"size: "<<nums.size()<<endl; // prints 5
    for(auto num:nums) 
        cout << num << " "; // prints 1 2 10 3 5
    cout<<endl;
    for(int i = 0; i < (int)nums.size(); i++)
        cout << nums[i] << " "; // prints 1 2 10 3 5
    cout<<endl;
    cout<<"index of 10: "<<find(nums.begin(), nums.end(), 10) - nums.begin()<<endl; // prints the address of element 3
    cout<<"is 3 present? "<<(find(nums.begin(), nums.end(), 3) != nums.end())<<endl; // prints 1 (true)
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(3);
    sort(nums.begin(), nums.end()); // sorting the vector
    nums.erase(unique(nums.begin(), nums.end()), nums.end()); // removing duplicates after sorting, complexity: O(n)
    for(auto num:nums) 
        cout << num << " "; // prints 1 2 3 5 10
    cout<<endl;

    vector <int> emptyVec(10); // creating a vector of size 10 with all elements initialized to 0
    cout<<"size: "<<emptyVec.size()<<endl; // prints 10

    vector<vector<int>> vec(3, vector<int>(4, 0)); // 3 rows, 4 columns, all elements initialized to 0
    vec.push_back(vector<int>(4, 1)); // adding a new row with 4 elements initialized to 1
    for(auto row:vec){
        for(auto val:row)
            cout << val << " "; // prints 0 0 0 0
        cout<<endl;
    }
    for(int i = 0; i < (int)vec.size(); i++){
        for(int j = 0; j < (int)vec[i].size(); j++)
            cout<<vec[i][j]<< " ";
        cout<<endl;   
    }
    return 0;
}