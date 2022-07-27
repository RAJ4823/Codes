#include <stdio.h>
#include <math.h>

int min(long long int num1, long long int num2) 
{
    return (num1 > num2 ) ? num2 : num1;
}
void solve()
{
    long long int k,n,m,i,j;
    scanf("%lld %lld %lld",&n,&m,&k);

    double A[n+1][m+1];

    for(i = 0; i <= n; i++)
    {
        for(j = 0; j <=m; j++)
        {
            if(i==0 || j==0)
            A[i][j] =0;
            else
            scanf("%lf",&A[i][j]);
        }
    }

    for(i = 0; i <= n; i++)
    {
        double p = 0;
        for(j = 0; j <=m; j++)
        {
            A[i][j] += p;
            p = A[i][j];
        }    
    }
    for(i = 0; i <= m; i++)
    {
        double p = 0;
        for(j = 0; j <=n; j++)
        {
            A[j][i] += p;
            p = A[j][i];
        }    
    }

    long long int min0 = min(m,n), ans=0, u;

    for(u = 1;u <= min0 ;u++)
    {
        for(i = u; i<= n; i++)
        {
            for(j = u; j <= m; j++)
            {
                if((A[i][j] + A[i-u][j-u] - A[i][j-u] - A[i-u][j])/(u*u) >= k)
                 ans++;
            }
        }
    }
    printf("%lld\n",ans);
}

int main()
{
    long long int t;
    scanf("%lld",&t);

    while(t--)
    {
        solve();
    }
    return 0;
}
