// Link: https://leetcode.com/problems/count-pairs-whose-sum-is-less-than-target

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: count-pairs-whose-sum-is-less-than-target
 *  RUNTIME: 7 ms
 *  MEMORY: 20.5 MB
 *  DATE: 8-24-2023, 10:02:55 PM
 *
 */

// Solution:

class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int count = 0, n = nums.size();
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if(nums[i] + nums[j] < target) count++;
            }
        }
        return count;
    }
};
