#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, x;
        cin >> n >> x;
        string s;
        cin >> s;

        ll l = 0, r = 0, sum[n], i;
        ll maxi = -2, index = 0;

        for(i=0; i<n; i++) {
            if(s[i] == '0') {
                sum[i] = -1;
                l++;
                if(l >= x)
                l=0;
            }
            else {
                sum[i] = l;
                l = 0;
            }
        }
        for(i=n-1; i>=0; i--) {
            if(s[i] == '0') {
                r++;
                if(r >= x)
                r=0;
            }
            else {
                sum[i] += r;
                r = 0;
            }
        }
    
     
        for(i=0; i<n; i++) {
            
            if(sum[i] > maxi) {
                maxi = sum[i];
                index = i;
            }
        }
        s[index] = '0';
     
        ll vacation = 0, f = 0;
        for (i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                f++;
                if (f == x)
                {
                    f = 0;
                    vacation++;
                }
            }
            else
            {
                f = 0;
            }
        }
        cout << vacation << endl;
    }
    return 0;
}