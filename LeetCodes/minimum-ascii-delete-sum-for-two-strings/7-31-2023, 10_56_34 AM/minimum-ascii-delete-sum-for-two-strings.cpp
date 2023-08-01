// Link: https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-ascii-delete-sum-for-two-strings
 *  RUNTIME: 21 ms
 *  MEMORY: 6.6 MB
 *  DATE: 7-31-2023, 10:56:34 AM
 *
 */

// Solution:

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        vector<int> curr(m+1, 0), prev(m+1, 0);
        for(int j=m-1; j>=0; j--) {
            prev[j] = prev[j+1] + s2[j];
        }

        for(int i=n-1; i>=0; i--) {
            curr[m] = prev[m] + s1[i];
                
            for(int j=m-1; j>=0; j--) {
                if(s1[i] == s2[j]) {
                    curr[j] = prev[j+1];
                } else {
                    curr[j] = min(s1[i] + prev[j], s2[j] + curr[j+1]);
                }
            }
            
            prev = curr;
        }
        return curr[0];
    }
};
