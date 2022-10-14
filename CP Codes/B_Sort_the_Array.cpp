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

int findL(vll &v)
{
    ff(i, 1, v.size())
    {
        if (v[i - 1] > v[i])
            return i - 1;
    }
    return 0;
}

int findR(vll &v)
{
    ffr(i, v.size() - 2, 0)
    {
        if (v[i] > v[i + 1])
            return i + 1;
    }
    return 0;
}

bool check(vll &v)
{
    ff(i, 1, v.size())
    {
        if (v[i - 1] >= v[i])
            return false;
    }
    return true;
}

int main()
{

    int n;
    cin >> n;
    vll v(n);
    f(i, n) cin >> v[i];

    bool flag = true;
    int left = 0, right = 0;
    left = findL(v);
    right = findR(v);

    int i = left, j = right;
    while (left <= right)
    {
        int a = v[left];
        int b = v[right];
        v[left++] = b;
        v[right--] = a;
    }

    if (check(v))
    {
        cout << "yes\n";
        cout << ++i << ' ' << ++j << endl;
    }
    else
        cout << "no\n";

    return 0;
}