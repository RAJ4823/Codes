// Link: https://leetcode.com/problems/find-peak-element

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: find-peak-element
 *  RUNTIME: 6 ms
 *  MEMORY: 9.3 MB
 *  DATE: 10-14-2023, 10:12:17 AM
 *
 */

// Solution:

class Solution {
public:
    bool isLesser(int mid, vector<int> &nums) {
        if(mid + 1 >= nums.size()) return false;
        return nums[mid] < nums[mid + 1];
    }
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;

        while(low <= high) {
            int mid = (low + high) / 2;
            if(isLesser(mid, nums)) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};
