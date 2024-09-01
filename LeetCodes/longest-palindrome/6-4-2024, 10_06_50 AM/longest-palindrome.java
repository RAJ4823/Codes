// Link: https://leetcode.com/problems/longest-palindrome

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: longest-palindrome
 *  RUNTIME: 9 ms
 *  MEMORY: 41.8 MB
 *  DATE: 6-4-2024, 10:06:50 AM
 *
 */

// Solution:

public class Solution {
    public int longestPalindrome(String s) {
        HashMap<Character, Integer> charFrequency = new HashMap<>();
        int oddFrequencyCount = 0;
        for (char ch : s.toCharArray()) {
            charFrequency.put(ch, charFrequency.getOrDefault(ch, 0) + 1);
            if (charFrequency.get(ch) % 2 == 1)
                oddFrequencyCount++;
            else
                oddFrequencyCount--;
        }
        if (oddFrequencyCount > 1)
            return s.length() - oddFrequencyCount + 1;
        return s.length();
    }
}
