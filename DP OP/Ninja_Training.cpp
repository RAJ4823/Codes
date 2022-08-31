//? https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003

#include <bits/stdc++.h>
using namespace std;

int f(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    if (dp[day][last] != -1)
        return dp[day][last];

    if (day == 0)
    {
        int maxi = 0;
        for (int i = 0; i < 3; i++)
        {
            if (i != last)
                maxi = max(maxi, points[day][i]);
        }
        return dp[day][last] = maxi;
    }

    int maxi = 0;
    for (int i = 0; i < 3; i++)
    {
        if (i != last)
        {
            int point = points[day][i] + f(day - 1, i, points, dp);
            maxi = max(maxi, point);
        }
    }
    return dp[day][last] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return f(n - 1, 3, points, dp);
    // Write your code here.
}