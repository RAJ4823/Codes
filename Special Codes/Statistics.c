#include <stdio.h>
#include <math.h>

int main()
{
    printf("Statistics Calculator\n");

    int n, i;
    printf("Enter n : ");
    scanf("%d", &n);

    //Declaring variables
    float x[n], y[n], xy[n];
    float x2[n], y2[n];
    float sum_x = 0, sum_y = 0, sum_x2 = 0, sum_y2 = 0, sum_xy = 0;
    float bxy, byx, r, rx, ry;
    float mean_x, mean_y, var_x, var_y, sd_x, sd_y;

    //X and Y input
    printf("Enter data of x ->\n");
    for(i=0; i<n; i++) {
        scanf("%f",&x[i]);
        x2[i] = pow(x[i],2);
        sum_x += x[i];
        sum_x2 += x2[i];
    }
    printf("Enter data of y ->\n");
    printf("\t x \t y \n");
    for(i=0; i<n; i++) {
        printf("\t%4.2f\t",x[i]);
        scanf("%f",&y[i]);
        y2[i] = pow(y[i],2);
        sum_y += y[i];
        sum_y2 += y2[i];
    }
    for(i=0; i<n; i++) {
        xy[i] = x[i]*y[i];
        sum_xy += xy[i];
    }

    //Table output
    printf("\nStatistics data table -> ( x , y , x^2 , y^2 , xy )\n\n");
    for(int i=0; i<n; i++) {
        printf("  %10.2f",x[i]);
        printf("  %10.2f",y[i]);
        printf("  %10.2f",x2[i]);
        printf("  %10.2f",y2[i]);
        printf("  %10.2f\n",xy[i]);
    }                  
    printf("---------------------------------------------------------------------------\n");
    printf("  %10.2f  %10.2f  %10.2f  %10.2f  %10.2f\n",sum_x, sum_y, sum_x2, sum_y2, sum_xy);
    printf("---------------------------------------------------------------------------\n");

    //Calculation
    mean_x = sum_x/n;
    mean_y = sum_y/n;

    var_x = (sum_x2/n) - pow(mean_x,2);
    var_y = (sum_y2/n) - pow(mean_y,2);

    sd_x  = sqrt(var_x);
    sd_y  = sqrt(var_y);

    rx = sqrt(sum_x2 - (sum_x*sum_x)/n);
    ry = sqrt(sum_y2 - (sum_y*sum_y)/n);

    r = (sum_xy - ((sum_x*sum_y)/n))/(rx*ry);
    bxy = r*(sd_x/sd_y);
    byx = r*(sd_y/sd_x);

    printf("Mean of x =  %.2f\n",mean_x);
    printf("Var  of x =  %.2f\n",var_x);
    printf("SD   of x =  %.2f\n\n",sd_x);
    printf("Mean of y =  %.2f\n",mean_y);
    printf("Var  of y =  %.2f\n",var_y);
    printf("SD   of y =  %.2f\n\n",sd_y);
    printf("Rank = %.2f\n", r);
    printf("bxy = %.2f\n", bxy);
    printf("byx = %.2f\n", byx);
    return 0;
}
