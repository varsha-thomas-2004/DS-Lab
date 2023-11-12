/*
Name : Varsha Thomas
Class : CS3B

To evaluate a postfix expression.
*/

#include <stdio.h>
#include <ctype.h>
#define size 20

char post[size];
int stack[size];
int top = -1;

int pop()
{
    return stack[top--];
}

void push(int item)
{
    stack[++top] = item;
}

void operate(int x, int y, char ch)
{
    int result;
    switch (ch)
    {
        case '+':
            result = x + y;
            break;
        case '-':
            result = x - y;
            break;
        case '*':
            result = x * y;
            break;
        case '/':
            if (y != 0)
                result = x / y;
            else
            {
                printf("Error: Division by zero\n");
                return;
            }
            break;
    }
    push(result);
}

int main()
{
    int i, x, y, res;
    char item;
    
    printf("POSTFIX EVALUATION\n");
    printf("Enter the postfix expression in a single line:\n");
    scanf("%s", &post[i]);
    for (i = 0; post[i] != '\0'; i++)
    {
        if (isdigit(post[i]))
        {
            item = post[i] - '0'; // Convert character to integer
            push(item);
        }
        else
        {
            y = pop();
            x = pop();
            operate(x, y, post[i]);
        }
    }
    
    res = pop();
    printf("The result of the postfix expression is %d.\n", res);
    
    return 0;
}
