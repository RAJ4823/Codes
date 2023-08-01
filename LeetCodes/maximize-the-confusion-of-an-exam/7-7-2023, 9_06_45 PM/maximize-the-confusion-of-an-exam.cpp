// Link: https://leetcode.com/problems/maximize-the-confusion-of-an-exam

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: maximize-the-confusion-of-an-exam
 *  RUNTIME: 19 ms
 *  MEMORY: 10 MB
 *  DATE: 7-7-2023, 9:06:45 PM
 *
 */

// Solution:

class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int n = s.size();
        int start = 0;
        int end = 0;
        int t = 0, f = 0; 
        int ans = 0; 

        while (end < n) {
            t += (s[end] == 'T');
            f += (s[end] == 'F');

            while (t > k && f > k) {
                if (s[start] == 'T')
                    t--;
                else
                    f--;
                start++;
            }

            ans = max(ans, end - start + 1); 
            end++;
        }

        return ans;
    }
};
