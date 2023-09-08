// Link: https://leetcode.com/problems/excel-sheet-column-title

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: excel-sheet-column-title
 *  RUNTIME: 0 ms
 *  MEMORY: 6 MB
 *  DATE: 8-22-2023, 2:13:52 PM
 *
 */

// Solution:

class Solution {
public:
    std::string convertToTitle(int n) {
        if (n < 27) {
            return std::string(1, 'A' + (n - 1) % 26);
        }
        
        std::string c = "";
        while (n > 0) {
            if (n % 26 == 0) {
                c += 'A' + 25;
                n -= 1;
            } else {
                c += 'A' + n % 26 - 1;
            }
            n /= 26;
        }
        std::reverse(c.begin(), c.end());
        return c;
    }
};
