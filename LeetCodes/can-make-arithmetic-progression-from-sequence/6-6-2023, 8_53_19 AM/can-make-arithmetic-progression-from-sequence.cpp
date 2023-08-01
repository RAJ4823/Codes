// Link: https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: can-make-arithmetic-progression-from-sequence
 *  RUNTIME: 4 ms
 *  MEMORY: 9 MB
 *  DATE: 6-6-2023, 8:53:19 AM
 *
 */

// Solution:

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        for(int i=2; i<arr.size(); i++) {
            if(arr[i] - arr[i-1] != arr[1] - arr[0]) {
                return false;
            }
        }
        return true;
    }
};
