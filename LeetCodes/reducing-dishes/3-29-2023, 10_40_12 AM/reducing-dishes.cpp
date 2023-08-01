// Link: https://leetcode.com/problems/reducing-dishes

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: reducing-dishes
 *  RUNTIME: 14 ms
 *  MEMORY: 8.3 MB
 *  DATE: 3-29-2023, 10:40:12 AM
 *
 */

// Solution:

class Solution {
public:
    int sumAll(int inx, int mul, int n, vector<int> &arr) {
        int sum = 0;
        for(int i=inx; i<n; i++) sum += (arr[i] * (mul++));
        return sum;
    }

    int maxSatisfaction(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        int inx = lower_bound(arr.begin(), arr.end(), 0) - arr.begin();
        if(inx >= n) return 0;

        vector<int> dp(n+1, 0), prev(n+1, 0);

        for(int j = inx + 1; j>0; j--) {
            prev[j] = sumAll(inx, j, n, arr);
        }

        for(int i = inx - 1; i>=0; i--) {
            for(int j = i + 1; j>0; j--) {
                dp[j] = max(prev[j+1] + arr[i] * j, prev[j]);
            }
            prev = dp;
        }
        return prev[1];
    }
};
