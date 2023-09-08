// Link: https://leetcode.com/problems/search-in-rotated-sorted-array

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: search-in-rotated-sorted-array
 *  RUNTIME: 7 ms
 *  MEMORY: 11.1 MB
 *  DATE: 8-8-2023, 8:32:33 AM
 *
 */

// Solution:

class Solution {
public:
    int binarySearch(vector<int> &v, int i, int j, int target)
    {
        while (i < j) {
            int mid = (i + j) / 2;
            if (v[mid] == target) {
                return mid;
            } 
            else if (v[i] <= v[mid]) {
                if (target >= v[i] && target < v[mid]) {
                    j = mid - 1;
                } else {
                    i = mid + 1;
                }
            } else {
                if (target > v[mid] && target <= v[j]) {
                    i = mid + 1;
                } else {
                    j = mid - 1;
                }
            }
        }
        if(v[i] == target) return i;
        return -1;
    }
 
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i=0; i<n; i++) {
            if(nums[i] == target) return i;
        }
        return -1;
    }
};
