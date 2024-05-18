// Link: https://leetcode.com/problems/expressive-words

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: expressive-words
 *  RUNTIME: 1 ms
 *  MEMORY: 41.8 MB
 *  DATE: 4-17-2024, 11:17:32 AM
 *
 */

// Solution:

class Solution {
    public int expressiveWords(final String s, final String[] words) {
        int count = 0;

        for(final String word : words)
            if(helper(s, word))
                count++;

        return count;
    }

    private boolean helper(final String s, final String word) {
        if(s.length() < word.length())
            return false;

        int i = 0, j = 0;

        while(i < s.length() && j < word.length()) {
            if(s.charAt(i) != word.charAt(j))
                return false;

            final char curr = word.charAt(j);
            int sCount = 0;

            while(i < s.length() && s.charAt(i) == curr) {
                sCount++;
                i++;
            }

            int wordCount = 0;

            while(j < word.length() && word.charAt(j) == curr) {
                wordCount++;
                j++;
            }

            if(sCount - wordCount < 0 || (sCount - wordCount != 0 && sCount < 3))
                return false;
        }

        return i >= s.length() && j >= word.length();
    }
}
