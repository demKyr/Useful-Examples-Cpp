#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// O(nlogn)
int lengthOfLIS(vector<int>& nums) {
    vector <int> dp(nums.size(),2501); // each element i holds the smallest value possible for a LIS that has length i
    int maxSub = 0;
    for(int i=0;i<nums.size();i++){ // iterate through all numbers
        int lb = lower_bound(dp.begin(), dp.begin()+maxSub, nums[i]) - dp.begin(); // for each number find lower bound of dp array, this index shows the LIS with number as last element
        if(dp[lb] == 2501)  maxSub++; // if number is creating a new LIS, increase maxSub
        dp[lb] = min(dp[lb], nums[i]); // if number creates a new LIS of length lb and is smaller than the previous smallest number that created a new LIS of length lb, replace the value 
    }
    return maxSub;
}

int main() {
    vector<int> nums = {10,9,2,5,3,7,101,18,19};
    cout << "Length of Longest Increasing Subsequence: " << lengthOfLIS(nums) << endl;
    return 0;
}