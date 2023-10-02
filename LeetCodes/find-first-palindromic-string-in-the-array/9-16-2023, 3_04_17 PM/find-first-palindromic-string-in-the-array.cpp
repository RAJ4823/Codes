// Link: https://leetcode.com/problems/find-first-palindromic-string-in-the-array

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: find-first-palindromic-string-in-the-array
 *  RUNTIME: 27 ms
 *  MEMORY: 19.9 MB
 *  DATE: 9-16-2023, 3:04:17 PM
 *
 */

// Solution:

class Solution {
public:
    bool isPalindrome(string &word) {
        int i=0, j = word.size() -1;
        while(i < j) {
            if(word[i] != word[j]) 
                return false;
            i++;
            j--;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for(auto &word: words) {
            if(isPalindrome(word)) {
                return word;
            }
        }
        return "";
    }
};
