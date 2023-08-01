// Link: https://leetcode.com/problems/add-to-array-form-of-integer

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: add-to-array-form-of-integer
 *  RUNTIME: 44 ms
 *  MEMORY: 27.4 MB
 *  DATE: 2-15-2023, 8:37:39 AM
 *
 */

// Solution:

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        reverse(num.begin(), num.end());
        for (int i = 0; i < num.size(); i++) {
            num[i] += k;
            k = num[i] / 10;
            num[i] %= 10;
        }
        while (k) {
            num.push_back(k%10);
            k /= 10;
        }
        reverse(num.begin(), num.end());
        return num;
    }
};
