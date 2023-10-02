// Link: https://leetcode.com/problems/check-if-the-sentence-is-pangram

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: check-if-the-sentence-is-pangram
 *  RUNTIME: 6 ms
 *  MEMORY: 6.7 MB
 *  DATE: 9-13-2023, 9:31:16 AM
 *
 */

// Solution:

class Solution {
public:
    bool checkIfPangram(string sentence) {
        set<char> cnt(sentence.begin(), sentence.end());
        return cnt.size() == 26;
    }
};
