// Link: https://leetcode.com/problems/binary-trees-with-factors

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: binary-trees-with-factors
 *  RUNTIME: 24 ms
 *  MEMORY: 10.5 MB
 *  DATE: 10-26-2023, 2:58:20 PM
 *
 */

// Solution:

#define ll long long
class Solution {
public:
    ll MOD = 1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size(), ans = 0;
        sort(arr.begin(), arr.end());
        unordered_map<ll,ll> ways;
        unordered_set<int> nums(arr.begin(), arr.end());

        for(auto &val: arr) ways[val] = 1;

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(arr[j] > sqrt(arr[i])) break;
                ll x = arr[i] / arr[j];
                if(arr[i] % arr[j] == 0 && nums.find(x) != nums.end()) {
                    ll newWays = ways[arr[j]] * ways[x];
                    if(x == arr[j])
                        ways[arr[i]] = (ways[arr[i]] + newWays) % MOD;
                    else
                        ways[arr[i]] = (ways[arr[i]] + newWays * 2) % MOD;

                }
            }
        }

        ll totalWays = 0;
        for(auto &[root, countWays]: ways)
            totalWays = (totalWays + countWays) % MOD;
        return totalWays;
    }
};  
