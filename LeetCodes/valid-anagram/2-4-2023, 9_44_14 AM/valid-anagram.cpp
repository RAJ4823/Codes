// Link: https://leetcode.com/problems/valid-anagram

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: valid-anagram
 *  RUNTIME: 15 ms
 *  MEMORY: 7.4 MB
 *  DATE: 2-4-2023, 9:44:14 AM
 *
 */

// Solution:

class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size(), m = t.size();
        if(m != n) return false;

        unordered_map<char, int> count;
        for(auto &ch: s) count[ch]++;
        for(auto &ch: t) {
            if(count[ch] == 1) count.erase(ch);
            else count[ch]--;
        }
        if(count.empty()) return true;
        return false;
    }
};
