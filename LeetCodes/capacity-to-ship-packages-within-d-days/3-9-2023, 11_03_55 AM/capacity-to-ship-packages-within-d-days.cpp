// Link: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: capacity-to-ship-packages-within-d-days
 *  RUNTIME: 42 ms
 *  MEMORY: 31 MB
 *  DATE: 3-9-2023, 11:03:55 AM
 *
 */

// Solution:

#define ll long long
class Solution {
public:
    ll countDays(ll mid, vector<int> &weights) {
        ll count = 1, weight = 0;
        for(ll val:weights) {
            weight += val;
            if(weight > mid) {
                count++;
                weight = val;
            }
        }
        return count;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        ll low = 0, high = 0, ans = 0;
        for(ll val:weights) {
            low = max(low, val);
            high+=val;
        }

        while(low <= high) {
            ll mid = (low+high)/2;
            if(countDays(mid, weights) <= days) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
