//? https://www.codingninjas.com/codestudio/problems/divisible-set_3754960
//* LDS  = "Longest Divisible Subset"
//* Using code of 'print LIS'

#include <bits/stdc++.h>
using namespace std;

vector<int> LDS(vector<int> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<int> dp(n, 1), hash(n);
    int len = 0, j = 0; // lastindex
    for (int i = 0; i < n; i++)
    {
        hash[i] = i;
        for (int prev = 0; prev < i; prev++)
        {
            if (arr[i] % arr[prev] == 0 && 1 + dp[prev] > dp[i])
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

    //! Backtracking dp to print LDS
    vector<int> lds;
    lds.push_back(arr[j]);
    while (hash[j] != j)
    {
        j = hash[j];
        lds.push_back(arr[j]);
    }
    reverse(lds.begin(), lds.end());
    return lds;
}

int main()
{
    vector<int> arr = {1, 4, 5, 2, 3, 9, 8, 6, 11, 18};
    vector<int> lds = LDS(arr);
    for (auto it : lds)
        cout << it << ' ';
    cout << endl;
}