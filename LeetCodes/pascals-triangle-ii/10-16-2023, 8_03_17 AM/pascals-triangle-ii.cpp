// Link: https://leetcode.com/problems/pascals-triangle-ii

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: pascals-triangle-ii
 *  RUNTIME: 3 ms
 *  MEMORY: 6.5 MB
 *  DATE: 10-16-2023, 8:03:17 AM
 *
 */

// Solution:

class Solution {
public:
    int nCr(int n, int r) {
        long long res = 1;
        for(int i=0; i<r; i++) {
            res = res * (n - i) / (i + 1);
        }
        return res;
    }

    vector<int> getRow(int n) {
        vector<int> ans;
        for(int i=0; i<=n; i++) {
            ans.push_back(nCr(n, i));
        }
        return ans;
    }
};
