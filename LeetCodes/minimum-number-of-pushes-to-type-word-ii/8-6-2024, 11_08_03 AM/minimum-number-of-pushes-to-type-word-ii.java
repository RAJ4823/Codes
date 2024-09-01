// Link: https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-number-of-pushes-to-type-word-ii
 *  RUNTIME: 10 ms
 *  MEMORY: 45.7 MB
 *  DATE: 8-6-2024, 11:08:03 AM
 *
 */

// Solution:

class Solution {
    public int minimumPushes(String word) {
        int[] freq = new int[26];
        for(char c: word.toCharArray()) {
            freq[c - 'a']++;
        }

        Integer[] sortedFreq = new Integer[26];
        for(int i=0; i<26; i++) {
            sortedFreq[i] = -freq[i];
        }
        Arrays.sort(sortedFreq);

        int ans = 0, pushes = 1, keys = 0;
        for(int i=0; i<26; i++) {
            ans += (-sortedFreq[i] * pushes);
            keys++;
            if(keys % 8 == 0) {
                pushes++;
            }
        }
        return ans;
    }
}
