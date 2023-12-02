/*
Name : Varsha Thomas
Class : CS3B

To implement stack using linked list.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nd
{
	int data;
	struct nd *next;
} node;
node *top = NULL;

//Push() inserts an element to the front of the linked list
void Push(int data)
{
	node *new = (node *)malloc(sizeof(node));
	new -> data = data;
	if (top == NULL) 
		new -> next = NULL;
	new -> next = top;
	top = new; 
}
//Pop() pops out an element from the front
void Pop()
{
	node *ptr;
	if (top == NULL)
	{
		printf("Stack empty.\n");
	}
	else if (top -> next == NULL)
	{
		ptr = top;
		top = NULL;
		printf("Popped %d\n", ptr -> data);
		free(ptr);
	}
	else
	{
		ptr = top;
		top = top -> next;
		printf("Popped %d\n", ptr -> data);
		free(ptr);
	}
}

//Peek() shows the top
void Peek()
{
	if (top == NULL)
		printf("Stack empty.\n");
	else
		printf("Top: %d\n", top -> data);
}

//Display() prints the linked list
void Display()
{	
	node *ptr;	
	printf("Linked List:\n");
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
	int ch = 0, data;	
	printf("STACK USING LINKED LIST.\n");
	printf("1. Push\n2. Pop\n3. Peek\n4. Display\n");
	while (ch < 5)
	{
		printf("Enter your choice: ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				printf("Enter the element: ");
				scanf("%d", &data);
				Push(data);
				break;
			case 2:
				Pop();
				break;
			case 3:
				Peek();
				break;
			case 4:
				Display();
				break;
			default:
				printf("EXIT.\n");
		}
	}
}
