// Link: https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: number-of-ways-to-reorder-array-to-get-same-bst
 *  RUNTIME: 368 ms
 *  MEMORY: 297.3 MB
 *  DATE: 6-16-2023, 9:35:01 PM
 *
 */

// Solution:


class Solution {
private:
    vector<vector<long long>> nCr;
    
    long long findWays(vector<int> &arr, long long MOD) {
        int len = arr.size();
        if(len <= 2) return 1;

        vector<int> left, right;
        for(int i=1; i<len; i++) {
            if(arr[i] < arr[0]) left.push_back(arr[i]);
            else                right.push_back(arr[i]);
        }

        long long ways_curr = nCr[len-1][left.size()] % MOD;
        long long ways_next = (findWays(left, MOD) % MOD * findWays(right, MOD) % MOD) % MOD;

        return (ways_curr * ways_next) % MOD;
    }

public:
    int numOfWays(vector<int>& nums) {
        long long n = nums.size(), MOD = 1e9+7;

        nCr.resize(n+1, vector<long long> (n+1, 1));

        for(int i=0; i<=n; i++) {
            for(int j=1; j<i; j++) {
                nCr[i][j] = (nCr[i-1][j] + nCr[i-1][j-1]) % MOD;
            }
        }

        long long totalWays = findWays(nums, MOD) % MOD;
        return (totalWays - 1) % MOD;
    }
};
