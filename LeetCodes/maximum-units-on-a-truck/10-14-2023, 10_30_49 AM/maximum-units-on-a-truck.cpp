// Link: https://leetcode.com/problems/maximum-units-on-a-truck

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: maximum-units-on-a-truck
 *  RUNTIME: 30 ms
 *  MEMORY: 16.2 MB
 *  DATE: 10-14-2023, 10:30:49 AM
 *
 */

// Solution:

class Solution {
public:
    int maximumUnits(vector<vector<int>>& arr, int maxi) {
        sort(arr.begin(), arr.end(), [&](const vector<int> &a, const vector<int> &b) {
            return a[1] > b[1];
        });

        int ans = 0;
        for(auto &box: arr) {
            int x = min(box[0], maxi);
            ans += x*box[1];
            maxi -= x;
            if(maxi <= 0) break;
        }
        return ans;
    }
};
