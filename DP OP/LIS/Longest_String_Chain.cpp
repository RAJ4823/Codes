//? https://www.codingninjas.com/codestudio/problems/longest-string-chain_3752111
#include <bits/stdc++.h>
using namespace std;

bool compare(string &s1, string &s2)
{
    //* s1 is greater than s2 because of subsequence pattern
    
    int n = s1.size();
    int m = s2.size();
    
    if(n != m + 1)
       return false;
    
    int i=0, j = 0;
    while(i<n)
    {
        if(j<m && s1[i] == s2[j])
        {
            i++;
            j++;
        }
        else
            i++;
    }
    if(i == n && j == m)
        return true;
    return false;
}

bool sortByLength(string &s1, string &s2)
{
    return (s1.size() < s2.size());
}

int longestStrChain(vector<string> &arr)
{
    int n = arr.size();
    vector<int> dp(n, 1);
    int ans = 1;
    
    //* Here we have to use sequence means we can pick any string from given array 
    //* So to match with this subsequence code we have to sort given sting by their LENGTH
    sort(arr.begin(), arr.end(), sortByLength);
               
    for(int i=1;i<n;i++)
    {
        for(int j=0; j<i;j++)
        {
            if(compare(arr[i],arr[j]) && dp[j] + 1 > dp[i])
                dp[i] = dp[j] + 1;
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}
