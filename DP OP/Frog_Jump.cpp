//? https://www.codingninjas.com/codestudio/problem-details/frog-jump_3621012

#include <bits/stdc++.h>
using namespace std;
#define ll long long

//! Recursion method
//? TC = O(n^2),  SC = O(n)+ O(n)

// int f(int n, vector<int> &heights)
// {
//     if (n == 0)
//         return 0;
//     int left = f(n - 1, heights) + abs(heights[n] - heights[n - 1]);
//     int right = INT_MAX;
//     if (n > 1)
//         right = f(n - 2, heights) + abs(heights[n] - heights[n - 2]);
//     return min(left, right);
// }

//! Using memoisation (recursive- DP)
//? TC = O(n), SC = O(n) + O(n)

// int f(int n, vector<int> &heights, vector<int> &dp)
// {
//     if (n == 0)
//         return 0;
//     if (dp[n] != -1)
//         return dp[n];
//     int left = f(n - 1, heights, dp) + abs(heights[n] - heights[n - 1]);
//     int right = INT_MAX;
//     if (n > 1)
//         right = f(n - 2, heights, dp) + abs(heights[n] - heights[n - 2]);
//     return dp[n] = min(left, right);
// }

int frogJump(int n, vector<int> &heights)
{
    // return f(n - 1, heights);

    // vector<int> dp(n + 1, -1);
    // return f(n - 1, heights, dp);

    //! Using tabulation (iterative- DP)
    //? TC - O(n), SC - (n)

    // vector<int> dp(n, 0);
    // dp[0] = 0;
    // for (int i = 1; i < n; i++)
    // {
    //     int left = dp[i - 1] + abs(heights[i] - heights[i - 1]);
    //     int right = INT_MAX;
    //     if (i > 1)
    //         right = dp[i - 2] + abs(heights[i] - heights[i - 2]);
    //     dp[i] = min(left, right);
    // }
    // return dp[n - 1];

    //! Space Optimized method
    //?  TC - O(n), SC - O(1)
    int prev1 = 0, prev2 = 0;
    for (int i = 1; i < n; i++)
    {
        int left = prev1 + abs(heights[i] - heights[i - 1]);
        int right = INT_MAX;
        if (i > 1)
            right = prev2 + abs(heights[i] - heights[i - 2]);
        int curr = min(left, right);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}