// Link: https://leetcode.com/problems/scramble-string

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: scramble-string
 *  RUNTIME: 154 ms
 *  MEMORY: 36.8 MB
 *  DATE: 3-30-2023, 10:32:55 AM
 *
 */

// Solution:

class Solution {
public:
    unordered_map<string,bool> dp;
    bool find(string s1, string s2) {
        int n = s1.size();
        if(s1==s2) return true;   
        if(n==1) return false;
        
        string str = s1 + " " + s2;
        if(dp.find(str) != dp.end()) 
            return dp[str];

        for(int i=1;i<n;i++)
        {
            if(find(s1.substr(0,i),s2.substr(0,i)) && find(s1.substr(i),s2.substr(i)))
                return dp[str] = true;
            
            if(find(s1.substr(0,i),s2.substr(n-i)) && find(s1.substr(i),s2.substr(0,n-i)))
                return dp[str] = true;
        }
        
        return dp[str] = false;
    }

    bool isValid(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        return s1 == s2;
    }

    bool isScramble(string s1, string s2) {
        if(isValid(s1, s2)) {
            return find(s1, s2);
        }
        return false;
    }
};
