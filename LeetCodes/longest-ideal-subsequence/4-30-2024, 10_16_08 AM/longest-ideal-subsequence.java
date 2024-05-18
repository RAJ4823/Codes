// Link: https://leetcode.com/problems/longest-ideal-subsequence

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: longest-ideal-subsequence
 *  RUNTIME: 16 ms
 *  MEMORY: 44.5 MB
 *  DATE: 4-30-2024, 10:16:08 AM
 *
 */

// Solution:

class Solution {
    public int longestIdealString(String s, int k) {
        int[] alpha = new int[26];
        int res=0;
        for(char ch:s.toCharArray()){
            int idx =ch-'a';
            int min = Math.max(0, idx-k);
            int max = Math.min(25, idx+k);
            int maxVal=0;
            for(int i=min; i<=max; i++){
                maxVal = Math.max(maxVal, alpha[i]);
            }
            alpha[idx] = maxVal+1;
            res = Math.max(res, maxVal+1);
        }
        return res;
    }
}
