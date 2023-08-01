// Link: https://leetcode.com/problems/substring-with-largest-variance

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: substring-with-largest-variance
 *  RUNTIME: 508 ms
 *  MEMORY: 6.9 MB
 *  DATE: 7-9-2023, 9:49:51 AM
 *
 */

// Solution:

class Solution {
public:
    int find(char &ch1, char &ch2, string &s, int n) {
        int a = 0, b = 0, cnt = 0;
        int c = 0, d = 0;
        for(int i = 0; i<n; i++) {
            if(s[i] == ch1) a++;
            if(s[i] == ch2) b++;
            if(b > a)   a=0, b=0;
            if(a && b)  cnt = max(cnt, a-b);
            
            if(s[n-i-1] == ch1) c++;
            if(s[n-i-1] == ch2) d++;
            if(d > c)   c=0, d=0;
            if(c && d)  cnt = max(cnt, c-d);
        }
        return cnt;
    }
    int largestVariance(string s) {
        int n = s.size(), ans = 0;
        int count[26] = {0};
        for(auto &ch: s) count[ch - 'a']++;
        
        for(char i='a'; i<='z'; i++) {
            for(char j='a'; j<='z'; j++) {
                if(i == j || count[i - 'a'] == 0 || count[j - 'a'] == 0)
                    continue;
                ans = max(ans, find(i, j, s, n));
            }
        }
        return ans;
    }
};
