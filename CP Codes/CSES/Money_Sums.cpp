#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> possibleSums;
    int totalSum = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        totalSum += a[i];
    }

    vector<bool> dp(totalSum + 1, false);

    // Base cases
        dp[0] = true;
    if (a[0] <= totalSum)
        dp[a[0]] = true;

    // Tabulation DP
    for (int i = 1; i < n; i++)
    {
        vector<bool> temp(totalSum + 1, false);
        for (int target = 0; target <= totalSum; target++)
        {
            bool pick = false, notp = false;
            notp = dp[target];
            if (target >= a[i])
                pick = dp[target - a[i]];
            temp[target] = (pick || notp);
        }
        dp = temp;
    }

    // Finding all Possible sum
    for (int currSum = 1; currSum <= totalSum; currSum++)
        if (dp[currSum])
            possibleSums.push_back(currSum);

    // Output
    cout << possibleSums.size() << endl;
    for(auto &sum : possibleSums)
        cout << sum << ' ';
}