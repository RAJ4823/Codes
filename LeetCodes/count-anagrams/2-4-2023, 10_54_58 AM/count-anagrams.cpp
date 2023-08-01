// Link: https://leetcode.com/problems/count-anagrams

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: count-anagrams
 *  RUNTIME: 134 ms
 *  MEMORY: 16.4 MB
 *  DATE: 2-4-2023, 10:54:58 AM
 *
 */

// Solution:

#define ll long long

class Solution {
public:
    int MOD = 1e9 + 7;
    ll fact[100005] = {0};

    int power(ll x, ll i)
    {
        ll ans = 1;
        while(i > 0){   
            if(i & 1) ans = (ans * x) % MOD;   
            i >>= 1; 
            x = (x * x) % MOD;
        }
        return ans;
    }

    int find(string &str, unordered_map<char, ll> &m) {
        ll n = str.size(), div = 1;
        for(auto &[ch, val]: m) {
            if(val >  1) div = (div % MOD * fact[val] % MOD) % MOD;
        } 
        return (fact[n] * power(div, MOD-2)) % MOD;
    }

    int countAnagrams(string s) {
        string temp = "";
        ll count = 1, n = s.size();

        fact[0] = 1;
        for(ll i=1; i<100005; i++) {
            fact[i] = (i * fact[i-1] % MOD) % MOD;
        } 
        
        unordered_map<char, ll> m;
        for(int i=0; i<n; i++) {
            if(s[i] == ' ') {
                count = (count%MOD * find(temp, m)%MOD) % MOD;
                temp = "";
                m.clear();
                continue;
            }
            temp += s[i];
            m[s[i]]++;
        }
        count = (count%MOD * find(temp, m)%MOD) % MOD;
        return count;
    }
};
