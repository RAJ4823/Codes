// Link: https://leetcode.com/problems/binary-search

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: binary-search
 *  RUNTIME: 43 ms
 *  MEMORY: 27.6 MB
 *  DATE: 4-1-2023, 9:17:21 AM
 *
 */

// Solution:

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        while(low <= high) {
            int mid = (low + high)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target) 
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
};
