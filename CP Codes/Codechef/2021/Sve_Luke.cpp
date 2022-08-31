#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    double d,l,v1,v2;
    cin>>d>>l>>v1>>v2;
    double num=l-d;
    double den=v1+v2;
    double ans=num/den;

    cout<<setprecision(7)<<ans;
}