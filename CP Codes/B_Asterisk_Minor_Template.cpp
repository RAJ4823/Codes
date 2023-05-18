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
    int t;
    cin>>t;

    while(t--)
    {
        string a,b;
        cin >> a >> b;
        int n = a.size(), m = b.size();
        string ans = "";
        if(a[0] == b[0]) {
            ans += a[0];
            ans += '*';
        } else if(a[n-1] == b[m-1]) {
            ans += '*';
            ans += a[n-1];
        } else {
            for(int i=0; i<n-1; i++) {
                string temp = a.substr(i, 2);
                if(b.find(temp) != string::npos) {
                    ans += '*';
                    ans += temp;
                    ans += '*';
                    break;
                }
            }
        }
        if(ans == "") cout << "NO\n";
        else cout << "YES\n" << ans << endl; 
    }
    return 0;
}