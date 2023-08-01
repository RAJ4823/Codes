// Link: https://leetcode.com/problems/next-permutation

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: next-permutation
 *  RUNTIME: 3 ms
 *  MEMORY: 11.9 MB
 *  DATE: 8-1-2023, 10:52:28 AM
 *
 */

// Solution:

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), index = -1;
        for(int i=n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                index = i;
                break;
            }
        }
        if(index != -1) {
            for(int i=n-1; i>=index; i--){
                if(nums[i] > nums[index]){
                    swap(nums[i], nums[index]);
                    break;
                }
            }
        }
        reverse(nums.begin() + index + 1, nums.end());
    }
};
