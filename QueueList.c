/*
Name : Varsha Thomas
Class : CS3B

To implement queue using linked list
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

//Dequeue() deletes an element from the rear
void Dequeue()
{
	node *ptr;
	if (front == NULL)
	{
		printf("Stack empty.\n");
	}
	else if (front -> next == NULL)
	{
		ptr = front;
		front = NULL;
		rear = NULL;
		printf("Deleted %d.\n", ptr -> data);
		free(ptr);
	}
	else
	{
		ptr = front;
		front = front -> next;
		ptr -> next = NULL;
		printf("Deleted %d.\n", ptr -> data);
		free(ptr);
	}
}

//Display() prints the linked list
void Display()
{	
	node *ptr;	
	printf("Linked List:\n");
	if (front == NULL)
	{
		printf("Memory insufficient.\n");
	}
	else
	{
		ptr = front;
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
	int ch = 0, data;
	node *front = (node *)malloc(sizeof(node));
	node *rear = (node *)malloc(sizeof(node));
	printf("QUEUE USING LINKED LIST.\n");
	printf("1. Enqueue\n2. Dequeue\n3. Display\n");
	while (ch < 4)
	{
		printf("Enter your choice: ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				printf("Enter the element: ");
				scanf("%d", &data);
				Enqueue(data);
				break;
			case 2:
				Dequeue();
				break;
			case 3:
				Display();
				break;
			default:
				printf("EXIT.\n");
		}
	}
}
