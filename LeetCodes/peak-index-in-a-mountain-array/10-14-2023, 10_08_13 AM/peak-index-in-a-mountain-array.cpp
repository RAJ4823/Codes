// Link: https://leetcode.com/problems/peak-index-in-a-mountain-array

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: peak-index-in-a-mountain-array
 *  RUNTIME: 98 ms
 *  MEMORY: 60.1 MB
 *  DATE: 10-14-2023, 10:08:13 AM
 *
 */

// Solution:

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 0, high = arr.size() - 1;

        while(low <= high) {
            int mid = (low + high) / 2;
            if(arr[mid] > arr[mid + 1]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
