// Link: https://leetcode.com/problems/removing-minimum-number-of-magic-beans

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: removing-minimum-number-of-magic-beans
 *  RUNTIME: 190 ms
 *  MEMORY: 101.1 MB
 *  DATE: 9-20-2023, 11:29:44 AM
 *
 */

// Solution:

#define ll long long
class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(), beans.end());

        ll ans = LONG_LONG_MAX, n = beans.size();
        ll total = 0, curr = 0;
        for(ll val: beans) total += val;

        for(int i=0; i<n; i++) {
            ll cost = curr + total - (beans[i] * (n - i));
            ans = min(ans, cost);
            curr += beans[i];
            total -= beans[i];
        }
        return ans;
    }
};
