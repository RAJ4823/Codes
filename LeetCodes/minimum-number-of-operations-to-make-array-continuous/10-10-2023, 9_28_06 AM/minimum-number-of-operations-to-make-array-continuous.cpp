// Link: https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-number-of-operations-to-make-array-continuous
 *  RUNTIME: 143 ms
 *  MEMORY: 64.5 MB
 *  DATE: 10-10-2023, 9:28:06 AM
 *
 */

// Solution:

class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), i = 0, maxi = 1, count = 1; 
        
        for (int j = 1; j < n; ++j) {
            if (nums[j] == nums[j - 1]) {
                continue;
            }

            while (nums[j] - nums[i] > n - 1) {
                if(i<n && nums[i+1] == nums[i]){
                    count++;
                }
                i++;
                count--;
            }
            count++;
            maxi = max(maxi, count);
        }

        return (n - maxi);
    }
};
