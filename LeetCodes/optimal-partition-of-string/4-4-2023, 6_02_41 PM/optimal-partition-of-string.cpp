// Link: https://leetcode.com/problems/optimal-partition-of-string

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: optimal-partition-of-string
 *  RUNTIME: 249 ms
 *  MEMORY: 44.6 MB
 *  DATE: 4-4-2023, 6:02:41 PM
 *
 */

// Solution:

class Solution {
public:
    int partitionString(string s) {
        unordered_map<char,int> m;
        int i = 0, j = 0, n = s.size();

        int ans = 1;
        while(j < n) {
            if(m[s[j]] > 0) {
                ans++;
                m.clear();
            }
            m[s[j++]]++;
        }
        return ans;
    }
};
