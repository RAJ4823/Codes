#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int* var;

    printf("Enter the size of array : ");
    scanf("%d",&n);

    //Dynamic memory allocation with malloc()
    //With calloc() same :  var = (int*) malloc(n,sizeof(int));
    /* Malloc assign garbage values and
       Calloc assign 0 as a values */
    
    var = (int*) malloc(n*sizeof(int));
    
    for(int i=0; i<n; i++)
    {
        printf("Enter element %d : ",i+1);
        scanf("%d",&var[i]);
    }

    printf("\t\nOutput :\n");

    for(int i=0; i<n; i++)
    {
        printf("Element %d is : %d \n",i+1,var[i]);
    }

    //Re allocating memory in var by  using Realloc
    printf("\nEnter new size of array : ");
    scanf("%d",&n);

    var = (int*) realloc(var, n*sizeof(int));

    for(int i=0; i<n; i++)
    {
        printf("Enter new element %d : ",i+1);
        scanf("%d",&var[i]);
    }

    printf("\t\nOutput :\n");

    for(int i=0; i<n; i++)
    {
        printf("New Element %d is : %d \n",i+1,var[i]);
    }

    //Free the var by using free()
    free(var);

    return 0;
}