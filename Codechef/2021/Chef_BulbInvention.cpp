#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n,p,k;
        int cnt = 0;
        cin >> n >> p >> k;
        int ck = p%k;
        int x = n%ck;
        
        if(ck == p && ck >10)
        cout << p+1 << endl;
        else if(p>=k)
        cout << (ck+1)*x << endl;
        else
        cout << ck*x + 1 <<endl;
    }
    return 0;
}