// Link: https://leetcode.com/problems/maximum-score-after-splitting-a-string

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: maximum-score-after-splitting-a-string
 *  RUNTIME: 0 ms
 *  MEMORY: 6.5 MB
 *  DATE: 12-22-2023, 10:48:51 PM
 *
 */

// Solution:

class Solution {
public:
    int maxScore(const std::string& s) {
        int max_score = 0;
        int count_zeros_left = 0;
        int count_ones_right = std::count(s.begin(), s.end(), '1');

        for (int i = 0; i < s.size() - 1; ++i) {
            count_zeros_left += (s[i] == '0');
            count_ones_right -= (s[i] == '1');
            max_score = std::max(max_score, count_zeros_left + count_ones_right);
        }

        return max_score;
    }
};
        
    
