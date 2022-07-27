#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int N,M,i,j;
        scanf("%lld %lld",&N,&M);
        long long int A[N], c=0;

        for(i =0; i<N; i++)
        {
            scanf("%lld",&A[i]);
        }

        for(i =0; i<=M; i++)
        {
            for(j =0; j<=M; j++)
            {
                if(A[i] == j)
                {
                    c++;
                }
            }
        }
        if(c == M)
        printf("Y\n");
        else
        printf("NO\n");
    }
    return 0;
}