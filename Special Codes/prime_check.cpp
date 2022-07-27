#include <bits/stdc++.h>
using namespace std;

//Work : Checking that given number is prime or not;
//Input : 5
//Output : Prime

int main()
{
    int n, i;    
    cout<<"Enter a number : ";
    cin>>n;


    for(i=2; i*i<n; i++) {
        if(n%i==0) {
            i=0;
            break;
        }
    }
    if(i==0) {
        cout<<"Not a Prime";
    }
    else {
        cout<<"Prime";
    }
    return 0;
}