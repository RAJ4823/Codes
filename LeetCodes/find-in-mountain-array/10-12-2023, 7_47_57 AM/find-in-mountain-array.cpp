// Link: https://leetcode.com/problems/find-in-mountain-array

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: find-in-mountain-array
 *  RUNTIME: 3 ms
 *  MEMORY: 7.4 MB
 *  DATE: 10-12-2023, 7:47:57 AM
 *
 */

// Solution:

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int search(int left, int right, int target, bool reversed, MountainArray &arr) {
        while(left <= right) {
            int mid = (left + right) / 2;
            int val = arr.get(mid);
            if(val == target)
                return mid;
            
            if(reversed) {
                if(val > target) 
                    left = mid + 1;
                else
                    right = mid - 1;
            } else {
                if(val < target)
                    left = mid + 1;
                else 
                    right = mid - 1;
            }
        }
        return -1;
    }
    int findPeak(int left, int right, MountainArray &arr) {
        while(left <= right) {
            int mid = (left + right) / 2;
            if(arr.get(mid) < arr.get(mid + 1)) 
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }
    int findInMountainArray(int target, MountainArray &arr) {
        int n = arr.length();
        int peak = findPeak(0, n-1, arr);
        if(arr.get(peak) == target) 
            return peak;

        int leftIndex = search(0, peak, target, false, arr);
        int rightIndex = search(peak + 1, n-1, target, true, arr);

        if(leftIndex >= 0 && arr.get(leftIndex) == target) 
            return leftIndex;
        if(rightIndex >= 0 && arr.get(rightIndex) == target)
            return rightIndex;
        return -1;
    }
};
