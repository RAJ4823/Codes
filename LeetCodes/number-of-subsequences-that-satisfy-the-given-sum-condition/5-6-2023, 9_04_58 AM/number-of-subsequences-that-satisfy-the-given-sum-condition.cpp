// Link: https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: number-of-subsequences-that-satisfy-the-given-sum-condition
 *  RUNTIME: 179 ms
 *  MEMORY: 47.6 MB
 *  DATE: 5-6-2023, 9:04:58 AM
 *
 */

// Solution:

#define ll long long

class Solution {
public:
    ll mod = 1000000007;
    ll power(ll x, ll y)
    {
        ll res = 1;
        while (y > 0) {
            if (y % 2 == 1)
                res = (res % mod * x % mod) % mod;
            y = y >> 1;
            x = (x % mod * x % mod) % mod;
        }
        return res % mod;
    }

    int numSubseq(vector<int>& nums, int target) {
        int i = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        int j = n-1;
        ll count = 0;   
        while(i <= j) {
            if(nums[j] + nums[i] <= target) {
                count = (count % mod + power(2, j - i)) % mod;
                i++;                      
            }
            else {
                j--;
            }
        }
        return count;
    }
};
