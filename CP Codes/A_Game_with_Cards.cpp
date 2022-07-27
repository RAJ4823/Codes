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
    cin>>t;

    while(t--)
    {
        int x,y;
        cin >> x;
        int a[x];
        f(i,x) cin >> a[i];
        cin >> y;
        int b[y];
        f(i,y) cin >> b[i];
        sort(a,a+x);
        sort(b,b+y);
        if(a[x-1] > b[y-1])
        {
            cout << "Alice\n";
            cout << "Alice\n";
        }
        else if(a[x-1] < b[y-1])
        {
            cout << "Bob\n";
            cout << "Bob\n";
        }
        else
        {
            cout << "Alice\n";
            cout << "Bob\n";
        }
    }
    return 0;
}