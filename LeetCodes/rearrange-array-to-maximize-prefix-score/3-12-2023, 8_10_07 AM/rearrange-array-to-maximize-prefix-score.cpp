// Link: https://leetcode.com/problems/rearrange-array-to-maximize-prefix-score

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: rearrange-array-to-maximize-prefix-score
 *  RUNTIME: 186 ms
 *  MEMORY: 83.1 MB
 *  DATE: 3-12-2023, 8:10:07 AM
 *
 */

// Solution:

class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long n = nums.size(), count = 0, sum = 0;
        for(int i = n-1; i>=0; i--) {
            sum+=nums[i];
            if(sum > 0) count++;
            else break;
        }
        return count;
    }
};
