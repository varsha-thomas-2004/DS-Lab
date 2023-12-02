/*
Name : Varsha Thomas
Class : CS3B

To keep the stack sorted at every push
*/

#include <stdio.h>
#define size 5

int top_sorted = -1, top_sorthelp = -1;
int sorted[size], sorthelp[size];

int pop(int sorted[])
{
    int popped;
    if (top_sorted == -1)
    {
        printf("Stack empty.\n");
    }
    else
    {
        popped = sorted[top_sorted--];
    }
    return popped;
}

void push(int sorted[], int item)
{
    if (top_sorted == size - 1)
    {
        printf("Stack is full. Cannot insert element %d\n", item);
    }
    else if (top_sorted == -1)
    {
        sorted[++top_sorted] = item;
    }
    else
    {
        while (top_sorted != -1 && item > sorted[top_sorted])
        {
            sorthelp[++top_sorthelp] = sorted[top_sorted--];
        }
        sorted[++top_sorted] = item;
        while (top_sorthelp != -1)
        {
            sorted[++top_sorted] = sorthelp[top_sorthelp--];
        }
    }
}

void display(int sorted[], int sorthelp[])
{
    int i;
    if (top_sorted == -1)
    {
        printf("Original stack is empty.\n");
    }
    else
    {
        printf("Current original stack:\n");
        for (i = top_sorted; i >= 0; i--)
        {
            printf("%d\n", sorted[i]);
        }
    }
}

void main()
{
    int ch = 0, item, popped;
    printf("SORTED PUSH\n");
    printf("1. Push\n2. Pop\n3. Display\nPress any number to exit.\n");
    while (ch < 4)
    {
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d", &item);
                push(sorted, item);
                break;
            case 2:
                popped = pop(sorted);
                printf("%d is popped out from the stack.\n", popped);
                break;
            case 3:
                display(sorted, sorthelp);
                break;
            default:
                printf("EXITTING FROM THE PROGRAM...\n");
        }
    }
}