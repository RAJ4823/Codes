// Link: https://leetcode.com/problems/number-of-black-blocks

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: number-of-black-blocks
 *  RUNTIME: 915 ms
 *  MEMORY: 261.5 MB
 *  DATE: 7-12-2023, 5:42:30 PM
 *
 */

// Solution:

#define ll long long
class Solution {
public:
    unordered_map<ll, ll> mp;
    ll n, m, total;
    void count(int x, int y) {
        if(x < 0 || y < 0 || x >= n-1 || y >= m-1)
            return;
        ll nodeVal = m*x + y;
        mp[nodeVal]++;
    }
    vector<long long> countBlackBlocks(int N, int M, vector<vector<int>>& coordinates) {
        n = N;
        m = M;
        for(auto &coord: coordinates) {
            count(coord[0], coord[1]);
            count(coord[0] - 1, coord[1]);
            count(coord[0], coord[1] - 1);
            count(coord[0] - 1, coord[1] - 1);
        }
        
        vector<ll> ans(5, 0);
        for(auto &x: mp) {
            ll val = x.first;
            // cout << val / m << ' ' << val % m << ' ' << x.second << endl;
            ans[x.second]++;
        }
        
        ll total = 0;
        for(int i=1; i<5; i++) {
            total += ans[i];    
        }
        // cout << endl;
        ans[0] = (n-1)*(m-1) - total;
        return ans;
    }
};
