#include <bits/stdc++.h>
using namespace std;

//Work : Finding all prime numbers between 2 to N
//input : 20
//output : 2 3 5 7 11 13 17 19

int main() {

    int n,i,j;
    vector<bool> prime(n+1, true);

    cout<<"Enter Limit : ";
    cin>>n;

    for(i=2; i*i<=n; i++) {

        if(prime[i]) {
        for(j=i*i; j<=n; j+=i) {
            prime[j] = false;
        }
        }
    }

    for(i=2; i<=n; i++) {
        if(prime[i]) {
            cout<<i<<' ';
        }
    }

    return 0;
}