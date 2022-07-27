#include <bits/stdc++.h>
#define ll long long
using namespace std;

void toh(int n, char a, char b, char c) {
    
    if(n==1)
    printf("Move 1 from %c to %c\n",a,b);
    else {
        toh(n-1,a,c,b);
        printf("Move %d from %c to %c\n",n,a,b);
        toh(n-1,c,b,a);
    }

}
int main()
{
    int n;
    char a='A',b='B',c='C';
    cout << "Enter the total number of disks in Tower : ";
    cin >> n;

    toh(n,a,c,b);
    
    return 0;
}