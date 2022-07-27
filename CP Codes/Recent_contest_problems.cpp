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
#define yn(x) (x) ? cout << "YES\n" : cout << "NO\n";
#define ynif(x, y) (x == y) ? cout << "YES\n" : cout << "NO\n";
#define db1(x) cout << #x << " = " << (x) << "\n";
#define db2(x, y) cout << #x << " = " << (x) << " | " << #y << " = " << (y) << "\n"
#define SIZE 1000001
#define MOD 1000000007LL

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        ll n;
        cin >> n;
        map<string,ll> m;
        for(int i=0; i<n; i++)
        {
            string s;
            cin >> s;
            m[s]++;
        }
        cout << m["START38"] << ' ' << m["LTIME108"] << endl;
        
    }
    return 0;
}