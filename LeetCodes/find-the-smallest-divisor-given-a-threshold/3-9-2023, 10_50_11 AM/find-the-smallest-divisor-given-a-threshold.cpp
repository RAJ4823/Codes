// Link: https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: find-the-smallest-divisor-given-a-threshold
 *  RUNTIME: 54 ms
 *  MEMORY: 22.4 MB
 *  DATE: 3-9-2023, 10:50:11 AM
 *
 */

// Solution:

#define ll long long
class Solution {
public:
    ll countDivSum(ll mid, vector<int> &nums) {
        ll count=0;
        for(ll val:nums) {
            count += ceil(1.0 * val / mid);
        }
        return count;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        ll low = 1, high = 0;
        for(ll val: nums) high=max(high,val);
        ll ans = high;
        while(low <= high) {
            ll mid = (low+high)/2;
            ll cnt = countDivSum(mid, nums);
            if(cnt <= threshold) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
