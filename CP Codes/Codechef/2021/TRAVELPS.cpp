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
        int n,a,b;
        int sum_a=0,sum_b=0;
        string s = "\0";
        cin >> n >> a >> b;
        cin >> s;
        
        for(int i=0; i<n; ++i) {
            if(s[i]=='0') {
                sum_a++;
            }
            else {
                sum_b++;
            }        }
        cout << (sum_a*a + sum_b*b) << endl;
    }
    return 0;
}