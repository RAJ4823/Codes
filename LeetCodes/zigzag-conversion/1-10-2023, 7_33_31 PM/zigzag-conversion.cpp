// Link: https://leetcode.com/problems/zigzag-conversion

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: zigzag-conversion
 *  RUNTIME: 8 ms
 *  MEMORY: 8.3 MB
 *  DATE: 1-10-2023, 7:33:31 PM
 *
 */

// Solution:

class Solution {
public:
    string convert(string str, int n) {
        if(n==1)
        return str;
        
        int y=0;
        bool flag= true;
        string loc[n];
        
        for(int i=0;i<n;i++)    loc[i]="";
        
        for(int i=0;i<str.length();i++){
            loc[y] += str[i];
            if(y==0)    flag=true;
            if(y==n-1)  flag=false;
            if(flag==true)
                y++;
            else
                y--;
        }

        string ans="";
        
        for(auto &word: loc) ans += word;
        return ans;
    }
};
