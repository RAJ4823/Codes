#include <stdio.h>
#include <math.h>

// PROUDLY MADE BY RAJ PATEL
// MATRIX PRO++ v4.0
/*
          | a  b  c |
          | d  e  f |
          | g  h  i |
*/ 

void power(float x[3][3]);
double eigen(double, double, double);   
void explaination(); 
       
void main()
{
    float a,b,c,d,e,f,g,h,i;
    char M;

    explaination();

    //Input of Matrix
    printf("\nEnter your Matrix : \n\n");
    scanf(" %f %f %f",&a ,&b ,&c);
    scanf(" %f %f %f",&d ,&e ,&f);
    scanf(" %f %f %f",&g ,&h ,&i);
    
    float x[3][3]={{a,b,c},{d,e,f},{g,h,i}};
    float m = a*(e*i-f*h)-b*(d*i-f*g)+c*(d*h-e*g);
    start:
    
    printf("\nEnter Method : ");
    scanf(" %c",&M);
    
    if(M=='T' || M=='t')//Transpose
    {
        printf("\nTranspose of Matrix : \n\n");
        printf("   %2.f %2.f %2.f\n",a ,d ,g);
        printf("   %2.f %2.f %2.f\n",b ,e ,h);
        printf("   %2.f %2.f %2.f\n",c ,f ,i);
    }
    
    if(M=='D' || M=='d')//Determinant
    {
        printf("\nDeterminant |M| : %.2f\n",m);
    }
    
    if((M=='A' || M=='I') || (M=='a' || M=='i'))
    {
        float A=e*i-f*h ,D=c*h-b*i ,G=b*f-c*e;
        float B=f*g-d*i ,E=a*i-c*g ,H=c*d-a*f;
        float C=d*h-e*g ,F=b*g-a*h ,I=a*e-b*d;
        
        if(M=='A' || M=='a')//Adjoint
        {
            printf("\nAdjoint of Matrix : \n\n");
            printf("   %3.f  %3.f  %3.f\n",A ,D ,G);
            printf("   %3.f  %3.f  %3.f\n",B ,E ,H);
            printf("   %3.f  %3.f  %3.f\n",C ,F ,I);
        }
        
        if(M=='I' || M=='i')//Inverse
        {
            if(m!=0)
            {
                printf("\nInverse of Matrix : \n\n");
                printf("   %3.2f  %3.2f  %3.2f\n",A/m ,D/m ,G/m);
                printf("   %3.2f  %3.2f  %3.2f\n",B/m ,E/m ,H/m);
                printf("   %3.2f  %3.2f  %3.2f\n",C/m ,F/m ,I/m);
            }
            else
                printf("\nInverse matrix is not possible\n");
        }
    }
    
    if(M=='P' || M=='p')//Power
    {
        power(x);    
    }
    
    if(M=='E' || M=='e')//Eigen Values
    {
        double l, b1,c1,d1,x[3],E[3],I[3],X[3],Y[3],Z[3];
        b1 = a + e + i;
        c1 = e*i-f*h + a*i-c*g + a*e-b*d;
        d1 = m; 
        eigen(b1,c1,d1);
    }  
    printf("-----------------------------\n");
    goto start;
}

//Explaination of methods
void explaination()
{
    printf("Available Methods : \n");
    printf("  T : Transpose\n");
    printf("  D : Determinant\n");
    printf("  A : Adjoint\n");
    printf("  I : Inverse\n");
    printf("  P : Power\n");
    printf("  E : Eigen Values\n");
}

//Method Power : To calculate power of matrix
void power(float a[3][3])
{
    int p,i,j;
    float m2[3][3],m3[3][3],m4[3][3],m5[3][3],m6[3][3],m7[3][3];   
    
    printf("Enter '0' for return to method :\n");
    
    for(i=0;i<3;i++)//Calculation for powers
    {
        for(j=0;j<3;j++)//2
        {
            m2[i][j]=a[i][0]*a[0][j] + a[i][1]*a[1][j] + a[i][2]*a[2][j];
        }
        for(j=0;j<3;j++)//3
        {
            m3[i][j]=m2[i][0]*a[0][j] + m2[i][1]*a[1][j] + m2[i][2]*a[2][j];
        }
        for(j=0;j<3;j++)//4
        {
            m4[i][j]=m3[i][0]*a[0][j] + m3[i][1]*a[1][j] + m3[i][2]*a[2][j];
        }
        for(j=0;j<3;j++)//5
        {
            m5[i][j]=m4[i][0]*a[0][j] + m4[i][1]*a[1][j] + m4[i][2]*a[2][j];
        }
        for(j=0;j<3;j++)//6
        {
            m6[i][j]=m5[i][0]*a[0][j] + m5[i][1]*a[1][j] + m5[i][2]*a[2][j];
        }
        for(j=0;j<3;j++)//7
        {
            m7[i][j]=m6[i][0]*a[0][j] + m6[i][1]*a[1][j] + m6[i][2]*a[2][j];
        }
    }
    
    start:  
    printf("\nPower : ");
    scanf(" %d",&p);
    
    switch(p)
    {
    case 2 :
        for(i=0;i<3;i++)
        {
        printf("\n %6.f%6.f%6.f\n",m2[i][0],m2[i][1],m2[i][2]);
        } 
    break;
    
    case 3 :
        for(i=0;i<3;i++)
        {
        printf("\n %6.f%6.f%6.f\n",m3[i][0],m3[i][1],m3[i][2]);
        }
    break;
    
    case 4 :
        for(i=0;i<3;i++)
        {
        printf("\n %6.f%6.f%6.f\n",m4[i][0],m4[i][1],m4[i][2]);
        }
    break;
    
    case 5 : 
        for(i=0;i<3;i++)
        {
        printf("\n %6.f%6.f%6.f\n",m5[i][0],m5[i][1],m5[i][2]);
        }
    break;
    
    case 6 : 
        for(i=0;i<3;i++)
        {
        printf("\n %6.f%6.f%6.f\n",m6[i][0],m6[i][1],m6[i][2]);
        }
    break;
    
    case 7 : 
        for(i=0;i<3;i++)
        {
        printf("\n %6.f%6.f%6.f\n",m7[i][0],m7[i][1],m7[i][2]);
        }
    break;
    
    default : 
        printf("Enter valid power (From 2-7) :");
    }
    
    if(p!=0)
    goto start;
}

double eigen(double b1, double c1, double d1)
{
    double a=1,p,q,x2,x3,B,C,D;
    double x=-50,z;

    while(x<=50)
    {
        z = pow(x,3) - b1*pow(x,2) + c1*x - d1;
        
        if(z==0)
        {
            //x² + (b+ap)x + (c + bp + ap²)
            p = x;
            B =  p - b1;
            C = c1 - b1*p + p*p;
        
            D = B*B - 4*C;
            
            x2 = -B - sqrt(D);
            x3 = -B + sqrt(D);
            
            printf("\nEigen values : %.2lf, %.2lf, %.2lf\n", p, x2/2, x3/2);
            break;
        }
        x++;
    }
}
            