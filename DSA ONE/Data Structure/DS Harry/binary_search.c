#include <stdio.h>

int binary_search(int arr[], int size, int element) {
    int low, mid, high;
    low = 0;
    high = size-1;

    while(low <= high) {
        mid = (low+high)/2;
        
        if(arr[mid] == element) { 
            return mid;
        } 
        
        if(arr[mid] < element) {
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }
    return -1;
}

int main()
{
    int element, size;
    printf("Enter the size of (sorted) array : ");
    scanf("%d",&size);
    int arr[size];

    printf("Enter the elements of the array ->\n");
    for(int i=0; i<size; ++i) {
        scanf("%d",&arr[i]);
    }
    printf("Enter the element which you want to search : ");
    scanf("%d",&element);

    int ans = binary_search(arr, size, element);
    printf("Index of element is : %d", ans);
    return 0;
}