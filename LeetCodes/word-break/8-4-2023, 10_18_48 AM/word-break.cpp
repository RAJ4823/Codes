// Link: https://leetcode.com/problems/word-break

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: word-break
 *  RUNTIME: 4 ms
 *  MEMORY: 7.5 MB
 *  DATE: 8-4-2023, 10:18:48 AM
 *
 */

// Solution:

class Solution {
    public:
        bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
                int n = s.size();
                        std::vector<bool> dp(n + 1, false);
                                dp[0] = true;
                                        int max_len = 0;
                                                for (const auto& word : wordDict) {
                                                            max_len = std::max(max_len, static_cast<int>(word.size()));
                                                                    }

                                                                            for (int i = 1; i <= n; i++) {
                                                                                        for (int j = i - 1; j >= std::max(i - max_len - 1, 0); j--) {
                                                                                                        if (dp[j] && std::find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end()) {
                                                                                                                            dp[i] = true;
                                                                                                                                                break;
                                                                                                                                                                }
                                                                                                                                                                            }
                                                                                                                                                                                    }

                                                                                                                                                                                            return dp[n];
                                                                                                                                                                                                }
                                                                                                                                                                                                

        

};
