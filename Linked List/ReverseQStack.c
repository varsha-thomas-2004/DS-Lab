/*
Name : Varsha Thomas
Class : CS3B

To reverse a queue using stack.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nd
{
	int data;
	struct nd *next;
} node; 
node *front = NULL;
node *rear = NULL;
node *top = NULL;

//Enqueue() inserts an element in the front
void Enqueue(int data)
{
	node *new = (node *)malloc(sizeof(node));
	new -> data = data;
	if (rear == NULL)
	{
		new -> next = NULL;
		rear = new;
		front = new;
	}
	else
	{
		rear -> next = new;
		new -> next = NULL;
		rear = new;
	}
}

//Push() inserts an element to the front of the linked list
void Push(int data)
{
    while (front != rear)
    {
	    rear -> data = data;
        if (top == NULL) 
		    rear -> next = NULL;
	    rear -> next = top;
	    top = rear;
    } 
}

//Display() prints the linked list
void Display()
{	
	node *ptr;
	if (top == NULL)
	{
		printf("Memory insufficient.\n");
	}
	else
	{
        ptr = top;
		while (ptr != NULL)
		{			
			printf("%d\n", ptr -> data);
			ptr = ptr -> next;
		}
	}	
}

//Main
void main()
{
    int data, ch = 0;
    node *front = (node *)malloc(sizeof(node));
	node *rear = (node *)malloc(sizeof(node));
    Enqueue(1);
    Enqueue(2);
    Enqueue(3);
    Enqueue(4);
    printf("Original Queue:\n");
    Display();
    Push(data);
    printf("Reversed Queue:\n");
    Display();
}