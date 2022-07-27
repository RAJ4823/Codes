#include <stdio.h>
#define size 50

struct stack
{
    char stack[size];
    int top;
} s;

// PUSH
int push(char element)
{
    s.top++;
    s.stack[s.top] = element;
}

// POP
char pop()
{
    char temp = s.stack[s.top];
    s.top--;
    return temp;
}

int operator(char i)
{
    if (i == '+' || i == '-' || i == '/' || i == '*')
        return 1;
    else
        return 0;
}

int priority(char i)
{
    switch (i)
    {
    case '+':
        return 2;
        break;
    case '-':
        return 2;
        break;
    case '*':
        return 4;
        break;
    case '/':
        return 4;
        break;
    default:
        return 0;
        break;
    }
}

int main()
{
    s.top = -1;
    int i = 0, j = 0;
    char infix[size];
    char postfix[size];

    printf("Enter infix : ");
    scanf("%s", infix);
    printf("Infix : ");
    printf("%s", infix);

    while (infix[i] != '\0')
    {
        char ch = infix[i];

        if (!operator(ch))
        {
            postfix[j] = ch;
            j++;
            i++;
        }
        else
        {
            if (priority(s.stack[s.top]) < priority(ch))
            {
                push(ch);
                i++;
            }
            else
            {
                postfix[j] = pop();
                j++;
            }
        }
    }
    while (s.top != -1)
    {
        postfix[j] = pop();
        j++;
    }
    postfix[j]='\0';

    printf("\nPostfix : ");
    printf("%s", postfix);
    return 0;
}