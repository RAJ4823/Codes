// Link: https://leetcode.com/problems/maximum-number-of-alloys

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: maximum-number-of-alloys
 *  RUNTIME: 55 ms
 *  MEMORY: 55.2 MB
 *  DATE: 9-18-2023, 6:54:47 PM
 *
 */

// Solution:

#define ll long long
class Solution {
public:
    bool isPossible(int n, int mid, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        for(auto &machine: composition) {
            ll sum = 0;
            for (int j = 0; j < n; ++j) {
                ll units = max(0LL, (ll)(machine[j]) * mid - (ll)stock[j]);
                sum += units * (ll)cost[j];
            }
            if (sum <= budget)
                return true;
        }
        return false;
    }
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        int low = 0, high = 1e9;
        int ans = 0;

        while(low <= high) {
            int mid = (low + high)/2;
            
            if(isPossible(n, mid, budget, composition, stock, cost)) {
                ans = max(low, mid);
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
