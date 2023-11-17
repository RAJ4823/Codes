// Link: https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: sort-integers-by-the-number-of-1-bits
 *  RUNTIME: 9 ms
 *  MEMORY: 10.4 MB
 *  DATE: 10-30-2023, 11:09:19 AM
 *
 */

// Solution:

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [&](const int &a, const int &b) {
            if(__builtin_popcount(a) == __builtin_popcount(b))
                return a < b;
            else
                return  __builtin_popcount(a) < __builtin_popcount(b);
        });
        return arr;
    }
};
