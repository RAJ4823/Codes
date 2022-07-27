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
        int n;
        cin >> n;
        int m = n;
        int j = 1;
        while(m--) {
            cout << j << " ";
            for(int i=n; i>0; i--)  {
                if(i!=j)
                cout << i << " ";
            }
            cout << endl;
            j++;
        }
        
    }
    return 0;
}