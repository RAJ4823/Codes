#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
       ll int a,b,c,p,q,r;
       cin>>a>>b>>c>>p>>q>>r;
       ll int sum1,sum2;
       sum1=a+b+c;
       sum2=(p+q+r)/2;
       if(sum1+p-a>sum2 || sum1+q-b>sum2 || sum1+r-c>sum2){
           cout<<"YES\n";
       }
       else{
           cout<<"NO\n";
       }
    }
    return 0;
}