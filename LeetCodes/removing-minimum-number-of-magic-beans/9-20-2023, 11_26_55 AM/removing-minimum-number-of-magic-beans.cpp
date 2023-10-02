// Link: https://leetcode.com/problems/removing-minimum-number-of-magic-beans

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: removing-minimum-number-of-magic-beans
 *  RUNTIME: 277 ms
 *  MEMORY: 165 MB
 *  DATE: 9-20-2023, 11:26:55 AM
 *
 */

// Solution:

#define ll long long
class Solution {
public:
    vector<pair<ll,ll>> getValueCountPairs(vector<int>& beans) {
        vector<pair<ll,ll>> v;
        unordered_map<int, ll> cnt;

        for(auto &bean: beans) cnt[bean]++;
        for(auto &x: cnt) v.push_back({x.first, x.second});
        sort(v.begin(), v.end());

        return v;
    }

    long long minimumRemoval(vector<int>& beans) {
        vector<pair<ll,ll>> v = getValueCountPairs(beans);
        ll n = v.size();

        vector<pair<ll,ll>> rs(n+1), ls(n+1);
        rs[0] = {0, 0};
        ls[n] = {0, 0};

        for(ll i=1; i<=n; i++) {
            ll currSum = rs[i-1].first + (v[i-1].first * v[i-1].second);
            ll currCount = rs[i-1].second + v[i-1].second;
            rs[i] = {currSum, currCount};
        }

        for(ll i=n-1; i>=0; i--) {
            ll currSum = ls[i+1].first + (v[i].first * v[i].second);  
            ll currCount = ls[i+1].second + v[i].second;
            ls[i] = {currSum, currCount};
        }

        ll rightCost = ls[0].first, leftCost = rs[n].first;
        ll ans = min(rightCost, leftCost);

        for(ll i=1; i<=n; i++) {
            ll rightCost = ls[i].first - (ls[i].second * v[i-1].first);
            ll leftCost = rs[i-1].first;
            // cout << v[i-1].first << ' ' << rightCost << ' ' << leftCost << endl;
            ans = min(ans, rightCost + leftCost);
        }

        return ans;
    }
};
