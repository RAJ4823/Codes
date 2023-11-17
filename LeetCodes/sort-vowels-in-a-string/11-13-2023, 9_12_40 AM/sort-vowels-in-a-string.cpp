// Link: https://leetcode.com/problems/sort-vowels-in-a-string

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: sort-vowels-in-a-string
 *  RUNTIME: 43 ms
 *  MEMORY: 12.1 MB
 *  DATE: 11-13-2023, 9:12:40 AM
 *
 */

// Solution:

class Solution {
public:
    bool isVowel(char &ch) {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return true;
        if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            return true;
        return false;
    }
    string sortVowels(string s) {
        string vowels = "";
        for(auto &ch: s) {
            if(isVowel(ch))
                vowels += ch;
        }
        sort(vowels.begin(), vowels.end());
        int index = 0;
        for(int i=0; i<s.size(); i++) {
            if(isVowel(s[i])) {
                s[i] = vowels[index++];
            }
        }
        return s;
    }
};
