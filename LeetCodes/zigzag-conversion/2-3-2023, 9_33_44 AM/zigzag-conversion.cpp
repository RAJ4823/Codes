// Link: https://leetcode.com/problems/zigzag-conversion

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: zigzag-conversion
 *  RUNTIME: 7 ms
 *  MEMORY: 10.5 MB
 *  DATE: 2-3-2023, 9:33:44 AM
 *
 */

// Solution:

class Solution {
public:
    string convert(string str, int n) {
        if(n==1) return str;

        int x = 1, j= 0;
        vector<string> hash(n, "");
        string ans="";

        for(auto &ch: str){
            hash[j] += ch;
            if(j==0)    x = 1;
            if(j==n-1)  x = -1;
            j += x;
        }
        
        for(auto &word: hash){
            ans += word;
        } 
        return ans;
    }
};
