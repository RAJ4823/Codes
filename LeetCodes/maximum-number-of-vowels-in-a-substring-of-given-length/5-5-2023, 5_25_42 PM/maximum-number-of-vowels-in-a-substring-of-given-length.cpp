// Link: https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: maximum-number-of-vowels-in-a-substring-of-given-length
 *  RUNTIME: 22 ms
 *  MEMORY: 10.1 MB
 *  DATE: 5-5-2023, 5:25:42 PM
 *
 */

// Solution:

class Solution {
public:
    int count(char ch) {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return 1;
        return 0;
    }
    int maxVowels(string s, int k) {
        int curr = 0, maxi = 0;
        int n = s.size();

        for(int i=0; i<k; i++) {
            curr += count(s[i]);
        }
        maxi = curr;

        for(int i=k; i<n; i++) {
            curr -= count(s[i - k]);
            curr += count(s[i]);
            maxi = max(maxi, curr);
        }
        return maxi;
    }
};
