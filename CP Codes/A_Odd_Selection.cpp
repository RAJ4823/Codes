#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vpll vector<pair<ll, ll>>
#define vvll vector<vector<ll>>
#define vll vector<ll>
#define pll pair<ll, ll>
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

void find()
{
    int n, x;
    int odd = 0, eve = 0, val;
    cin >> n >> x;
    f(i, n)
    {
        cin >> val;
        (val % 2) ? (odd++) : (eve++);
    }
    bool flag = 0;
    for (int i = 1; i <= min(odd, x); i += 2)
        if ((x - i) <= eve)
            flag = 1;

    if (flag) cout << "Yes" << endl;
    else      cout << "No" << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--) find();
    return 0;
}