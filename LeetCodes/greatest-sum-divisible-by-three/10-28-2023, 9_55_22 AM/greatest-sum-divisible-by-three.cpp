// Link: https://leetcode.com/problems/greatest-sum-divisible-by-three

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: greatest-sum-divisible-by-three
 *  RUNTIME: 37 ms
 *  MEMORY: 25.3 MB
 *  DATE: 10-28-2023, 9:55:22 AM
 *
 */

// Solution:

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<int> curr(3, 0), prev(3, 0);
        prev[1] = prev[2] = INT_MIN;
        
        for(int i=n-1; i>=0; i--) {
            for(int rem=2; rem>=0; rem--) {
                curr[rem] = max(nums[i] + prev[(rem + nums[i]) % 3], prev[rem]);
            }
            prev = curr;
        } 
        return curr[0];
    }
};
