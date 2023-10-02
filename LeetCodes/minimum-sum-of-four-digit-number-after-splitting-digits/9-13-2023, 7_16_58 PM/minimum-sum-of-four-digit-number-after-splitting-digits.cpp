// Link: https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-sum-of-four-digit-number-after-splitting-digits
 *  RUNTIME: 2 ms
 *  MEMORY: 6.3 MB
 *  DATE: 9-13-2023, 7:16:58 PM
 *
 */

// Solution:

class Solution {
public:
    int minimumSum(int num) {
        vector<int> arr;
        while(num > 0) {
            arr.push_back(num % 10);
            num /= 10;
        }
        sort(arr.begin(), arr.end());

        int sum1 = 10*arr[0] + arr[2];
        int sum2 = 10*arr[1] + arr[3];
        return sum1 + sum2;
    }
};
