#include <stdio.h>

int main() {
    
    int t;
    float k1,k2,k3,v;
    
    scanf("%d",&t); //9.578
    
    while(t--)
    {
        scanf("%f %f %f %f",&k1,&k2,&k3,&v);
        float x = 100/(k1*k2*k3*v);
        if(x-9.57 >= 0.005 )
        {
            printf("NO\n");
        }
        else if(x < 9.575)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
	return 0;
}
