#include <stdio.h>

void display(int arr[], int size){
    for(int i=0; i< size; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int insertion(int arr[], int size, int capacity, int element, int index)
{
    if(size>=capacity){
        return -1;
    }
    for(int i=size-1; i>=index; i--)
    {
        arr[i+1] = arr[i];
    }
    arr[index] = element;
    
    return 1;
}
int main()
{
    int size,capacity,element,index;
    printf("Enter the capacity of array : ");
    scanf("%d",&capacity);
    printf("Enter the size of array : ");
    scanf("%d",&size);
    int arr[capacity];


    printf("Enter the elemets of the array ->\n");

    for(int i=0; i<size; i++) {
        scanf("%d",&arr[i]);
    }

    printf("Enter the element which you want to insert : ");
    scanf("%d",&element);
    printf("Enter the index where you want to insert the element : ");
    scanf("%d",&index);
    insertion(arr, size, capacity, element, index);

    size += 1;
    display(arr,size);

    return 0;
}