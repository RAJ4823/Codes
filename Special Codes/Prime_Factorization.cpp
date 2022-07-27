#include <bits/stdc++.h>
using namespace std;

//Work : Finding factors of given numbers
//input : 24
//output : 2^3 3^1
//Explain : 2*2*2*3 = 24

int main() {

    int n,i, count = 0;
    cout<<"Enter a number : ";
    cin>>n;

    int root = int(sqrt(n));

    for(i=2; i<root; i++) {
        if(n%i==0) {
            count = 0;
            while(n%i==0) {
                count++;
                n/=i;
            }
            cout<<i<<"^"<<count<<"\n";
        }
    }

    if(n>1) cout<<n<<"^1";
    return 0;
}