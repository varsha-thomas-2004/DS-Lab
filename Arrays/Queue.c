/*
Name : Varsha Thomas
Class : CS3B

To implement queue using array.
*/

#include <stdio.h>
#define maxsize 5

int i, front = -1, rear = -1;

void Enqueue(int q[], int item)
{
    if (rear == maxsize - 1)
    {
        printf("Queue is full.\n");
    }
    else
    {
        printf("Enter element: ");
        scanf("%d", &item);
        if (front == -1 && rear == -1)
        {
            front = 0;
            q[++rear] = item;
        }
        else
        {
            q[++rear] = item;
        }
    }
}

void Dequeue(int q[])
{
    if (front == -1)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        int item = q[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
        }
    }
}

void Display(int q[])
{
    for (i = 0; i < maxsize; i++)
    {
        printf("%d\n", q[i]);
    }
}

void main()
{
    int ch, item, q[maxsize];
    printf("QUEUE IMPLEMENTATION\n");
    printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);
    while (1)
    {
        if (ch == 1)
        {
            Enqueue(q, item);
            break;
        }
        else if (ch == 2)
        {
            Dequeue(q);
            break;
        }
        else if (ch == 3)
        {
            Display(q);
            break;
        }
        else if (ch == 4)
        {
            printf("EXITTING FROM THE PROGRAM...\n");
            exit(0);
        }
        else
        {
            printf("INVALID ENTRY!\n");
            break;
        }
    }
}