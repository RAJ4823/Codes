// Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: find-first-and-last-position-of-element-in-sorted-array
 *  RUNTIME: 3 ms
 *  MEMORY: 14 MB
 *  DATE: 10-9-2023, 12:40:52 PM
 *
 */

// Solution:

class Solution {
public:
    int binarySearch(vector<int> &nums, int tar, bool findLeft) {
        int low = 0, high = nums.size() - 1, index = -1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(nums[mid] == tar) {
                index = mid;

                if(findLeft) 
                    high = mid - 1;
                else         
                    low = mid + 1;
            } else if(nums[mid] < tar) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return index;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = binarySearch(nums, target, true);
        int last = binarySearch(nums, target, false);

        if(first <= last) {
            return {first, last};
        }
        return {-1, -1};
    }
};
