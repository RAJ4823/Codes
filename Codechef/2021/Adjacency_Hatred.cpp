#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int t;
    cin>>t;

    while(t--)
    {
        int n, sum = 0;
        cin >> n;
        int a[n], e[n], o[n];
        int ev = 0, od = 0;

        for(int i=0; i<n; i++) {
            int x;
            cin >> x;
            if(x%2==0) {
                e[ev] = x;
                ev++; 
            }
            else {
                o[od] = x;
                od++;
            }
    }

        for (int j = 0; j < ev; j++)
        {
            a[j] = e[j];
        }
        for (int j = 0; j < od; j++)
        {
            a[j+ev] = o[j];
        }

        if(ev==0 || od == 0) {
            cout << "-1" << endl;
        }
        else {
            for (int i = 0; i < n; i++)
            {
                cout << a[i] << " ";
            }
            cout << endl;
        }
        
    }
    return 0;
}