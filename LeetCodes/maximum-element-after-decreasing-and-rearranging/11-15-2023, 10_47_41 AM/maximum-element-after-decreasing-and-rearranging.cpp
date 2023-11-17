// Link: https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: maximum-element-after-decreasing-and-rearranging
 *  RUNTIME: 86 ms
 *  MEMORY: 51.6 MB
 *  DATE: 11-15-2023, 10:47:41 AM
 *
 */

// Solution:

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        arr[0] = 1;

        for (int i = 1; i < arr.size(); ++i) {
            arr[i] = (abs(arr[i] - arr[i - 1]) <= 1) ? arr[i] : arr[i - 1] + 1;
        }

        return arr.back(); 
    }
};
