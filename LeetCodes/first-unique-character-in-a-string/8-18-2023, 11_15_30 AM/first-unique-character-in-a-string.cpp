// Link: https://leetcode.com/problems/first-unique-character-in-a-string

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: first-unique-character-in-a-string
 *  RUNTIME: 22 ms
 *  MEMORY: 10.8 MB
 *  DATE: 8-18-2023, 11:15:30 AM
 *
 */

// Solution:

class Solution {
public:
    int firstUniqChar(string s) {
        int alpha[26] = {0}, n = s.size();

        for(int i=0; i<n; i++) 
            alpha[s[i] - 'a']++;
        for(int i=0; i<n; i++)  
            if(alpha[s[i] - 'a'] == 1)
                return i;
        return -1;
    }
};
