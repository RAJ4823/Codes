// Link: https://leetcode.com/problems/neighboring-bitwise-xor

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: neighboring-bitwise-xor
 *  RUNTIME: 357 ms
 *  MEMORY: 259.5 MB
 *  DATE: 5-25-2023, 10:12:38 PM
 *
 */

// Solution:

class Solution {
public:
    bool doesValidArrayExist(vector<int>& b) {
        int sum = 0;
        for(auto &val: b) sum += val;
        return !(sum%2);
    }
};
