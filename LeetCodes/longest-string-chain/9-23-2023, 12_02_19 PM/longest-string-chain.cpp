// Link: https://leetcode.com/problems/longest-string-chain

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: longest-string-chain
 *  RUNTIME: 52 ms
 *  MEMORY: 16.9 MB
 *  DATE: 9-23-2023, 12:02:19 PM
 *
 */

// Solution:

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> dp;
        sort(words.begin(), words.end(), [&](const string &a, const string &b) {
            return a.size() < b.size();
        });

        int maxChain = 0;
        for(auto &word: words) {
            dp[word] = 1;
            for(int i=0; i<word.size(); i++) {
                string prev = word.substr(0, i) + word.substr(i+1);
                if(dp.find(prev) != dp.end()) {
                    dp[word] = max(dp[word], dp[prev] + 1);
                }
            }
            maxChain = max(maxChain, dp[word]);
        }
        return maxChain;
    }
};
