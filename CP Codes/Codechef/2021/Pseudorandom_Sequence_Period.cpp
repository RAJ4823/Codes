#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e5+5;
int u[N];
int a,b,c,d,e;
 
int main()
{
  
  cin >> a >> b >> c >> d;

  while (!u[d]) 
  {
      u[d] = ++e;
      d = (a*d+b)%c;
  }
  cout << 1+e-u[d];
}