//? https://www.codingninjas.com/codestudio/problems/longest-bitonic-sequence_1062688?leftPanelTab=1

#include <bits/stdc++.h>
using namespace std;

//* Bitonic means increasing and decreasing
//* IT can just increasing or decreasing also
//* First we have calc dp1 from forward direction then dp2 from reverse direction 
//* Now at each index (dp1[i] + dp2[i] - 1) will give bitonic length

void lis_forward(vector<int> &arr, int n, vector<int> &dp)
{
    for(int i=1; i<n; i++)
    {
        for(int j =0; j<i;j++)
        {
            if(arr[i] > arr[j] && dp[j] + 1 > dp[i])
                dp[i] = dp[j] + 1; 
        }
    }
}

void lis_reverse(vector<int> &arr, int n, vector<int> &dp)
{
    for(int i=n-2; i>=0; i--)
    {
        for(int j =n-1; j>i;j--)
        {
            if(arr[i] > arr[j] && dp[j] + 1 > dp[i])
                dp[i] = dp[j] + 1; 
        }
    }
}

int longestBitonicSequence(vector<int>& arr, int n) {
	vector<int> dp_forward(n,1), dp_reverse(n ,1);
  
  lis_forward(arr, n, dp_forward);
  lis_reverse(arr, n, dp_reverse);
  
  int length, ans = 0;
  for(int i=0;i<n;i++)
  {
      length = (dp_forward[i] + dp_reverse[i] - 1);
      ans = max(ans, length);
  }
  return ans;
} 
