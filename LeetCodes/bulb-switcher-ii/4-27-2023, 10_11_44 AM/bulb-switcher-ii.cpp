// Link: https://leetcode.com/problems/bulb-switcher-ii

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: bulb-switcher-ii
 *  RUNTIME: 3 ms
 *  MEMORY: 6.1 MB
 *  DATE: 4-27-2023, 10:11:44 AM
 *
 */

// Solution:

class Solution {
public:
    int flipLights(int n, int m) {
        if (m == 0 || n == 0) {
            return 1;
        }
        else if (n == 1) {
            return 2;
        }
        else if (n == 2) {
            return (m == 1) ? 3 : 4;
        }
        else if (m == 1) {
            return 4;
        }
        else if (m == 2) {
            return 7;
        }
        return 8;
    }
};
