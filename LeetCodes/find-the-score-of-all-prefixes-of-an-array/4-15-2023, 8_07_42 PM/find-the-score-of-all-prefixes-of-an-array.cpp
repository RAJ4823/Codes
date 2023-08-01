// Link: https://leetcode.com/problems/find-the-score-of-all-prefixes-of-an-array

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: find-the-score-of-all-prefixes-of-an-array
 *  RUNTIME: 169 ms
 *  MEMORY: 56.2 MB
 *  DATE: 4-15-2023, 8:07:42 PM
 *
 */

// Solution:

#define ll long long

class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size();
        vector<ll> ans(n), sum(n, 0);
        ll maxi = 0;
        for(int i=0; i<n; i++) {
            maxi = max(maxi, (ll)nums[i]);
            sum[i] = maxi + nums[i];
        }
        for(int i=1; i<n; i++){
            sum[i] += sum[i-1];
        }
        return sum;
    }
};
