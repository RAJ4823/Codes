#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1000000007;

ll countGoodSubsequences(string s)
{
    ll n = s.size(), ans = 0;
    unordered_map<char, ll> cnt;
    for (auto &ch : s)
    {
        cnt[ch]++;
    }

    ll m = cnt.size();
    for (auto &sc : s)
    {
        ll mini = INT_MAX;
        for (auto &x : cnt)
            mini = min(mini, x.second);

        ll len = mini * m;
        ll total = (len * (len - 1)) % MOD;
        ans = (ans + total) % MOD;
        cnt[sc]--;
    }
    return ans;
}

int main()
{

    string s;
    cin >> s;
    cout << countGoodSubsequences(s);
    return 0;
}