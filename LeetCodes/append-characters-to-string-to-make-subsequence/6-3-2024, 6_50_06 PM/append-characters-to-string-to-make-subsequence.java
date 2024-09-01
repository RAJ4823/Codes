// Link: https://leetcode.com/problems/append-characters-to-string-to-make-subsequence

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: append-characters-to-string-to-make-subsequence
 *  RUNTIME: 173 ms
 *  MEMORY: 45.9 MB
 *  DATE: 6-3-2024, 6:50:06 PM
 *
 */

// Solution:

class Solution {
    public int appendCharacters(String s, String t) {
        int n = s.length(), m = t.length();
        int prev = -1;
        for(int j=0; j<m; j++) {
            int nextPrev = -1;
            for(int i=prev+1; i<n; i++) {
                if(s.charAt(i) == t.charAt(j)) {
                    nextPrev = i;
                    break;
                }
            }
            System.out.println(nextPrev);
            if(nextPrev == -1) {
                return (m - j);
            } else {
                prev = nextPrev;
            }
        }
        return 0;
    }
}
