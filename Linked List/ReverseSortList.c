/*
Name : Varsha Thomas
Class : CS3B

To reverse and sort a linked list.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nd
{
    int data;
    struct nd *next;
} node;

//Reverse() reverses the order of linked list
void Reverse (node *head)
{
    node *ptr, *prev, *next;
    ptr = head;
    prev = next = NULL;
    while (ptr != NULL)
    {
        next = ptr -> next;
        ptr -> next = prev;
        prev = ptr;
        ptr = next;
    }
    head = prev;
}

//Sort() sorts the linked list
void sort

//Main
void main()
{
    int ch = 0;
    node *head = (node*)malloc(sizeof(node));
    printf("LINKED LIST: REVERSE AND SORT");
    printf("1. Reverse\n2. Sort\n3. Display\n");
    while (ch < 4)
    {
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                Reverse(head);
                break;
            case 2:
                Sort(head);
                break;
            case 3:
                Display(head);
                break;
            default:
                printf("EXIT.\n");
        }
    }
}
