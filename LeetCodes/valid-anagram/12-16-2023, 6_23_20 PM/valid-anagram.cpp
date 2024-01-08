// Link: https://leetcode.com/problems/valid-anagram

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: valid-anagram
 *  RUNTIME: 3 ms
 *  MEMORY: 7.8 MB
 *  DATE: 12-16-2023, 6:23:20 PM
 *
 */

// Solution:

class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size(), m = t.size();
        if(m != n) 
            return false;
        vector<int> count1(26, 0), count2(26, 0);

        for(int i=0; i<n; i++) {
            count1[s[i] - 'a']++;
            count2[t[i] - 'a']++;
        }

        return (count1 == count2);
    }
};
