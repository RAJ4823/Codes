// Link: https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: element-appearing-more-than-25-in-sorted-array
 *  RUNTIME: 8 ms
 *  MEMORY: 12.7 MB
 *  DATE: 12-11-2023, 4:19:54 PM
 *
 */

// Solution:

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int x = n / 4;
        for(int i=0; i<n; i++)
            if(arr[i] == arr[i + x])
                return arr[i];
        return 0;
    }
};
