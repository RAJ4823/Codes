#include <stdio.h>

void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

int partition(int a[], int low, int high)
{
    int pivot, i, j, temp;
    pivot = a[low];
    i = low + 1;
    j = high;

    while (i < j)
    {
        while (a[i] < pivot)
        {
            i++;
        }
        while (a[j] > pivot)
        {
            j--;
        }

        if (i <= j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    temp = a[low];
    a[low] = a[j];
    a[j] = temp;
    return j;
}

void quick_sort(int a[], int low, int high)
{
    if (low < high)
    {
        int mid = partition(a, low, high);
        quick_sort(a, low, mid - 1);
        quick_sort(a, mid + 1, high);
    }
}

int main()
{
    int a[] = {8, 4, 7, 12, 4, 0};
    int n = 6;

    printf("Array before sorting : \n");
    print(a, n);

    quick_sort(a, 0, n - 1);

    printf("\nArray after sorting : \n");
    print(a, n);
    return 0;
}