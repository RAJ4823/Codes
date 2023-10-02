// Link: https://leetcode.com/problems/count-pairs-of-points-with-distance-k

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: count-pairs-of-points-with-distance-k
 *  RUNTIME: 2863 ms
 *  MEMORY: 88.3 MB
 *  DATE: 9-19-2023, 6:23:36 PM
 *
 */

// Solution:

#define ll long long
class Solution {
public:
    int countPairs(vector<vector<int>>& arr, int k) {
        int n = arr.size();
        map<pair<int,int>, ll> mp;
        vector<pair<pair<int,int>, ll>> v;
        ll ans = 0;
        
        for(auto &x: arr) {
            mp[{x[0], x[1]}]++;
        }
        for(auto &x: mp) {
            v.push_back({x.first, x.second});
        }
        int m = v.size();
        for(int i=0; i<m; i++) {
            for(int j=i+1; j<m; j++) {
                ll dist = (v[i].first.first ^ v[j].first.first) + (v[i].first.second ^ v[j].first.second);
                ll count = (v[i].second * v[j].second);
                if(dist == k) {
                    ans += count;
                }
            }
        }
        for(auto &x: v) {
            ll dist = (x.first.first ^ x.first.first) + (x.first.second ^ x.first.second);
            ll count = x.second * (x.second - 1) / 2;
            if(dist == k && x.second > 1) {
                ans += count;
            }
        }
        return ans;
    }
};
