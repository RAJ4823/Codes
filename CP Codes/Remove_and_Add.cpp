#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vpll vector<pair<ll, ll>>
#define vvll vector<vector<ll>>
#define vll vector<ll>
#define mll map<ll, ll>
#define f(i, n) for (int i = 0; i < (n); i++)
#define ff(i, a, b) for (int i = (a); i < (b); i++)
#define fr(i, n) for (int i = (n); i >= 0; i--)
#define ffr(i, a, b) for (int i = (a); i >= (b); i--)
#define db1(x) cout << #x << " = " << (x) << "\n";
#define db2(x, y) cout << #x << " = " << (x) << " " << #y << " = " << (y) << "\n"
#define SIZE 1000001
#define MOD 1000000007LL

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;
        ll a[n], sum = 1;
        map<ll, list<ll>> left;
        map<ll, list<ll>> right;
        mll count, l, r;

        f(i, n)
        {
            cin >> a[i];
            count[a[i]]++;
            l[a[i]]++;
            r[a[i]]++;
        }

        f(i, n)
        {
            if (l[a[i]] > 1)
            {
                left[a[i]].push_back(sum);
                l[a[i]]--;
                sum = 1;
            }
            else
                sum++;
        }
        sum = 1;
        fr(i, n - 1)
        {
            if (r[a[i]] > 1)
            {
                right[a[i]].push_back(sum);
                r[a[i]]--;
                sum = 1;
            }
            else
                sum++;
        }
        ll ans = 0, ls = 0, rs = 0;

        f(i, n)
        {
            if (count[a[i]] > 1)
            {
                if(ls<0) ls = 0;
                if(rs<0) rs = 0;
                ll x = left[a[i]].front() + ls;
                ll y = right[a[i]].front() + rs;
                ans += min(x, y);
                if (x <= y && ls == 0)
                {
                    left[a[i]].pop_front();
                    rs++;
                    ls--;
                }
                else if(rs == 0)
                {
                    right[a[i]].pop_front();
                    ls++;
                    rs--;
                }
                count[a[i]]--;
            }
        }
        cout << ans << endl; 
    }
    return 0;
}