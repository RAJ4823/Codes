// Link: https://leetcode.com/problems/max-consecutive-ones-iii

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: max-consecutive-ones-iii
 *  RUNTIME: 39 ms
 *  MEMORY: 55.8 MB
 *  DATE: 11-9-2023, 6:48:03 PM
 *
 */

// Solution:

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size(), left = 0, right = 0;
        int maxi = 0, zero = 0;

        while(right < n) {
            if(nums[right] == 0)
                zero++;

            while(zero > k) {
                if(nums[left] == 0)
                    zero--;
                left++;
            }

            maxi = max(maxi, right - left + 1);
            right++;
        }
        return maxi;
    }
};
