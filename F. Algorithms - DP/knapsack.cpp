#include<iostream>
#include<vector>

using namespace std;

int knapsack(vector<int> &weight, vector<int> &value, int w){
    int n = weight.size();
    vector<vector<int>> dp(n+1, vector<int>(w+1));  // an element with index i,j represents max value using first i items with max weight j
    for(int i=0;i<=n;i++){          // iterate through items
        for(int j=0;j<=w;j++){      // iterate through weights from 0 to w
            if(j==0 || i==0)
            dp[i][j] = 0;
            else if(weight[i-1] <= j)   // item can be included because its weight weight[i-1] is less than current weight j
            dp[i][j] = max(dp[i-1][j-weight[i-1]] + value[i-1], dp[i-1][j]);  // the best solution for index i,j is the max of (including the item i-1 and adding its value to the max value for weight available minus weight of item i-1, not including the item i-1)
            else
            dp[i][j] = dp[i-1][j];      // the best solution for index i,j is the same as that for i-1,j (not including the item i-1)
        }
    }
    return dp[n][w];
}

int main(){
    vector<int> weight = {1, 2, 3};
    vector<int> value = {10, 15, 40};
    cout<<knapsack(weight, value, 5)<<endl; // prints 55

    vector<int> weight2 = {1, 2, 3};
    vector<int> value2 = {60, 100, 120};
    cout<<knapsack(weight2, value2, 5)<<endl; // prints 220
    
    vector<int> weight3 = {6, 3, 4, 2};
    vector<int> value3 = {30, 14, 16, 9};
    cout<<knapsack(weight3, value3, 10)<<endl; // prints 46

    return 0;
}