#include <iostream>
using namespace std;
#include <algorithm> 

int main()
{
   int t;
   cin>>t;
   
   while(t--)
   {
     int n,m,k, r=0, x= 0;
     cin>>n>>m>>k;
     
     int user[k], same[n];
     
     for(int i = 0; i<k; i++)
     {
       cin>>user[i];
     }
     sort(user, user + k);
     
     for(int i = 0; i<k; i++)
     {
       if((user[i] == user[i+1]) && (x!=user[i]) && (user[i]<=n))
       {
           same[r] = user[i];
           x = same[r];
           r++;
       }
       
       if(user[i] > n)
       break;
     }
     
     cout<<r<<" ";
     for(int i = 0; i<r; i++)
     {
       cout<<same[i]<<" ";
     }
     cout<<"\n";
   }
   
   return 0;
}