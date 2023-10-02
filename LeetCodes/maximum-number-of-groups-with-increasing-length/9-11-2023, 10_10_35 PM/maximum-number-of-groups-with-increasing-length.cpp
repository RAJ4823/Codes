// Link: https://leetcode.com/problems/maximum-number-of-groups-with-increasing-length

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: maximum-number-of-groups-with-increasing-length
 *  RUNTIME: 138 ms
 *  MEMORY: 123.9 MB
 *  DATE: 9-11-2023, 10:10:35 PM
 *
 */

// Solution:

#define ll long long
class Solution {
public:
    int maxIncreasingGroups(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        ll sum = 0, ans = 0, cnt = 1;

        for(auto &val: arr) {
            sum += val;
            if(sum >= cnt) {
                ans++;
                cnt += (ans + 1);
            }
        }

        return ans;
    }
};
