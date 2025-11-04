#include<iostream>

using namespace std;

int climbStairs(int n) {
    if(n<=2) return n;
    int prevprev=1;
    int prev=2;
    int cur;
    for(int i=3;i<=n;i++){
        cur=prevprev+prev;
        prevprev = prev;
        prev=cur;
    }
    return cur;
}

int main(){
    cout<<climbStairs(3)<<endl; // Expected output: 3
    cout<<climbStairs(10)<<endl; // Expected output: 89
    return 0;
}