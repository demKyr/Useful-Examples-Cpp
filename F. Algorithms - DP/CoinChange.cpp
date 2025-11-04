#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int coinChange(vector<int>& coins, int amount) {
    // O(amount*coins.length)
    vector<int> dp(amount+1);
    dp[0] = 0;
    for(int i=1;i<=amount;i++){
        dp[i] = 10005;
        for(int j=0;j<coins.size();j++)
            if(coins[j] <= i)
                dp[i] = min(dp[i], dp[i-coins[j]]+1);
    }

    if(dp[amount] == 10005)  return -1;
    return dp[amount];

    // O(amount^2)
    // unordered_set<int> coinSet(coins.begin(), coins.end());
    // vector<int> dp(amount+1);
    // dp[0] = 0;
    // for(int i=1;i<=amount;i++){
    //     dp[i] = 1005;
    //     for(int j=0;j<=i;j++)
    //         if(coinSet.count(i-j))
    //             dp[i] = min(dp[i], dp[j]+1);
    // }

    // if(dp[amount] == 1005)  return -1;
    // return dp[amount];
}

int main() {
    vector<int> coins1 = {1, 2, 5};
    cout<<coinChange(coins1, 11)<<endl; // Expected output: 3 (11 = 5 + 5 + 1)
    vector<int> coins2 = {2, 4, 6};
    cout<<coinChange(coins2, 7)<<endl; // Expected output: -1 (No combination can make
    vector<int> coins3 = {1, 3, 4, 5};
    cout<<coinChange(coins3, 7)<<endl; // Expected output: 2 (7 = 3 + 4)
    return 0;
}