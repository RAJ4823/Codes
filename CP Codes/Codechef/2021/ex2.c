#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);

    while(t--)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);

        if((b<a && a<c) || (c<a && a<b))
        {
            printf("%d\n",a);
        }
        if((a<b && b<c) || (c<b && b<a))
        {
            printf("%d\n",b);
        }
        if((a<c && c<b) || (b<c && c<a))
        {
            printf("%d\n",c);
        }
    }
    return 0;
}
