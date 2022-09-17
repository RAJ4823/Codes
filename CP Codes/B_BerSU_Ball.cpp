#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vpll vector<pair<ll, ll>>
#define vvll vector<vector<ll>>
#define vll vector<ll>
#define mll map<ll, ll>
#define fauto(i, a) for (auto &i : a)
#define f(i, n) for (int i = 0; i < (n); i++)
#define ff(i, a, b) for (int i = (a); i < (b); i++)
#define fr(i, n) for (int i = (n); i >= 0; i--)
#define ffr(i, a, b) for (int i = (a); i >= (b); i--)
#define db1(x) cout << #x << " = " << (x) << "\n";
#define db2(x, y) cout << #x << " = " << (x) << " " << #y << " = " << (y) << "\n"
#define SIZE 1000001
#define MOD 1000000007LL

ll input(vll &v)
{
    ll n, x;
    cin >> n;
    f(i, n)
    {
        cin >> x;
        v.push_back(x);
    }
    return n;
}

int main()
{
    vll boy, girl;
    ll n = input(boy);
    ll m = input(girl);
    ll count = 0;
    sort(boy.begin(), boy.end());
    sort(girl.begin(), girl.end());
    f(i, n)
    {
        f(j, m)
        {
            int diff = abs(boy[i] - girl[j]);
            if (diff <= 1)
            {
                count++;
                girl[j] = -1;
                break;
            }
        }
    }
    cout << count << endl;
    return 0;
}