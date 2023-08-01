// Link: https://leetcode.com/problems/unique-paths

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: unique-paths
 *  RUNTIME: 0 ms
 *  MEMORY: 5.9 MB
 *  DATE: 3-27-2023, 10:34:13 AM
 *
 */

// Solution:

class Solution {
public:
    int uniquePaths(int m, int n) {
        // uniquePahs: (m+n-2)C(n-1) = (m+n-2)!/ ((m-1)! * (n-1)!)
        long long path = 1;
        for (long long i = n; i <= (m + n - 2); i++) {
            path *= i;
            path /= (i - n + 1);
        }
        return path;
    }
};
