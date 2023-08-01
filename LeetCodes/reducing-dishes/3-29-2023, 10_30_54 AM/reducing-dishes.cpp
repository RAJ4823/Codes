// Link: https://leetcode.com/problems/reducing-dishes

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: reducing-dishes
 *  RUNTIME: 42 ms
 *  MEMORY: 20.8 MB
 *  DATE: 3-29-2023, 10:30:54 AM
 *
 */

// Solution:

class Solution {
public:
    int n = 0;
    int sumAll(int inx, int mul, vector<int> &arr) {
        int sum = 0;
        for(int i=inx; i<n; ++i) {
            sum += (arr[i] * mul);
            mul++;
        }
        return sum;
    }

    // int find(int inx, int mul, vector<int> &arr, vector<vector<int>> &dp) {
    //     if(inx >= n) return 0;
    //     if(dp[inx][mul] != -1) return dp[inx][mul];

    //     if(arr[inx] >= 0) {
    //         return dp[inx][mul] = sumAll(inx, mul, arr);
    //     }

    //     int take = arr[inx] * mul + find(inx + 1, mul + 1, arr, dp);
    //     int nottake = find(inx + 1, mul, arr, dp);
    //     return dp[inx][mul] = max(take, nottake);
    // }

    int maxSatisfaction(vector<int>& arr) {
        n = arr.size();
        sort(arr.begin(), arr.end());
        vector<vector<int>> dp(n + 1, vector<int> (n+1, 0));
        // return find(0, 1, arr, dp);

        int inx = n;
        for(int i=0; i<n; i++) {
            if(arr[i] >= 0) {
                inx = i;
                break; 
            }
        }

        if(inx == n) return 0;
        
        for(int j = inx + 1; j>0; j--) {
            dp[inx][j] = sumAll(inx, j, arr);
        }

        for(int i = inx - 1; i>=0; i--) {
            for(int j=n-2; j>0; j--) {
                dp[i][j] = max(dp[i+1][j+1] + arr[i] * j, dp[i+1][j]);
            }
        }
        return dp[0][1];
    }
};
