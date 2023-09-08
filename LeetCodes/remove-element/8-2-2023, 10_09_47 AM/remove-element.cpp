// Link: https://leetcode.com/problems/remove-element

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: remove-element
 *  RUNTIME: 0 ms
 *  MEMORY: 8.7 MB
 *  DATE: 8-2-2023, 10:09:47 AM
 *
 */

// Solution:

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0, n = nums.size();
        for(int i=0; i<n; i++) {
            if(nums[i] == val) {
                for(int j=i+1; j<nums.size(); j++) {
                    if(nums[j] != val) {
                        swap(nums[i], nums[j]);
                        break;
                    }
                }
            }
        }
        for(int i = n-1; i>=0; i--) {
            if(nums[i] == val) {
                count++;
                nums[i] = '_';
            }
            else
                break;
        }
        return n - count;
    }
};
