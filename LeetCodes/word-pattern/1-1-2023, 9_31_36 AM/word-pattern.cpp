// Link: https://leetcode.com/problems/word-pattern

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: word-pattern
 *  RUNTIME: 0 ms
 *  MEMORY: 6.2 MB
 *  DATE: 1-1-2023, 9:31:36 AM
 *
 */

// Solution:

class Solution {
public:
    bool wordPattern(string p, string s) {
        vector<int> vp (26, 0);
        unordered_map<string,int> m;
        int i=0, n = p.size();
        istringstream ss (s);
        string temp;
        
        for(string temp; ss >> temp; ++i) {
            if(i == n || vp[p[i]-'a'] != m[temp]) 
                return false;
            vp[p[i]-'a'] = i+1;
            m[temp] = i + 1;
        }
        if(i != n) return false;
        return true;
    }
};
