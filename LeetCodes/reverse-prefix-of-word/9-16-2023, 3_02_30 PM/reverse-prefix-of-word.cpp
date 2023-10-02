// Link: https://leetcode.com/problems/reverse-prefix-of-word

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: reverse-prefix-of-word
 *  RUNTIME: 0 ms
 *  MEMORY: 6.6 MB
 *  DATE: 9-16-2023, 3:02:30 PM
 *
 */

// Solution:

class Solution {
public:
    string reversePrefix(string word, char ch) {
        int index = -1, n = word.size();

        for(int i=0; i<n; i++) {
            if(word[i] == ch) {
                index = i;
                break;
            }
        }

        if(index == -1) return word;

        int i = 0, j = index;

        while(i < j) {
            swap(word[i++], word[j--]);
        }
        return word;
    }
};
