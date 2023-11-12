/*
Name : Varsha Thomas
Class : CS3B

To convert an infix expression to postfix using stack.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

char stack[MAX], infix[MAX], postfix[MAX];
int top = -1;

void push(char c)
{
    if (top == MAX - 1)
    {
        printf("Stack overflow.");
    }
    else
    {
        c = stack[++top];
    }
}

char pop()
{
    char c;
    if (top == -1)
    {
        printf("Stack underflow.");
    }
    else
    {
        c = stack[top--];
    }
    return c;
}

void isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

void intoPost()
{
    int i, j;
    char symbol, next;
    i = j = 0;
    for (i = 0; i < strlen(infix); i++)
    {
        symbol = infix[i];
        if (symbol == '(')
        {
            push(symbol);
            break;
        }
        else if (symbol == ')')
        {
            while (symbol != '(')
            {
                pop();
            }
            break;
        }
        else if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^')
        {
            if ()
            {}
        }
    }
}

