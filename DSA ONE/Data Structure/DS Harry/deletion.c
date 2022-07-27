#include <stdio.h>

void display(int arr[], int size){
    for(int i=0; i< size; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int deletion(int arr[], int size, int capacity, int element)
{
    int index = -1;
    for(int i=0; i< size; i++) {
        if(arr[i]==element)
        index = i;
    }

    if(index == -1)
    return -1;

    for(int i=index; i<size; i++)
    {
        arr[i] = arr[i+1];
    }
    
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

    printf("Enter the element which you want to delete : ");
    scanf("%d",&element);
    deletion(arr, size, capacity, element);

    size -= 1;
    display(arr,size);

    return 0;
}