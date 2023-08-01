// Link: https://leetcode.com/problems/determine-if-string-halves-are-alike

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: determine-if-string-halves-are-alike
 *  RUNTIME: 6 ms
 *  MEMORY: 6.6 MB
 *  DATE: 12-5-2022, 10:09:39 AM
 *
 */

// Solution:

class Solution {
private:
    bool check(char ch)
    {
        if(ch == 'a' || ch == 'e' ||ch == 'i' ||ch == 'o' ||ch == 'u' ||ch == 'A' ||ch == 'E' ||ch == 'I' ||ch == 'O' ||ch == 'U')
            return true;
        return false;
    }

public:
    bool halvesAreAlike(string s) {
        int n = s.length();
        int count = 0;
        for(int i=0; i<n/2; i++)
        {
            if(check(s[i])) count++;
            if(check(s[n-i-1])) count--;
        }
        return (count == 0);
    }
};
