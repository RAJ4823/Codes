#include <stdio.h>

void print(int a[], int n){
    for(int i=0; i<n; i++) {
        printf("%d ",a[i]);
    }
}

void selection_sort(int a[], int n){
    int min=0, temp;

    for(int i=0 ;i<=n-2; i++) {
        min = i;
        for(int j=i+1; j<=n-1; j++) {
            if(a[j] < a[min]) {
                min = j;
            }
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

int main()
{
    int a[] = {8,4,7,12,4,0};
    int n = 6;

    printf("Array before sorting : \n");
    print(a,n);

    selection_sort(a,n);

    printf("\nArray after sorting : \n");
    print(a,n);
    return 0;
}