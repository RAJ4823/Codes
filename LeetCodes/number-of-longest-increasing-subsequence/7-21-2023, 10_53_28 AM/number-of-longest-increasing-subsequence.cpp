// Link: https://leetcode.com/problems/number-of-longest-increasing-subsequence

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: number-of-longest-increasing-subsequence
 *  RUNTIME: 203 ms
 *  MEMORY: 13.2 MB
 *  DATE: 7-21-2023, 10:53:28 AM
 *
 */

// Solution:

class Solution {
public:
    int findNumberOfLIS(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> dp(n, 1), count(n, 1);
        
        int maxLength = 1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(arr[i] > arr[j] && dp[j]+1 > dp[i])
                {
                    dp[i] = dp[j] +1;
                    count[i] = count[j];
                }
                else if(arr[i] > arr[j] && dp[j]+1==dp[i])
                {
                    count[i] += count[j];
                }
            }
            maxLength = max(maxLength, dp[i]);
        }
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            if(dp[i] == maxLength)
                ans+=count[i];
        }
        return ans;
    }

};
