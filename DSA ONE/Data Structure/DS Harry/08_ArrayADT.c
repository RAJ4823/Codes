#include <stdio.h>
#include <stdlib.h>

struct myArray {
    int total_size;
    int used_size;
    int *ptr;
};
 
void create(struct myArray * a) {
    printf("Enter total size of Array : ");
    scanf("%d",&(a->total_size));
    printf("Enter the size will be used in Array : ");
    scanf("%d",&(a->used_size));
}
void insert(struct myArray * a) {
    int n;
    for(int i=0; i<a->used_size; ++i) {
        printf("Enter element - %d : ",i);
        scanf("%d",&n);

        (a->ptr)[i] = n;
    }
}
void show(struct myArray * a) {
    printf("\nArray is : ");
    for(int i=0; i<a->used_size; ++i) {
        printf("%d ",(a->ptr)[i]);
    }
}
int main() {
    struct myArray a;
    create(&a);
    insert(&a);
    show(&a);
    return 0;
}