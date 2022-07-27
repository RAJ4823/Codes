#include <stdio.h>
#include <stdlib.h>

struct stack {
    int size;
    int top;
    int *arr;
};

int isFull(struct stack * s) {
    if(s->top == s->size)
    return 1;
    else
    return 0;
}
int isEmpty(struct stack * s) {
    if(s->top == -1)
    return 1;
    else
    return 0;
}

int push(struct stack * s, int value) {
    if(isFull(s)) {
        printf("Stack Overflow !\nCannot push the %d\n",value);
    }
    else {
        s->top++;
        s->arr[s->top] = value;
    }
}
int pop(struct stack * s) {
    if(isEmpty(s)) {
        printf("Stack Underflow !\n");
    }
    else {
        int popped = s->arr[s->top];
        s->top--;
        return popped;
    }
}
int peak(struct stack *s, int i) {

    if(s->top + 1 < i && i < 1) {
        printf("Position is not possible\n");
        return 0;
    }
    else {
        return (s->arr[s->top + 1 - i]);
    }
}

void display(struct stack *s) {
    printf("\nVisual representation of stack is : \n");
    for(int i=0; i<=s->top; ++i) {
        printf("\n| %5.d |",s->arr[s->top - i]);
    }
    printf("\n|_______|\n");
}

int main()
{
    struct stack * s = (struct stack *) malloc(sizeof(struct stack));
    s->size = 0;
    s->top = -1;
    s->arr = (int *) malloc(s->size * sizeof(int));
    printf("Stack created successfully\n");

    printf("How many elements you want to push ? : ");
    scanf("%d",&(s->size));

    //PUSH OPERATION
    for(int i=0; i<s->size; ++i) {
        int x;
        printf("Enter element %d  : ",i+1);
        scanf("%d",&x);
        push(s,x);
    }  
    
    // POP OPERATION
    // int pop_num;
    // printf("How many elements you want to pop ? : ");
    // scanf("%d",&pop_num);

    // while(pop_num--) {
    //     printf("Element %d popped\n", pop(s));
    // }

    // PEAK OPERATION
    // int i;
    // printf("Which position you want to peak ? : ");
    // scanf("%d",&i);
    // printf("Element : %d\n",peak(s,i));

    display(s);
    
    return 0;
}