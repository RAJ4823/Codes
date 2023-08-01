// Link: https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-flips-to-make-a-or-b-equal-to-c
 *  RUNTIME: 3 ms
 *  MEMORY: 5.9 MB
 *  DATE: 6-7-2023, 9:03:19 AM
 *
 */

// Solution:

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;
        while(a || b || c) {
            int da = a & 1;
            int db = b & 1;
            int dc = c & 1;
            // cout << da << ' ' << db << endl;
            a = a>>1;
            b = b>>1;
            c = c>>1;
            if((da | db) != dc) {
                if(dc == 0)
                    flips += (da + db);
                else
                    flips++;
            }
        }
        return flips;
    }
};
