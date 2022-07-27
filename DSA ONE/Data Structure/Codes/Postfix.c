#include <stdio.h>
#define size 20

struct stack
{
    int top;
    char stack[size];
} s;

int infix_to_postfix(char infix[])
{

    char c;
    char postfix[size];
    s.top++;
    s.stack[s.top] = '$';

    int j = 0;
    for (int i = 0; infix[i] != '\0'; i++)
    {
        c = infix[i];
        int instack = pr(s.stack[s.top]) ;
        int incoming = pr(c);
        if (instack > incoming)
        {
            postfix[j] = pop();
            j++;
        }
        else
        {
            push(c);
        }
    }
    while (pop()!= '$')
    {
        postfix[j] = pop();
        j++;
    }
    postfix[j] = '\0';
    printf("Postfix Expression : %s", postfix);
    return 0;
}

int pr(char p)
{
    int value;
    switch (p)
    {
    case '+':
        value = 2;
        break;

    case '-':
        value = 2;
        break;
    case '*':
        value = 4;
        break;
    case '/':
        value = 4;
        break;
    case '^':
        value = 5;
        break;
    case '(':
        if (s.stack[s.top] == p)
            value = 0;
        else
            value = 9;
        break;

    case ')':
        if (s.stack[s.top] == p)
            value = 9;
        else
            value = 0;
        break;

    default:
        value = 8;
        break;
    }
    return value;
}

void push(char element)
{
    s.top++;
    s.stack[s.top] = element;
}

char pop()
{
    char poped = s.stack[s.top];
    s.top--;
    return poped;
}

int main()
{
    s.top = -1;
    char infix[] = "A^B*C-D+E/F/(G+H)";
    infix_to_postfix(infix);
    return 0;
}