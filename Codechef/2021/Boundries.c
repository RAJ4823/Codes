#include <stdio.h>

int main()
{
    int t,N,M;
    scanf("%d",&t);

    while(t--)
    {
        int c=0;
        scanf("%d",&N);

        for(int M=1; M <=N;M++)
        {
            if(N%M <= N/2)
            {
                c++;
            }
        }
        printf("%d\n",c);

    }

}