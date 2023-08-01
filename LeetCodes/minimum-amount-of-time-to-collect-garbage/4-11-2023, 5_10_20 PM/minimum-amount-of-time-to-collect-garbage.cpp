// Link: https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-amount-of-time-to-collect-garbage
 *  RUNTIME: 254 ms
 *  MEMORY: 103.8 MB
 *  DATE: 4-11-2023, 5:10:20 PM
 *
 */

// Solution:

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        unordered_map<char, int> lastPos;
        unordered_map<char, int> count;
        int n = garbage.size(), chars = 0;
        for(int i=n-1; i>=0; i--) {
            for(auto &ch: garbage[i]) {
                if(lastPos.find(ch) == lastPos.end()) {
                    lastPos[ch] = i;
                    chars++;
                }
                count[ch]++;
            }
        }

        int m = travel.size();
        vector<int> prefixSum(m+1, 0);
        for(int i=1; i<=m; i++) {
            prefixSum[i] = prefixSum[i-1] + travel[i-1];
        }


        int ans = 0;
        for(auto &x: count) {
            ans += (x.second + prefixSum[lastPos[x.first]]);
        }
        return ans;
    }
};
