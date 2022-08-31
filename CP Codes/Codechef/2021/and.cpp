#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e5+5;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    vector<ll> a(N,0);
    vector<ll> b(N,0);
    bool chk = true;
    int n,x;
    cin >> n >> x;

    for(int i=0; i<n; ++i) 
    {
        int p,q;
        cin >> p;
        q = p&x;

        if(p==q)
            a[p]++;
        else{
            a[p]++;
            b[q]++;
        }
    }

    for(int i=0; i<N; ++i)
    {
        if(a[i]>=2)
        {
            cout << "0\n";
            chk = false;
            return 0;
        }
    }
    for(int i=0; i<N; ++i)
    {
        if(a[i]==1 && b[i]>=1)
        {
            cout << "1\n";
            chk = false;
            return 0;
        }
    }
    for(int i=0; i<N; ++i)
    {
        if(b[i]>=2)
        {
            cout << "2\n";
            chk = false;
            return 0;
        }
    }
    if(chk)
    {
        cout << "-1\n";
        return 0;
    }
}