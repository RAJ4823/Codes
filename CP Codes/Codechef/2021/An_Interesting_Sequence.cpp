#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
     
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int k, sum = 0;
        cin>>k;
        int K = 2*k+1, a[K];
        a[0] = 0;

        for(int i=1; i<= K; i++)
        {
            a[i] = k + i*i;
        }

        for(int i=1; i<K; i++)
        { 
            sum = sum + gcd(a[i],a[i+1]);
        }
        cout<<sum<<endl;
    }
    return 0;
}
