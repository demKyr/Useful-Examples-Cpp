// nth_element() uses the Quickselect algorithm to place the nth element in its sorted position
// All elements before the nth element are less than or equal to it
// All elements after the nth element are greater than or equal to it
// This is done in linear time on average O(n)
// It is similar to quicksort. The difference is, instead of recurring for both sides (after finding pivot), it recurs only for the part that contains the k-th smallest element

// TIP: It can be used to find median in an unsorted array in linear time
// TIP: It can also be used to find the k largest or k smallest elements in an array in linear time (not sorted)

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    vector <int> arr {64, 34, 25, 12, 22, 11, 91, 90};

    nth_element(arr.begin(), arr.begin() + 2, arr.end());
    cout<<"3rd smallest element is: "<<arr[2]<<endl; 

    nth_element(arr.begin(), arr.begin() + arr.size() - 3, arr.end());
    cout<<"3rd largest element is: "<<arr[arr.size() - 3]<<endl;

    int n = arr.size();
    if(n%2 == 1){
        nth_element(arr.begin(), arr.begin() + n/2, arr.end());
        cout<<"Median is: "<<arr[n/2]<<endl;
    } else {
        nth_element(arr.begin(), arr.begin() + n/2, arr.end());
        nth_element(arr.begin(), arr.begin() + n/2 + 1, arr.end());
        cout<<"Median is: "<<(arr[n/2] + arr[n/2 - 1]) / 2.0<<endl;
    }

    nth_element(arr.begin(), arr.begin() + 4, arr.end());
    cout<<"the first 5 smallest elements are: "; // not sorted
    for(int i = 0; i < 5; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    nth_element(arr.begin(), arr.begin() + 4, arr.end(), greater<int>());
    cout<<"the first 5 largest elements are: "; // not sorted
    for(int i = 0; i < 5; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}
    