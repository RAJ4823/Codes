// Link: https://leetcode.com/problems/minimize-maximum-of-array

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimize-maximum-of-array
 *  RUNTIME: 163 ms
 *  MEMORY: 71.3 MB
 *  DATE: 3-9-2023, 11:39:06 AM
 *
 */

// Solution:

#define ll long long
class Solution {
public:
    bool isPossible(ll mid, vector<int>& nums) {
        ll extra = 0;
        for (ll val : nums) {
            ll diff = abs(val - mid);
            if (val > mid) {
                if (diff > extra) return false;
                extra -= diff;
            } else {
                extra += diff;
            }
        }
        return true;
    }

    int minimizeArrayValue(vector<int>& nums) {
        ll low = 0, high=1e9, ans = 0;
        while(low <= high) {
            ll mid = (low + high)/2;
            if(isPossible(mid, nums)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
