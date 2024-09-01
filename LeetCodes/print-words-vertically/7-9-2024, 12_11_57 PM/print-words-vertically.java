// Link: https://leetcode.com/problems/print-words-vertically

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: print-words-vertically
 *  RUNTIME: 6 ms
 *  MEMORY: 41.6 MB
 *  DATE: 7-9-2024, 12:11:57 PM
 *
 */

// Solution:

class Solution {
    public List<String> printVertically(String s) {
        String[] words = s.split(" ");
        int maxLength = 0;
        for(String word: words) {
            maxLength = Math.max(maxLength, word.length());
        }

        List<String> ans = new ArrayList<>();
        for(int i=0; i<maxLength; i++) {
            String str = "";
            for(String word: words) {
                if(i < word.length()) {
                    str += word.charAt(i);
                } else {
                    str += " ";
                }
            }
            ans.add(str.stripTrailing());
        }
        return ans;
    }

}
