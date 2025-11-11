// https://www.geeksforgeeks.org/cpp/sort-c-stl/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Point{
    int x;
    int y;
};

bool customComparison(const Point &a, const Point &b){
    return (a.y > b.y || (a.y == b.y && a.x > b.x)); // sorting based on y coordinate and then x coordinate
}

int main(){
    vector <int> arr {64, 34, 25, 12, 22, 11, 90};
    sort(arr.begin(), arr.end());
    for(int el: arr){
        cout<<el<<" ";
    }
    sort(arr.begin(), arr.end());
    cout<<endl;

    sort(arr.begin(), arr.end(), greater<int>());
    for(int el: arr){
        cout<<el<<" ";
    }
    cout<<endl;

    int arr2[] = {5, 2, 8, 1, 4};
    int n = sizeof(arr2)/sizeof(arr2[0]);
    sort(arr2, arr2 + n);
    for(int el: arr2){
        cout<<el<<" ";
    }
    cout<<endl;

    // CUSTOM COMPARATORS

    // Using a lambda expression
    vector<Point> points = {{3, 8}, {3, 5}, {1, 2}, {4, 1}, {7, 1}};
    sort(points.begin(), points.end(), [](const Point &a, const Point &b){
        return (a.x < b.x || (a.x == b.x && a.y < b.y)); // sorting based on x coordinate and then y coordinate
    });
    for(auto p: points){
        cout<<"("<<p.x<<", "<<p.y<<") ";
    }
    cout<<endl;

    // Using a function pointer
    sort(points.begin(), points.end(), customComparison);
    for(auto p: points){
        cout<<"("<<p.x<<", "<<p.y<<") ";
    }
    cout<<endl;

    return 0;
}