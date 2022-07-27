#include <stdio.h>
#include <stdlib.h>

struct stack{
    int value;
    struct stack * next;
};

void display(struct stack * ptr) {
    while(ptr!= NULL) {
        printf("Element : %d\n",ptr->value);
        ptr = ptr->next;
    }
}

struct stack * push(struct stack * s, int data) {
    struct stack * new = (struct stack *) malloc(sizeof(struct stack));
    new->value = data;
    new->next = s;
    s = new;

    return s;
}

int main()
{
    struct stack * s = (struct stack *) malloc(sizeof(struct stack));
    s->value = -1;
    s->next = NULL;
    int size;

    printf("How many elements you want to push ? : ");
    scanf("%d",&size);

    //PUSH OPERATION
    for(int i=0; i<size; ++i) {
        int x;
        printf("Enter element %d  : ",i+1);
        scanf("%d",&x);
        push(s,x);
    }  
    display(s);
    return 0;
}