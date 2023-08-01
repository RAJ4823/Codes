// Link: https://leetcode.com/problems/maximum-candies-allocated-to-k-children

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: maximum-candies-allocated-to-k-children
 *  RUNTIME: 186 ms
 *  MEMORY: 84.4 MB
 *  DATE: 3-8-2023, 10:44:17 AM
 *
 */

// Solution:

#define ll long long
class Solution {
public:
    ll find(ll mid, vector<int> &candies) {
        ll count = 0;
        for(ll x: candies) count += (x / mid);
        return count;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        ll minCandies = 1, maxCandies = 0, sum = 0;
        for(auto &val: candies) {   
            sum += val;
        } 
        if(sum < k) return 0;
        if(sum ==k) return 1;
        ll ans = 0;
        maxCandies = sum / k;
        while(minCandies <= maxCandies) {
            ll mid = (maxCandies + minCandies)/2;
            if(find(mid, candies) >= k) {
                minCandies = mid+1;
                ans = mid;
            } 
            else {
                maxCandies = mid-1;
            } 
        }
        return ans;
    }
};
