// Link: https://leetcode.com/problems/unique-length-3-palindromic-subsequences

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: unique-length-3-palindromic-subsequences
 *  RUNTIME: 287 ms
 *  MEMORY: 13.3 MB
 *  DATE: 11-14-2023, 9:15:14 PM
 *
 */

// Solution:

class Solution {
public:
    int countPalindromicSubsequence(string inputString) {
        vector<int> mini(26, INT_MAX), maxi(26, INT_MIN);

        for(int i = 0; i < inputString.size(); i++) {
            int charIndex = inputString[i] - 'a';
            mini[charIndex] = min(mini[charIndex], i);
            maxi[charIndex] = max(maxi[charIndex], i);
        }

        int uniqueCount = 0;
        for (int charIndex = 0; charIndex < 26; charIndex++) {
            if (mini[charIndex] == INT_MAX || maxi[charIndex] == INT_MIN) {
                continue;
            }

            unordered_set<char> uniqueCharsBetween;
            for (int j = mini[charIndex] + 1; j < maxi[charIndex]; j++) {
                uniqueCharsBetween.insert(inputString[j]);
            }
            uniqueCount += uniqueCharsBetween.size();
        }

        return uniqueCount;
    }
};
