//? https://www.codingninjas.com/codestudio/problems/number-of-longest-increasing-subsequence_3751627

#include<bits/stdc++.h>
using namespace std;

//* Using dp of LIS count the occurence of length
//* Then sum up the all count == maxLength

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
