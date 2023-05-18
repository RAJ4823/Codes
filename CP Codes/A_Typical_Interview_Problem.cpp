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

int main()
{
    int t, i = 1;
    cin>>t;
    string fb = "";
    while(fb.size() < 100)
    {
        if(i % 3 == 0) fb += "F";
        if(i % 5 == 0) fb += "B";
        i++;
    }

    while(t--)
    {
        ll k;
        cin >> k;
        string s;
        cin >> s;
        if(fb.find(s) != string::npos) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}