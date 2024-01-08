// Link: https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: element-appearing-more-than-25-in-sorted-array
 *  RUNTIME: 9 ms
 *  MEMORY: 12.7 MB
 *  DATE: 12-11-2023, 4:18:33 PM
 *
 */

// Solution:

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int count = 0, prev = arr[0], n = arr.size();
        for(auto &val: arr) {
            if(prev == val) {
                count++;
            } else if(count > n / 4) {
                return prev;
            } else {
                count = 1;
                prev = val;
            }
        }
        return prev;
    }
};
