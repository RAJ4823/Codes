// Link: https://leetcode.com/problems/minimum-size-subarray-sum

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-size-subarray-sum
 *  RUNTIME: 32 ms
 *  MEMORY: 28.2 MB
 *  DATE: 7-6-2023, 7:24:33 PM
 *
 */

// Solution:

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0, sum = 0, ans = n + 1;

        while(j < n) {
            sum += nums[j];

            while(i <= j && sum >= target) {
                ans = min(ans, j - i + 1);
                sum -= nums[i];
                i++;
            } 
            j++;
        }
        if(ans == n+1) return 0;
        return ans;
    }
};
