// Link: https://leetcode.com/problems/find-the-divisibility-array-of-a-string

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: find-the-divisibility-array-of-a-string
 *  RUNTIME: 56 ms
 *  MEMORY: 28.4 MB
 *  DATE: 2-26-2023, 8:21:21 AM
 *
 */

// Solution:

class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int> ans;
        string prefix = "";
        long long rem = 0;
        
        for(auto &ch: word) {
            prefix += ch;
            int dig = (ch - '0');
            rem = (10*rem + dig) % m;
            
            if(rem == 0) 
                ans.push_back(1);
            else        
                ans.push_back(0);
        }
        return ans;
    }
};
