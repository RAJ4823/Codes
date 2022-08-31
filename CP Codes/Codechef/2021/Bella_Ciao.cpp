#include <bits/stdc++.h>
#include <iostream>
#define ll long long
using namespace std;

int main()
{
    //Using Fast input output
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;

    while(t--)
    {
        ll D,P,d,Q;
        cin>>D>>d>>P>>Q;

        ll MONEY = 0;       
        ll n = D/d;         //Number of Pairs
        ll R = D%d;         //Reminder
        ll N = n*(n-1)*0.5; //sum of 1 to (n-1)

        if(R==0)
        {
            MONEY = d*P*n + d*Q*N;
            std::cout<<MONEY<<"\n";
        }
        else
        {
            MONEY = d*P*n + d*Q*N;
            MONEY += R*(P + n*Q);

            std::cout<<MONEY<<"\n";
        }
    }
    return 0;
}