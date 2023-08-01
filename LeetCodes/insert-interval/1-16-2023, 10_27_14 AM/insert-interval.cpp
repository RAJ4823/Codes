// Link: https://leetcode.com/problems/insert-interval

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: insert-interval
 *  RUNTIME: 12 ms
 *  MEMORY: 17.2 MB
 *  DATE: 1-16-2023, 10:27:14 AM
 *
 */

// Solution:

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& in, vector<int>& newin) {
        int n = in.size();
        int s = newin[0], e = newin[1];
        if(n == 0) return {{s, e}};
        int i = 0;

        vector<vector<int>> ans;
        while(i < n && in[i][1] < s) 
            ans.push_back({in[i][0], in[i++][1]});

        if(i < n) {    
            int start = min(s, in[i][0]), end = e;
            while(i < n && in[i][0] <= e) i++;
            if(i > 0)
                end = max(e, in[i-1][1]);
            ans.push_back({start, end});

            while(i<n)          
                ans.push_back({in[i][0], in[i++][1]});
        } 
        else {
            ans.push_back({s,e});
        }

        
        
        return ans;
    }
};
