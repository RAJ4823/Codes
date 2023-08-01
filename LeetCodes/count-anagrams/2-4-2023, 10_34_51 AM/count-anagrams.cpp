// Link: https://leetcode.com/problems/count-anagrams

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: count-anagrams
 *  RUNTIME: 154 ms
 *  MEMORY: 31.7 MB
 *  DATE: 2-4-2023, 10:34:51 AM
 *
 */

// Solution:

#define ll long long

class Solution {
public:
    int MOD = 1e9 + 7;
    ll fact[100005] = {0};

    int modular_inverse(ll n){
        return power(n, MOD-2);
    }

    int power(ll x, ll i)
    {
        ll ans = 1;
        while(i > 0){
            if(i&1)ans = (ans*x)%MOD;
            i >>=1;
            x = (x*x)%MOD;
        }
        return ans;
    }

    int find(string &str) {
        unordered_map<char, ll> m;
        ll n = str.size(), d = 1;

        for(auto &ch : str) m[ch]++;
        for(auto &x: m) {
            if(x.second >  1) {
                d = (d % MOD * fact[x.second] % MOD) % MOD;
            }
        } 
        // cout << n << ' ' << fact[n] << ' ' << d << ' ' << endl;
        return (fact[n] * modular_inverse(d)) % MOD;
    }
    int countAnagrams(string s) {
        string temp = "";
        ll count = 1, n = s.size();
        fact[0] = 1;
        for(ll i=1; i<100005; i++) 
            fact[i] = (i * fact[i-1] % MOD) % MOD;

        vector<string> strs;
        for(int i=0; i<n; i++) {
            if(s[i] == ' ') {
                strs.push_back(temp);
                temp = "";
                continue;
            }
            temp += s[i];
        }
        strs.push_back(temp);

        for(auto &str: strs) {
            count = (count%MOD * find(str)%MOD) % MOD;
        }
        return count;
    }
};
