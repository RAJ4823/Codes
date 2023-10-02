// Link: https://leetcode.com/problems/maximum-number-of-groups-with-increasing-length

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: maximum-number-of-groups-with-increasing-length
 *  RUNTIME: 151 ms
 *  MEMORY: 124 MB
 *  DATE: 9-11-2023, 10:08:10 PM
 *
 */

// Solution:

#define ll long long
class Solution {
public:
    int maxIncreasingGroups(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        ll sum = 0, ans = 0;

        for(auto &val: arr) {
            sum += val;
            ll count = (ans + 1) * (ans + 2) / 2;
            if(sum >= count) {
                ans++;
            }
        }

        return ans;
    }
};
