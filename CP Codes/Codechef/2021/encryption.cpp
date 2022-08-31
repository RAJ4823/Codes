#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,p;
    cin >> n >> p;
    ll a[n];

    for(ll i=0; i<n; ++i)   cin >> a[i];

    ll prf[n], suf[n];
    ll sum=0;
    ll mx = -1;

    for(ll i=0; i<n; ++i)
    {
        sum += a[i];
        prf[i] = sum%p;
    }
    sum=0;
    for(ll i=n-1; i>=0; i--)
    {
        sum += a[i];
        suf[i] = sum%p;
    }
    
    for(ll i=0; i<n-1; ++i)
    {
        sum =0;
        sum = prf[i]+suf[i+1];
        mx = max(mx, sum);
    }

    cout << mx << endl;
    return 0;
}

#include <bits/stdc++.h>
#define ll long long
#include <boost/math/common_factor.hpp>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    string a, b;
    cin >> a;
    cin >> b;
    ll sum_a =0, sum_b=0, res=0,  mult =0;
    int A = a.size();
    int B = b.size();
    ll N = boost::math::lcm(A,B);

    if(A<N){
        for(int i=A; i<N; ++i){
            a[i] = a[i-A];
        }
    }
    if(B<N){
        for(int i=B; i<N; ++i){
            b[i] = b[i-B];
        }
    }
    /*
        S P = 1
        R S = 1
        P R = 1
    */
    if((n-N)>N)
    {
        res = (n-N)%N;
        mult = (n-N-res)/N;
    }
    for(ll i=0; i<N; ++i)
    {
        if(a[i]=='R' && b[i]=='P')  sum_b++;
        if(a[i]=='R' && b[i]=='S')  sum_a++;
        if(a[i]=='P' && b[i]=='S')  sum_b++;
        if(a[i]=='P' && b[i]=='R')  sum_a++;
        if(a[i]=='S' && b[i]=='P')  sum_a++;
        if(a[i]=='S' && b[i]=='R')  sum_b++;

        if((n-N)<=N && i==(n-N))
        {
            sum_b += sum_b;
            sum_a += sum_a;
        }
        if((n-N)>N)
        {
            if(res == i)
            {
                sum_a += sum_a;
                sum_b += sum_b;
            }
            if(mult == i)
            {
                sum_b += mult*sum_b;
                sum_a += mult*sum_a;
            }
        }      
    }
    cout << sum_b << " " << sum_a << endl;
    return 0;
}