// Link: https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: reduction-operations-to-make-the-array-elements-equal
 *  RUNTIME: 166 ms
 *  MEMORY: 83.1 MB
 *  DATE: 11-19-2023, 6:13:58 PM
 *
 */

// Solution:

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), count = 0, sum = 0;
        
        for(int i=1; i<n; i++) {
            if(nums[i] > nums[i-1]) {
                sum++;
            }
            count += sum;
        }
        return count;
    }
};
