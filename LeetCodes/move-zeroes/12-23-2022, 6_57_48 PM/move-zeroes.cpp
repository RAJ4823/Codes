// Link: https://leetcode.com/problems/move-zeroes

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: move-zeroes
 *  RUNTIME: 33 ms
 *  MEMORY: 19.3 MB
 *  DATE: 12-23-2022, 6:57:48 PM
 *
 */

// Solution:

class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int i = 0, j = 0;
        int n = arr.size();
        while(j < n) {
            while(j < n && arr[j] == 0) j++;
            if(j >= n) break;
            arr[i] = arr[j];
            i++;
            j++;
        }
        while(i < n) {
            arr[i] = 0;
            i++;
        }
    }
};
