#include <stdio.h>
#define size 20

struct stack{
    int top;
    int value[size];
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
int push(char element,int pr)
{
    s.stack[s.top] = element;
    s.top++;

}

//POP
int pop()
{
    s.top--;
    return s.stack[s.top+1];
}

/* TABLE of procedure/priorities
    ( ) = 3
    * / = 2
    + - = 1
*/

int main()
{
    s.top = -1;
    char string[] = "a*b+c";
    char postfix[];

    for(int i=0; string[i] != '\0'; i++)
    {
        if(string[i] == '+' || string[i] == '-')
        push(string[i],1);

        if(string[i] == '*' || string[i] == '/')
        push(string[i],2);

        if(string[i] == '(')
        push(string[i],3);

        if(string[i] == ')')
        pop();

    }
  
    
    return 0;
}