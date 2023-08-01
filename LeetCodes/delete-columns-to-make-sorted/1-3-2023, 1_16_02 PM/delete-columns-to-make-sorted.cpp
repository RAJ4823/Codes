// Link: https://leetcode.com/problems/delete-columns-to-make-sorted

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: delete-columns-to-make-sorted
 *  RUNTIME: 95 ms
 *  MEMORY: 12.3 MB
 *  DATE: 1-3-2023, 1:16:02 PM
 *
 */

// Solution:

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int len = strs[0].length();
        int ans = 0;

        for(int col = 0; col < len; col++) {
            for(int i = 0; i<n-1; i++) {
                if(strs[i][col] > strs[i+1][col]) {
                    ans++;
                    break;
                }
            }
        }  
        return ans;
    }
};
