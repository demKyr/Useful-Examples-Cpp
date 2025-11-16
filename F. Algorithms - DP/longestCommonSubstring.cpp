#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

// top-down recursive with memoization (instead of passing substring (additional complexity), we pass indices)
int maxCommonStringRecursive(string& s1, string& s2, int idx1, int idx2, vector<vector<int>>& memo){
    if(s1.length() == idx1 || s2.length() == idx2)    return 0;
    if(memo[idx1][idx2] != -1) return memo[idx1][idx2];
    if(s1[idx1]==s2[idx2])    
        return 1+maxCommonStringRecursive(s1, s2, idx1+1, idx2+1, memo);
    memo[idx1][idx2] = (max (max (maxCommonStringRecursive(s1, s2, idx1+1, idx2+1, memo), 
                                  maxCommonStringRecursive(s1, s2, idx1+1, idx2, memo)),
                             maxCommonStringRecursive(s1, s2, idx1, idx2+1, memo)));
    return memo[idx1][idx2];
}

// bottom-up DP
int maxCommonStringDP(string s1, string s2) {
    vector<vector<int>> dp(s1.length()+1, vector<int>(s2.length()+1,0));
    for(int i=1;i<=s1.length();i++){
        for(int j=1;j<=s2.length();j++){
            if(s1[i-1]==s2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max( max(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]);
        }
    }
    return dp[s1.size()][s2.size()];
}

int main(){
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
    vector<vector<int>> memo(s1.length()+1, vector<int>(s2.length()+1,-1));
    cout<<"Length of Longest Common Subsequence is "<<maxCommonStringRecursive(s1, s2, 0, 0, memo)<<endl; 
    cout<<"Length of Longest Common Subsequence is "<<maxCommonStringDP(s1, s2)<<endl;
    return 0;
}