// Link: https://leetcode.com/problems/count-the-number-of-beautiful-subarrays

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: count-the-number-of-beautiful-subarrays
 *  RUNTIME: 335 ms
 *  MEMORY: 135.3 MB
 *  DATE: 3-12-2023, 8:53:29 AM
 *
 */

// Solution:

#define ll long long
class Solution {
public:          
    long long beautifulSubarrays(vector<int>& nums) {
        ll n = nums.size(), count = 0;
        vector<ll> prefix(n);
        unordered_map<ll, ll> m;
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++)
          prefix[i] = prefix[i - 1] ^ nums[i];
        for (int i = 0; i < n; i++)
        {
          count += m[(ll)((0 ^ prefix[i]))];
          count += (prefix[i]) ? 0 : 1;
          m[prefix[i]]++;
        }
        return count;
    }
};
