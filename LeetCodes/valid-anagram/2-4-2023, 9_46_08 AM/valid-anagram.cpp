// Link: https://leetcode.com/problems/valid-anagram

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: valid-anagram
 *  RUNTIME: 6 ms
 *  MEMORY: 7.1 MB
 *  DATE: 2-4-2023, 9:46:08 AM
 *
 */

// Solution:

class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size(), m = t.size();
        if(m != n) return false;
        vector<int> count1(26, 0), count2(26, 0);
        for(int i=0; i<n; i++) {
            count1[s[i] - 'a']++;
            count2[t[i] - 'a']++;
        }
        if(count1 == count2) return true;
        return false;
    }
};
