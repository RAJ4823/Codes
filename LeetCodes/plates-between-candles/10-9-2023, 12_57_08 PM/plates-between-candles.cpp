// Link: https://leetcode.com/problems/plates-between-candles

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: plates-between-candles
 *  RUNTIME: 331 ms
 *  MEMORY: 145.5 MB
 *  DATE: 10-9-2023, 12:57:08 PM
 *
 */

// Solution:

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> prevCandle(n, -1), nextCandle(n, n), plates(n, 0);

        // Pre-compute prevCandles
        prevCandle[0] = (s[0] == '|') ? 0 : -1;
        for(int i=1; i<n; i++) {
            prevCandle[i] = (s[i] == '|') ? i : prevCandle[i-1];
        }

        // Pre-compute nextCandle
        nextCandle[n-1] = (s[n-1] == '|') ? n-1 : -1;
        for(int i=n-2; i>=0; i--) {
            nextCandle[i] = (s[i] == '|') ? i : nextCandle[i+1];
        }

        // Pre-compure plates
        plates[0] = (s[0] == '*');
        for(int i=1; i<n; i++) {
            plates[i] = plates[i-1] + (s[i] == '*');
        }

        // Calculate ans
        vector<int> ans;
        for(auto &q: queries) {
            if(nextCandle[q[0]] <= q[1] && prevCandle[q[1]] >= q[0]) {
                ans.push_back(plates[prevCandle[q[1]]] - plates[nextCandle[q[0]]]);
            } else {
                ans.push_back(0);
            }
        }
        return ans;
    }
};
