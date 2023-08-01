// Link: https://leetcode.com/problems/concatenated-words

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: concatenated-words
 *  RUNTIME: 187 ms
 *  MEMORY: 46.7 MB
 *  DATE: 1-27-2023, 1:55:01 PM
 *
 */

// Solution:

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> res;
        unordered_set<string> st(words.begin(), words.end());
    
        for (auto &word: words) {
            int n = word.size();
            vector<int> dp(n + 1, 0);
            dp[0] = 1;
            for (int i = 0; i < n; i++) {
                if (dp[i] == 0) continue;

                for (int j = i + 1; j <= n; j++) {
                    if(j - i >= n) continue;

                    string substr = word.substr(i, j-i);
                    if (st.find(substr) != st.end()) dp[j] = 1;
                }
                
                if (dp[n]) {
                    res.push_back(word);
                    break;
                }
            }
        }
        return res;
    }
};
