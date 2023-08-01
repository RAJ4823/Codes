// Link: https://leetcode.com/problems/put-marbles-in-bags

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: put-marbles-in-bags
 *  RUNTIME: 249 ms
 *  MEMORY: 66.8 MB
 *  DATE: 1-29-2023, 9:21:41 AM
 *
 */

// Solution:

#define ll long long

class Solution {
public:
     ll find(vector<int> &weights, int n, int k) {
        ll min_score = 0, max_score = 0;
        vector<ll> a(n-1), b(n-1);

        for (ll i = 0; i < n - 1; i++) {
            int cost = weights[i] + weights[i + 1];
            a[i] = cost;
            b[i] = cost;
        }

        sort(a.begin(), a.end(), greater<ll>());
        sort(b.begin(), b.end());

        for (ll i = 0; i < k; i++) {
            max_score += a[i];
            min_score += b[i];
        }
        return (max_score - min_score);
    }

    long long putMarbles(vector<int> &weights, int k)
    {
        int n = weights.size();
        if (k == 1 || k == n)
            return 0;

        ll diff = find(weights, n, k-1);
        return diff;
    }
};
