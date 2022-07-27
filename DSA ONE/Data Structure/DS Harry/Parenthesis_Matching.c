#include <stdio.h>
#define size 20

struct stack{
    int top;
    char stack[size];
} s;

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
int push(char element)
{
    s.top++;
    s.stack[s.top] = element;
}

//POP
int pop()
{
    s.top--;
    return s.stack[s.top+1];
}

int isMatch(char old, char new) {
    if((old == '(' && new == ')') || (old == '{' && new == '}') || (old == '[' && new == ']'))
    return 1;
    else
    return 0;
}

int main()
{
    s.top = -1;
    char c[] = "[2+3{3*9(3+6)}]";

    for(int i=0; c[i]!='\0'; i++) {
        if(c[i] == '(' || c[i] == '{' || c[i] == '[') {
            push(c[i]);
        }
        if(c[i] == ')' || c[i] == '}' || c[i] == ']') {
            char poped = pop();
            if(!isMatch(poped,c[i])) {
                s.top == -1;
                break;
            }
        }
    }

    if(s.top == -1) {
        printf("\nBALANCED");
    } else {
        printf("\nNOT BALANCED");
    }
    
    
    return 0;
}