#include <stdio.h>
#define size 5
struct stack
{
    int stack[size];
    int top;
} s;

//isFull
int isFull()
{
    if (s.top >= size-1)
        return 1;
    else
        return 0;
}

//isEmpty
int isEmpty()
{
    if (s.top == -1)
        return 1;
    else
        return 0;
}

//PUSH
int push(int element)
{
    s.top++;
    s.stack[s.top] = element;
}

//POP
int pop()
{
    s.top--;
}

//Display
int display()
{
    for (int i = 0; i <= s.top; i++)
    {
        printf("\n%d -> %d", i, s.stack[i]);
    }
}

int main()
{
    s.top = -1;
    int item;
    int choise;
    printf("Main Manu\n1. PUSH\n2. POP\n3. DISPLAY\n0. EXIT");

start:
    printf("\n-> ");
    scanf("%d", &choise);
    switch (choise)
    {
    case 0:
        goto end;
        break;
    case 1:
        scanf("%d", &item);

        if (isFull())
            printf("Stack is full\n");
        else
            push(item);
        break;

    case 2:
        if (isEmpty())
            printf("Stack is empty\n");
        else
            pop();
        break;
    case 3:
        display();
        break;

    default:
        break;
    }
    goto start;
end:
    return 0;
}