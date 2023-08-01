// Link: https://leetcode.com/problems/kth-missing-positive-number

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: kth-missing-positive-number
 *  RUNTIME: 7 ms
 *  MEMORY: 9.8 MB
 *  DATE: 3-6-2023, 9:55:41 AM
 *
 */

// Solution:

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> nums;
        int i = 1, j = 0, n = arr.size();
        while(nums.size() <= k) {
            if(j < n && i == arr[j]) j++, i++;
            else nums.push_back(i++);
        }
        return nums[k-1];
    }
};
