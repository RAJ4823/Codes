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
        int a[n];
        int zeros = 0, non_zeros = 0;

        for(int i=0; i<n; i++) {
            cin >> a[i];
            if(a[i])
                non_zeros++;
            else
                zeros++;
        }

        cout << max(zeros, non_zeros) << endl;
    }
    return 0;
}