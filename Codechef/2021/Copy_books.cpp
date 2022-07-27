#include <bits/stdc++.h>
#include <iostream>
#define ll long long
using namespace std;

int main()
{
    ll n, a, b, c;
    cin>>n>>a>>b>>c;

    long long mini = 0;

    switch(n%4)
    {
        case 1: mini = min(a*3LL, min(a + b, c));
                break;

        case 2: mini = min(a*2LL, min(b, c*2LL));
                break;

        case 3: mini = min(a, min(b + c, c*3LL));
    }

    cout<<mini;
    return 0;
}