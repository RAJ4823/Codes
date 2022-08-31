#include <bits/stdc++.h>
using namespace std;
#define MAXI 3E5+5


void shortroot()
{
    int n,m; 
    cin>>n>>m;

    int a[n];
    int b[m];
    int i,j;

    for (i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<m;i++)
    {
        cin>>b[i];
    }

    int maxi=MAXI;
    int soln[n];
    int LEFT=-1,RIGHT=-1;

    for(i=0;i<n;i++)
    {
       if(i==0){
        soln[i]=0;
       }
       else if(a[i]!=0){
        soln[i]=0;
       }
       else{
        soln[i]=maxi;   
       } 
   }

   for(i=0;i<n;i++)
   {
       if(a[i]==1){
           RIGHT=i;
       }
       if(RIGHT!=-1){
           if(a[i]==0){
            soln[i]=min(soln[i],i-RIGHT);
           }
       }
   }
    for(i=n-1;i>=0;i--)
    {
        if(a[i]==2){
            LEFT=i;  
        }
        if(LEFT!=-1){
            if(a[i]==0){ 
                soln[i] =min(soln[i],LEFT-i);
            }
        }
    }
    for(i=0;i<m;i++)
    {
        j=b[i]-1;
        if(soln[j]!=maxi){
            cout<<soln[j]<<" ";
        }
        else{
            cout<<-1<<" ";
        }
    }
   cout<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        shortroot();
    }
}