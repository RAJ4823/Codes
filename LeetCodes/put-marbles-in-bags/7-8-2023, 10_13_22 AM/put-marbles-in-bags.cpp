// Link: https://leetcode.com/problems/put-marbles-in-bags

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: put-marbles-in-bags
 *  RUNTIME: 266 ms
 *  MEMORY: 66.7 MB
 *  DATE: 7-8-2023, 10:13:22 AM
 *
 */

// Solution:

#define ll long long

class Solution {
public:
    long long putMarbles(vector<int> &weights, int k)
    {
        int n = weights.size();
        if (k == 1 || k == n)
            return 0;

        ll min_score = 0, max_score = 0;
        vector<ll> a(n-1), b(n-1);
        
        for (ll i = 0; i < n - 1; i++) {
            a[i] = b[i] = weights[i] + weights[i + 1];
        }

        sort(a.begin(), a.end(), greater<ll>());
        sort(b.begin(), b.end());

        for (ll i = 0; i < k - 1; i++) {
            max_score += a[i];
            min_score += b[i];
        }

        return (max_score - min_score);
    }
};
