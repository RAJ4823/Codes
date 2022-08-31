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
        int n,x;
        cin >> n;
        int a[n];
        vector<int> o;
        vector<int> e;
        for(int i=0; i<n; i++)
        {
            cin >> a[i];
            if(a[i]%2){
                o.push_back(a[i]);
            }
            else{
                e.push_back(a[i]);
            }
        }
        if(n%2 == 0) {
            if(o.size() == e.size()) {
                 x = o.size();
                for(int i=0; i<x; i++) {
                    cout << o[i] << ' ' << e[i] << ' ';
                }
                cout << "\n";
            }
            else {
                cout << "-1\n";
            }
        }
        else
        {
            if(o.size() == e.size()+1) 
            {
                x = o.size();
                for(int i = 0; i<x; i++) {
                    cout << o[i] << ' ';
                    if(i<x-2)
                    cout << e[i] << ' ';
                }
            }
            else if(o.size()+1 == e.size()) 
            {
                x = e.size();
                for(int i = 0; i<x; i++) {
                    cout << e[i] << ' ';
                    if(i<x-2)
                    cout << o[i] << ' ';
                }
            }
            else
            {
                cout << "-1\n";
            }
        }
    }
    return 0;
}