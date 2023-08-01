// Link: https://leetcode.com/problems/pass-the-pillow

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: pass-the-pillow
 *  RUNTIME: 0 ms
 *  MEMORY: 6 MB
 *  DATE: 3-5-2023, 8:14:32 AM
 *
 */

// Solution:

class Solution {
public:
    int passThePillow(int n, int time) {
        int index = 1, add = 1;
        for (int i = 0; i < time; i++) {
            if (index == 1)
                add = 1;
            else if (index == n) 
                add = -1;
            index += add;
        }
        return index;
    }
};
