// Link: https://leetcode.com/problems/count-the-number-of-vowel-strings-in-range

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: count-the-number-of-vowel-strings-in-range
 *  RUNTIME: 23 ms
 *  MEMORY: 31.8 MB
 *  DATE: 3-12-2023, 8:05:19 AM
 *
 */

// Solution:

class Solution {
public:
    bool isOk(string &s) {
        int n = s.size();
        if(s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u') {
            if(s[n-1] == 'a' || s[n-1] == 'e' || s[n-1] == 'i' || s[n-1] == 'o' || s[n-1] == 'u') {
                return true;
            }
        }
        return false;
    }
    int vowelStrings(vector<string>& words, int left, int right) {
        int count = 0;
        for(int i=left; i<=right; i++) {
            if(isOk(words[i])) count++;
        }
        return count;
    }
};
