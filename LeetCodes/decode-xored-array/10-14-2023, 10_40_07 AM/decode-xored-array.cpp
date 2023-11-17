// Link: https://leetcode.com/problems/decode-xored-array

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: decode-xored-array
 *  RUNTIME: 17 ms
 *  MEMORY: 26.4 MB
 *  DATE: 10-14-2023, 10:40:07 AM
 *
 */

// Solution:

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int x) {
        vector<int> arr;
        arr.push_back(x);
        for(auto &val: encoded) {
            x = val ^ x;
            arr.push_back(x);
        }
        return arr;
    }
};
