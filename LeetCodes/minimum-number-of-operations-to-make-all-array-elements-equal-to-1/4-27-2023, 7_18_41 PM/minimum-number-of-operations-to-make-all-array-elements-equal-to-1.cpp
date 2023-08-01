// Link: https://leetcode.com/problems/minimum-number-of-operations-to-make-all-array-elements-equal-to-1

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-number-of-operations-to-make-all-array-elements-equal-to-1
 *  RUNTIME: 4 ms
 *  MEMORY: 27.5 MB
 *  DATE: 4-27-2023, 7:18:41 PM
 *
 */

// Solution:

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int g = 0, ones = 0;
        for(int i=0; i<n; i++) {
            if(nums[i] == 1) ones++;
            g = __gcd(g, nums[i]);
        }
        if(g != 1) return -1;
        if(ones > 0) return n - ones;
        
        int mini = INT_MAX;
        for(int i=0; i<n; i++) {
            int cur = nums[i];
            for(int j=i; j<n; j++) {
                cur = __gcd(cur, nums[j]);
                if(cur == 1) {
                    mini = min(mini, j - i);
                }
            }
        }
        return n + mini - 1;
    }
};
