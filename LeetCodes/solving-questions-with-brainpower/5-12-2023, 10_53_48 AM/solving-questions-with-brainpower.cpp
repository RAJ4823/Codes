// Link: https://leetcode.com/problems/solving-questions-with-brainpower

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: solving-questions-with-brainpower
 *  RUNTIME: 409 ms
 *  MEMORY: 121.3 MB
 *  DATE: 5-12-2023, 10:53:48 AM
 *
 */

// Solution:

#define ll long long 

class Solution {
public:
    vector<ll> dp;
    int n;
    ll find(int i, vector<vector<int>> &arr) {
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        
        ll take = arr[i][0] + find(i + 1 + arr[i][1], arr);
        ll nottake = find(i + 1, arr);
        return dp[i] = max(take, nottake);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        n = questions.size();
        dp.resize(n, -1);
        return find(0, questions);
    }
};
