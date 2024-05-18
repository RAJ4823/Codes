// Link: https://leetcode.com/problems/assign-cookies

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: assign-cookies
 *  RUNTIME: 29 ms
 *  MEMORY: 17.9 MB
 *  DATE: 1-10-2024, 11:32:47 AM
 *
 */

// Solution:

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int count = 0;
        int i=0, j=0;
        while(i < g.size() && j < s.size()) {
            while(j < s.size() && g[i] > s[j]) j++;
            if(j < s.size() && g[i] <= s[j]) {
                count++;
                i++;
                j++;
            }
        }
        return count;
    }
};
