/*
Name : Varsha Thomas
Class : CS3B

To implement deque using linked list.
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

//Enqueue() inserts an element to the deque
void Enqueue(int data, int opt)
{
	node *new = (node *)malloc(sizeof(node));
	new -> data = data;
	if (rear == NULL)
	{
		new -> next = NULL;
		rear = new;
		front = new;
		printf("Inserted %d to the deque.\n", rear -> data);
	}
	else
	{
		if (opt == 1)
		{
			rear -> next = new;
			new -> next = NULL;
			rear = new; 
			printf("Inserted %d at rear.\n", rear -> data);
		}
		else if (opt == 2)
		{
			new -> next = front;
			front = new;
			printf("Inserted %d at front.\n", front -> data);
		}
		else
		{
			printf("Invalid Entry.\n");
		}
	}
}

//Dequeue() deletes an element from the deque
void Dequeue(int opt)
{
	node *ptr, *temp;
	if (front == NULL)
	{
		printf("Queue is empty.\n");
	}
	else if (front -> next == NULL)
	{
		ptr = front;
		front = NULL;
		rear = NULL;
		printf("Deleted %d.\n", ptr -> data);\
		free(ptr);
	}
	else
	{
		if (opt == 1)
		{
			ptr = front;
			while (ptr != rear)
			{
				temp = ptr;
				ptr = ptr -> next;
			}
			printf("Deleted %d from the rear.\n", ptr -> data);
			temp -> next = NULL;
			rear = temp;
		}
		else if(opt == 2)
		{
			ptr = front;
			front = front -> next;
			ptr -> next = NULL;
			printf("Deleted %d from the front.\n", ptr -> data);
			free(ptr);	
		}
		else
		{
			printf("Invalid entry.\n");
		}
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
	int ch = 0, data, opt;
	node *front = (node *)malloc(sizeof(node));
	node *rear = (node *)malloc(sizeof(node));
	printf("DEQUE.\n");
	printf("1. Enqueue\n2. Dequeue\n3. Display\n");
	printf("For enqueue and dequeue use option 1 for rear and 2 for front.\n");
	while (ch < 4)
	{
		printf("Enter your choice: ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				printf("Enter the element: ");
				scanf("%d", &data);
				printf("Enter option: ");
				scanf("%d", &opt);
				Enqueue(data, opt);
				break;
			case 2:
				printf("Enter option: ");
				scanf("%d", &opt);
				Dequeue(opt);
				break;
			case 3:
				Display();
				break;
			default:
				printf("EXIT.\n");
		}
	}
}
