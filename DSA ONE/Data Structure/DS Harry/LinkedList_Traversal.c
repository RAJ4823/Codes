#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * next;
};
 
void display(struct node * ptr) {
    while(ptr!= NULL) {
        printf("Element : %d\n",ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    struct node * first;
    struct node * second;
    struct node * third;
    struct node * forth;

    first = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    forth = (struct node *)malloc(sizeof(struct node));

    first->data = 10;
    first->next = second;

    second->data = 20;
    second->next = third;
    
    third->data = 30;
    third->next = forth;
    
    forth->data = 40;
    forth->next = NULL;

    display(first);
    return 0;
}