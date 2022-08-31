#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;z
    int a[n], b[n], c[n], d[n], e[n];
    int pl[n], mi[n], sum[n];
    string s[n];

    for(int i=0; i<n; ++i)
    {
        cin >> s[i];
        cin >> pl[i] >> mi[i];
        cin >> a[i] >> b[i] >> c[i] >> d[i] >> e[i];
        sum[i] = a[i] + b[i] + c[i] + d[i] + e[i] + 100*pl[i] - 50*mi[i];      
    }
    int mx=-1*1e9, ix =0;

    for(int i=0; i<n;++i)
    {
        if(sum[i]>mx)
        {
            mx=sum[i];
            ix = i;
        }
    }
    cout << s[ix] << endl;
    return 0;
}