// Link: https://leetcode.com/problems/minimum-operations-to-make-all-array-elements-equal

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-operations-to-make-all-array-elements-equal
 *  RUNTIME: 275 ms
 *  MEMORY: 83.9 MB
 *  DATE: 3-26-2023, 12:08:18 PM
 *
 */

// Solution:

#define ll long long

class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        
        ll n = nums.size();
        vector<ll> prefix(n + 1, 0), suffix(n + 1, 0);
        for(int i=1; i<=n; i++) {
            prefix[i] = prefix[i-1] + (ll)nums[i-1];
        }
        for(int i=n-1; i>=0; i--) {
            suffix[i] = suffix[i+1] + (ll)nums[i];
        }
        
        
        vector<ll> ans;
        for(auto &x: queries) {
            ll index = (lower_bound(nums.begin(), nums.end(), x) - nums.begin());
            ll val = x;
            ll left = abs((index * val) - prefix[index]);
            ll right= abs(suffix[index] - ((n-index) * val));
            ans.push_back(left+right);
        }
        return ans;
    }
};
