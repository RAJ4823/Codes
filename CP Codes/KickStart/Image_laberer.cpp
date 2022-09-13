#include <bits/stdc++.h>
using namespace std;
#define ll long long

double solve()
{
   ll n,m;
   double total = 0;
   cin >> n >> m;
   ll arr[n];
   
   for (int i = 0; i < n; i++)
   {
     cin >> arr[i];
     total += arr[i];
   }
   
   double sum = 0,med;
   ll k = (n-m+1);
   
   sort (arr, arr + n);
   for (int i = k; i < n; i++) {
     sum += arr[i];
   }
   if(n%2){
    med = arr[i/2];
   }
   else{
     med = arr[i/2] + arr[(i-1)/2];
     med /= 2;
   }
   
   return (med + sum);
}

int main()
{
    int cases;
    cin >> cases;
    for(int t=1; t<=cases; t++)
    {
      cout << "Case #" << t << ": ";
      cout << solve() << endl;
    }
}
