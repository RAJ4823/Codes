// Link: https://leetcode.com/problems/rotate-function

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: rotate-function
 *  RUNTIME: 101 ms
 *  MEMORY: 96.2 MB
 *  DATE: 12-16-2023, 6:40:01 PM
 *
 */

// Solution:

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int size = nums.size();
        int sum1 = 0, sum2 = 0;

        for(int i=0;i<nums.size();i++){
            sum1 += nums[i];
            sum2 += (i * nums[i]);
        }

        int ans = INT_MIN, idx = nums.size()-1;
        for(int i = 0; i < nums.size(); i++){
          int res = sum2 + sum1 - (size * nums[idx--]);
          sum2 = res;
          ans = max(res,ans);
        }
        return ans;
    }
};
