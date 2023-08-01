// Link: https://leetcode.com/problems/maximum-running-time-of-n-computers

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: maximum-running-time-of-n-computers
 *  RUNTIME: 223 ms
 *  MEMORY: 55.9 MB
 *  DATE: 7-27-2023, 10:26:10 AM
 *
 */

// Solution:

#define ll long long
class Solution {
public:
    bool isPossible(ll time, vector<int> &bat, ll n) {
        ll sum = 0;
        for(ll val: bat) {
            sum += val;
            if(sum >= time) {
                sum -= time;
                n--;
            }
        }
        return (n <= 0);
    }
    long long maxRunTime(int n, vector<int>& bat) {
        ll low = 1, high = 0;
        sort(bat.begin(),bat.end());
        for(ll val: bat) high+=val;
        high /= n;

        ll ans = 0;
        while(low <= high) {
            ll mid = (low + high) / 2;
            if(isPossible(mid, bat, n)) {
                low = mid + 1;
                ans = max(mid, ans);
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
