#include <stdio.h>
#include <math.h>

int main()
{
    int t,N;
    scanf("%d",&t);
    
    while(t--)
    {
        scanf("%d",&N);
        
        int x,y;
        x = N*(pow(6,N)+pow(5,N)+pow(4,N)+pow(3,N)+pow(2,N));
        y = pow(2,N);
        
        for(int i=2;i<=N; i=i+4)
        {
        if(N==1 || N==i)
        printf("%d",x);
        }

    }
    return 0;
}