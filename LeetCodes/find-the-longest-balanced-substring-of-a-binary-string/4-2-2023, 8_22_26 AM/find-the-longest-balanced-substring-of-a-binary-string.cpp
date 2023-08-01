// Link: https://leetcode.com/problems/find-the-longest-balanced-substring-of-a-binary-string

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: find-the-longest-balanced-substring-of-a-binary-string
 *  RUNTIME: 12 ms
 *  MEMORY: 6.3 MB
 *  DATE: 4-2-2023, 8:22:26 AM
 *
 */

// Solution:

class Solution
{
public:
    int findTheLongestBalancedSubstring(string s)
    {
        int ans = 0, n = s.size();

        for (int i = 0; i < n; i++)
        {
            int j = i;
            int count_1 = 0, count_2 = 0;

            while (j < n)
            {
                if (s[j] == '0') count_1++;
                else break;
                j++;
            }

            int k = j;
            while (k < n)
            {
                int res = (k - i + 1);
                if (s[k] == '1') count_2++;
                else break;
                if (count_1 == count_2) ans = max(ans, res);
                k++;
            }
        }
        
        return ans;
    }
};
