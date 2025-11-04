// Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// // AUX FUNCTION FOR MEMOIZATION RECURSIVE SOLUTION WITH UNORDERED_SET (2/2)
    bool worldBreak_aux(string s, unordered_set<string>& wordSet, unordered_map<string, bool>& memo){
        if(s=="") return true;
        if(memo.count(s)) return memo[s];
        for(int i=s.size(); i>=1; i--){
            if(wordSet.count(s.substr(0, i)))               // if slice of s[0:i] is in unordered_set
                if(worldBreak_aux(s.substr(i), wordSet, memo)){    // feed slice s[i:] to recursive function
                    memo[s] = true;
                    return true;
                }
        }   
        memo[s] = false;
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        // // MEMOIZATION RECURSIVE SOLUTION WITH UNORDERED_SET (1/2)
        // unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        // unordered_map<string, bool> memo;
        // return worldBreak_aux(s, wordSet, memo);

        // // NAIVE RECURSIVE SOLUTION WITH LINEAR SEARCH
        // if(s=="") return true;
        // for (string w:wordDict){
        //     if(w == s.substr(0,w.size()))
        //         if (wordBreak(s.substr(w.size()), wordDict))
        //             return true;
        // }
        // return false;

        int n = s.size();
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector <bool> dp (n + 1, false);
        dp[0]=true;
        for(int i=1;i<=n;i++){
            dp[i] = false;
            for(int j=0;j<=i;j++){
                if(dp[j] && wordSet.count(s.substr(j,i-j))){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }

int main() {
    string s1 = "leetcode";
    vector<string> wordDict1 = {"leet", "code"};
    cout << wordBreak(s1, wordDict1) << endl; // Expected output: 1 (true)
    string s2 = "applepenapple";
    vector<string> wordDict2 = {"apple", "pen"};
    cout << wordBreak(s2, wordDict2) << endl; // Expected output: 1 (true)
    string s3 = "catsandog";
    vector<string> wordDict3 = {"cats", "dog", "sand", "and", "cat"};
    cout << wordBreak(s3, wordDict3) << endl; // Expected output: 0 (false)
    return 0;
}