// Link: https://leetcode.com/problems/count-nice-pairs-in-an-array

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: count-nice-pairs-in-an-array
 *  RUNTIME: 155 ms
 *  MEMORY: 71.6 MB
 *  DATE: 11-21-2023, 6:31:34 PM
 *
 */

// Solution:

#define ll long long
class Solution {
public:
    unordered_map<int,int> cache;
    int rev(int &val) {
        if(cache.count(val)) 
            return cache[val];
        
        string str = to_string(val);
        reverse(str.begin(), str.end());
        return cache[val] = stoi(str);
    }
    int countNicePairs(vector<int>& nums) {
        unordered_map<int,ll> count;

        ll ans = 0, mod = 1e9 + 7;

        for(auto &val: nums) {
            int diff = (val - rev(val));
            count[diff]++;
        }

        for(auto &[diff, cnt]: count) {
            ll sum = ((cnt * (cnt - 1)) / 2) % mod;
            ans = (ans % mod + sum % mod) % mod;
        }
        return ans;
    }
};
