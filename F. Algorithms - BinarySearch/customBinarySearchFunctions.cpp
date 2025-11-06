// Binary Search which returns index of target if found, else -1. If there are multiple occurrences of target, returns index of the occurance it finds first.
// Upper Bound Search which returns index of the first element larger than target, else size of the list if target is larger than any element in the list.
// Lower Bound Search which returns index of the first element equal to or larger than target, else size of the list if target is larger than any element in the list.

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int bin_search(const vector<int>& v, int target, int leftInput=-1, int rightInput=__INT_MAX__){
    int left=max(0, leftInput);
    int right=min(int(v.size()-1), rightInput);
    while(left<=right){
        int mid = left + (right - left) / 2;    // int mid = (left+right)/2;  // this can cause overflow
        if(target > v[mid])
            left = mid+1;
        else if(target < v[mid])
            right = mid-1;
        else
            return mid;
    }
    return -1;
}

int upper_bound_search(const vector<int>& v, int target, int leftInput=-1, int rightInput=__INT_MAX__){
    int left=max(0, leftInput);
    int right=min(int(v.size()), rightInput);
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (target >= v[mid]) 
            left = mid + 1;
        else 
            right = mid;
    }
    return left;
}

int lower_bound_search(const vector<int>& v, int target, int leftInput=-1, int rightInput=__INT_MAX__){
    int left=max(0, leftInput);
    int right=min(int(v.size()), rightInput);
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (target > v[mid])
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}


int main(){
    vector <int> v{1,7,23,3,78,2,6,0,74,2,43,7,7,7,7,7,7,7};
    sort(v.begin(), v.end());

    for(int e:v)
        cout<<e<<" ";
    cout<<endl;

    int target = 7;
    cout<<target<<" found in index "<<bin_search(v, target)<<endl;
    int u_bound = upper_bound_search(v, target);
    cout<<target<<" upper bound is "<<v[u_bound]<<" found in index "<<u_bound<<endl;
    int l_bound = lower_bound_search(v, target);
    cout<<target<<" lower bound is "<<v[l_bound]<<" found in index "<<l_bound<<endl;

    target = 10;
    cout<<target<<" found in index "<<bin_search(v, target)<<endl;
    u_bound = upper_bound_search(v, target);
    cout<<target<<" upper bound is "<<v[u_bound]<<" found in index "<<u_bound<<endl;
    l_bound = lower_bound_search(v, target);
    cout<<target<<" lower bound is "<<v[l_bound]<<" found in index "<<l_bound<<endl;

    target = 0;
    cout<<target<<" found in index "<<bin_search(v, target)<<endl;
    u_bound = upper_bound_search(v, target);
    cout<<target<<" upper bound is "<<v[u_bound]<<" found in index "<<u_bound<<endl;
    l_bound = lower_bound_search(v, target);
    cout<<target<<" lower bound is "<<v[l_bound]<<" found in index "<<l_bound<<endl;
    
    target = -1;
    cout<<target<<" found in index "<<bin_search(v, target)<<endl;
    u_bound = upper_bound_search(v, target);
    cout<<target<<" upper bound is "<<v[u_bound]<<" found in index "<<u_bound<<endl;
    l_bound = lower_bound_search(v, target);
    cout<<target<<" lower bound is "<<v[l_bound]<<" found in index "<<l_bound<<endl;

    target = 78;
    cout<<target<<" found in index "<<bin_search(v, target)<<endl;
    u_bound = upper_bound_search(v, target);
    cout<<target<<" upper bound is "<<v[u_bound]<<" found in index "<<u_bound<<endl;
    l_bound = lower_bound_search(v, target);
    cout<<target<<" lower bound is "<<v[l_bound]<<" found in index "<<l_bound<<endl;
    
    target = 100;
    cout<<target<<" found in index "<<bin_search(v, target)<<endl;
    u_bound = upper_bound_search(v, target);
    cout<<target<<" upper bound is "<<v[u_bound]<<" found in index "<<u_bound<<endl;
    l_bound = lower_bound_search(v, target);
    cout<<target<<" lower bound is "<<v[l_bound]<<" found in index "<<l_bound<<endl;
    
}