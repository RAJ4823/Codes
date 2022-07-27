#include <stdio.h>

void print(int a[], int n){
    for(int i=0; i<n; i++) {
        printf("%d ",a[i]);
    }
}

void insetion_sort(int a[], int n) {
    int i,j,temp;
    for(i=1; i<=n-1; i++) {
        temp = a[i];
        j = i-1;
        
        while(j>=0 && a[j] > temp) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
    }
}

int main()
{
    int a[] = {8,4,7,12,4,0};
    int n = 6;

    printf("Array before sorting : \n");
    print(a,n);

    insetion_sort(a,n);

    printf("\nArray after sorting : \n");
    print(a,n);
    return 0;
}