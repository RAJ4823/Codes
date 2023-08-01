// Link: https://leetcode.com/problems/trapping-rain-water

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: trapping-rain-water
 *  RUNTIME: 16 ms
 *  MEMORY: 20.6 MB
 *  DATE: 2-1-2023, 5:31:44 PM
 *
 */

// Solution:

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left_max(n), right_max(n);
        left_max[0] = height[0];
        right_max[n-1] = height[n-1];
        
        for(int i=1; i<n; i++) {
            left_max[i] = max(height[i], left_max[i-1]);
        }
        for(int i=n-2; i>=0; i--) {
            right_max[i] = max(height[i], right_max[i+1]);
        }

        int sum = 0;
        for(int i=0; i<n;i++) {
            int diff = min(left_max[i], right_max[i]) - height[i];
            sum += max(0, diff);
        }
        return sum;
    }
};
