// Link: https://leetcode.com/problems/minimum-time-to-make-rope-colorful

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-time-to-make-rope-colorful
 *  RUNTIME: 110 ms
 *  MEMORY: 95.8 MB
 *  DATE: 12-27-2023, 9:44:24 AM
 *
 */

// Solution:

class Solution {
public:
    int minCost(string colors, vector<int>& arr) {
        int sum = arr[0], maxi = arr[0], count = 1;
        int n = arr.size(), ans = 0;
        char prev = colors[0];
        for(int i=1; i<n; i++) {
            if(colors[i] == prev) {
                sum += arr[i];
                maxi = max(maxi, arr[i]);
                count++;
            } else {
                if(count > 1) {
                    ans += (sum - maxi);
                }
                prev = colors[i];
                sum = arr[i];
                maxi = arr[i];
                count = 1;
            }
        }
        if(count > 1) 
            ans += (sum - maxi);
                
        return ans;
    }
};
