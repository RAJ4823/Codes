// Link: https://leetcode.com/problems/string-to-integer-atoi

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: string-to-integer-atoi
 *  RUNTIME: 0 ms
 *  MEMORY: 7.1 MB
 *  DATE: 1-26-2023, 10:45:36 AM
 *
 */

// Solution:

class Solution {
public:
    int myAtoi(string s) {
        long long int ans = 0;
        for(int i = 0;i < s.size(); i++){
            if(s[i] != ' '){
                if(('a'<=s[i] && s[i]<='z') || ('A' <= s[i] && s[i] <= 'Z') || s[i] == '.') {
                    return 0;
                } 
                else if('0' <= s[i] && s[i] <= '9') {
                    while('0' <= s[i] && s[i] <= '9') {
                        ans = ans*10 + (s[i] - '0');
                        if(INT_MAX <= ans) 
                            return INT_MAX;
                        i++;
                    }
                    return ans;
                }
                else if(s[i]=='+' || s[i]=='-') {
                    char ch = s[i++];
                    while('0' <= s[i] && s[i] <= '9'){
                        if(ch == '+') 
                            ans = ans*10 + (s[i]-'0');
                        else if(ch=='-') 
                            ans = ans*10 - (s[i]-'0');

                        i++;
                        if(INT_MAX <= ans) 
                            return INT_MAX;
                        else if(INT_MIN >= ans) 
                            return INT_MIN;
                    }
                    return ans;
                }
            }
        }
        return ans;
    }
};
