#include<bits/stdc++.h>
using namespace std;
 
string s1;
string s2;

int gcd(int a,int b)
{
    if(b==0)
        return a;

    return gcd(b,a%b);
}

int lcm(int a,int b)
{
    return a*b/gcd(a,b);
}

int solve(char a,char b)
{
    if(a=='R'&&b=='P')
        return 1;
    if(a=='P'&&b=='S')
        return 1;
    if(a=='S'&&b=='R')
        return 1;
    return 0;
}
int main()
{
    int n;
    scanf("%d",&n);
    cin>>s1>>s2;
    
    int c = lcm(s1.size(),s2.size());
    int ans1=0,ans2=0;
    int len1 = s1.size(),len2 = s2.size();

    for(int i=0;i<c;i++)
    {
        ans1+=solve(s1[i%len1],s2[i%len2]);
        ans2+=solve(s2[i%len2],s1[i%len1]);
    }

    ans1*=n/c;
    ans2*=n/c;
    int p = n-n/c*c;

    for(int i=0;i<p;i++)
    {
        ans1+=solve(s1[i%len1],s2[i%len2]);
        ans2+=solve(s2[i%len2],s1[i%len1]);
    }
    cout << ans1 <<" "<< ans2 <<endl;
}