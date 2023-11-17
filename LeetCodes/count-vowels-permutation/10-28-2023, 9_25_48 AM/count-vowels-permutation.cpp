// Link: https://leetcode.com/problems/count-vowels-permutation

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: count-vowels-permutation
 *  RUNTIME: 0 ms
 *  MEMORY: 6.3 MB
 *  DATE: 10-28-2023, 9:25:48 AM
 *
 */

// Solution:

#define ll long long
class Solution {
public:
    int countVowelPermutation(int n) {
        ll mod = 1e9+7;
        ll a = 1, e = 1, i = 1, o = 1, u = 1;

        for(int k=1; k<n; k++) {
            ll next_a =  e;
            ll next_e = (a + i) % mod;
            ll next_i = (a + e + o + u) % mod;
            ll next_o = (i + u) % mod;
            ll next_u = a;

            a = next_a;
            e = next_e;
            i = next_i;
            o = next_o;
            u = next_u;
        }

        return (a + e + i + o + u) % mod;
    }
};
