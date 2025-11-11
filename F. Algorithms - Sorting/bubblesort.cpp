#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void bubbleSort(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n; i++)      
        for (int j = 0; j < n - 1; j++) 
            if (a[j] > a[j + 1]) 
                swap(a[j], a[j + 1]);
}

int main(){
    vector <int> arr {64, 34, 25, 12, 22, 11, 90};
    bubbleSort(arr);
    for(int el: arr){
        cout<<el<<" ";
    }
    cout<<endl;
    return 0;
}