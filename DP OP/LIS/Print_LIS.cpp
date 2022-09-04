#include <bits/stdc++.h>
using namespace std;
//* Using code of LIS

vector<int> LIS(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n, 1), hash(n);
    int len = 0, j = 0; // lastindex
    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (arr[prev] < arr[i] && 1 + dp[prev] > dp[i])
            {
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }
        if (dp[i] > len)
        {
            len = dp[i];
            j = i; // last index
        }
    }

    //! Backtracking dp to print LIS
    vector<int> lis;
    lis.push_back(arr[j]);
    while (hash[j] != j)
    {
        j = hash[j];
        lis.push_back(arr[j]);
    }
    reverse(lis.begin(), lis.end());
    return lis;
}

int main()
{
    vector<int> arr = {1, 4, 5, 2, 3, 7, 1, 11, 0};
    vector<int> lis = LIS(arr);
    for (auto it : lis)
        cout << it << ' ';
    cout << endl;
}