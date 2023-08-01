// Link: https://leetcode.com/problems/minimum-cost-to-make-array-equal

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-cost-to-make-array-equal
 *  RUNTIME: 120 ms
 *  MEMORY: 38.5 MB
 *  DATE: 6-21-2023, 4:44:28 PM
 *
 */

// Solution:

#define ll long long

class Solution {
public:
    ll findCost(vector<int> &nums, vector<int> &cost, ll x) {
        ll currCost = 0;
        for(int i=0; i<nums.size(); i++) {
            currCost += 1LL * abs(nums[i] - x) * cost[i];
        }
        return currCost;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        ll low = 1, high = 1000001;
        ll ans = findCost(nums, cost, low);

        while(low < high) {
            ll mid = (low + high)/2;
            ll cost1 = findCost(nums, cost, mid);
            ll cost2 = findCost(nums, cost, mid+1);
            ans = min(cost1, cost2);
            if(cost1 > cost2) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return ans; 
    }
};
