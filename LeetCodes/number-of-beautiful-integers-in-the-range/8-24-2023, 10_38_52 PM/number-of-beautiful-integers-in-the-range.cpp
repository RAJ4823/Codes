// Link: https://leetcode.com/problems/number-of-beautiful-integers-in-the-range

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: number-of-beautiful-integers-in-the-range
 *  RUNTIME: 2110 ms
 *  MEMORY: 6 MB
 *  DATE: 8-24-2023, 10:38:52 PM
 *
 */

// Solution:

class Solution {
public:
    int isValid(int val) {
        int o = 0, e = 0;
        while(val > 0) {
            if(val & 1) o++;
            else e++;
            val /= 10;
        }
        return (o == e);
    }
    int numberOfBeautifulIntegers(int low, int high, int k) {
        low = ((low - 1) / k + 1) * k;

        int ans = 0;
        while(low <= 1e8 && low <= high) {
            ans += isValid(low);
            low += k;
        }
        return ans;
    }
};
