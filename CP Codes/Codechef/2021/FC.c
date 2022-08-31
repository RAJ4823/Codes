#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);

    while(t--)
    {
        long long int n,m,i=0,j=0,k=0;

        scanf("%lld %lld",&n,&m);
        long long int f[n],c[m], x[n+m], count =0;

        for(i =0; i<n; i++) scanf("%lld",&f[i]);
        for(i =0; i<n; i++) scanf("%lld",&c[i]);

        while (i <= n && j <= m)
        {
            if (f[i] < c[j])
            {
                x[k] = f[i];
                i++;
            }
            else
            {
                x[k] = -c[j];
                j++;
            }
            k++;
        }

    while (i != n)
    {
        x[k] = f[i];
        i++;
        k++;
    }

    while (j != m)
    {
        x[k] = -c[j];
        j++;
        k++;
    }

        for(i =0; i<n+m; i++)
        {
            if(x[i] < 0 && j==0)
            {
                count ++;
                j=1;
            }
            if(x[i] > 0 && j==1)
            {
                count ++;
                j =0;
            }
        }
        printf("%lld",count);

    }
    return 0;
}