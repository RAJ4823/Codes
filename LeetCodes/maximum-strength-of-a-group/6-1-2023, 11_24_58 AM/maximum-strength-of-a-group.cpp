// Link: https://leetcode.com/problems/maximum-strength-of-a-group

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: maximum-strength-of-a-group
 *  RUNTIME: 16 ms
 *  MEMORY: 46.6 MB
 *  DATE: 6-1-2023, 11:24:58 AM
 *
 */

// Solution:

#define ll long long
class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        ll p=1, maxi = INT_MIN, nm = INT_MIN, nc = 0;
        for(ll val: nums) {
            if(val < 0) nm = max(nm, val), nc++;
            if(val !=0) p *= val;
            maxi = max(maxi, val);
        }

        if(maxi == 0 && nc < 2) return 0;
        if(maxi < 0 && nc == 1) return nm;
        if(p > 0) return p;
        return p/nm;
    }
};
