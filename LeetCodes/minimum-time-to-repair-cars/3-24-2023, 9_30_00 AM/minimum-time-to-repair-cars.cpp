// Link: https://leetcode.com/problems/minimum-time-to-repair-cars

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-time-to-repair-cars
 *  RUNTIME: 172 ms
 *  MEMORY: 53.7 MB
 *  DATE: 3-24-2023, 9:30:00 AM
 *
 */

// Solution:

#define ll long long

class Solution {
public:
    ll countCars(ll minutes, vector<int> &ranks) {
        ll cnt = 0;
        for(ll val: ranks) {
            ll div = minutes / val;
            cnt += (ll)sqrt((double)(div));
        }
        return cnt;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        sort(ranks.begin(), ranks.end());
        int n = ranks.size();
        ll c = cars, r = ranks[n-1];
        ll low = 0, high = r * c * c;
        ll ans = high;
        while(low <= high) {
            ll mid = (low + high) / 2;
            ll cnt = countCars(mid, ranks);
            
            if(cnt >= cars) {
                ans = min(ans, mid);
                high= mid - 1;
            } else {
                low = mid + 1;   
            }
        }
        return ans;
    }
};
