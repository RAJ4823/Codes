// Link: https://leetcode.com/problems/minimum-cost-to-make-array-equal

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-cost-to-make-array-equal
 *  RUNTIME: 91 ms
 *  MEMORY: 41.5 MB
 *  DATE: 6-21-2023, 2:04:48 PM
 *
 */

// Solution:

#define ll long long

class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        ll n = nums.size();
        ll sum = 0, total = 0, mid, i = 0;
        vector<pair<ll,ll>> v(n);

        for(int i=0; i<n; i++) {
            v[i] = {nums[i], cost[i]};
            total += cost[i];
        }
        sort(v.begin(), v.end());

        while(sum < (total+1)/2 && i < n) {
            sum += v[i].second;
            mid = v[i].first;
            i++;
        }

        ll ans = 0;
        for(int i = 0; i < n;i++)
           ans += abs(1ll*nums[i]-mid)*(1ll*cost[i]);

        return ans; 
    }
};
