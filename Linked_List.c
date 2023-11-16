/*
Name : Varsha Thomas
Class : CS3B

To implement Linked list operations.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nd
{
	int data;
	struct nd *next;
} node;

//Insert_End() inserts elements in the end
void Insert_End(node *head, int data)
{
	node *new = (node*)malloc(sizeof(node));
	node *ptr;
	if (new == NULL)
	{
		printf("Memory insufficient.\n");
	}
	else
	{
		ptr = head;
		while (ptr -> next != NULL)
		{
			ptr = ptr -> next;
		}
		new -> data = data;
		ptr -> next = new;
	}
}

//Insert_After() inserts an element after the given element
void Insert_After(node *head, int before, int data)
{
	node *new = (node*)malloc(sizeof(node));
	node *ptr;
	if (new == NULL)
	{
		printf("Memory insufficient.\n");
	}
	else
	{
		ptr = head;
		while (ptr -> data != before && ptr -> next != NULL)
		{
			ptr = ptr -> next;
		}
		if (ptr -> next == NULL)
		{
			printf("Item not available.\n");
			return;
		}
		new -> data = data;
		new -> next = ptr -> next;
		ptr -> next = new;
	}
}

//Insert_Before() inserts an element before the given element
void Insert_Before(node *head, int after, int data)
{
	node *new = (node*)malloc(sizeof(node));
	node *ptr, *prev;
	if (new == NULL)
	{
		printf("Memory insufficient.\n");
	}
	else
	{
		ptr = head;
		while (ptr -> data != after && ptr -> next != NULL)
		{			
			ptr = ptr -> next;
		}
		if (ptr -> next == NULL)
		{
			printf("Item not available.\n");
			return;
		}
		prev -> next = ptr;
		new -> data = data;
		new -> next = ptr;
		prev -> next = new;
	}
}
//Display() prints the linked list
void Display(node *head)
{	
	node *ptr;	
	printf("Linked List:\n");
	if (head == NULL)
	{
		printf("Memory insufficient.\n");
	}
	else
	{
		ptr = head;
		while (ptr -> next != NULL)
		{			
			printf("%d\n", ptr -> data);
			ptr = ptr -> next;
		}
		printf("%d\n", ptr -> data);
	}	
}

//Main function
void main()
{
	int data, ch = 0, item;
	node *head = (node*)malloc(sizeof(node));
	printf("LINKED LIST\n");
	printf("Enter first element: ");
	scanf("%d", &data);
	head -> data = data;
	printf("1. Insertion at end\n2. Insert an element after a node\n3. Insert an element before anode\n5. Display\n");
	while (ch < 6)
	{
		printf("Enter your choice: ");
		scanf("%d", &ch);
		switch (ch)
		{
			case 1: 
				printf("Enter the element: ");
				scanf("%d", &data);
				Insert_End(head, data);
				break;
			case 2: 
				printf("Enter the BEFORE element present already in the list: ");
				scanf("%d", &item);
				printf("Enter the element to be inserted: ");
				scanf("%d", &data);
				Insert_After(head, item, data);
				break;	
			case 3:
				printf("Enter the AFTER element present already in the list: ");
				scanf("%d", &item);
				printf("Enter the element to be inserted: ");
				scanf("%d", &data);
				Insert_Before(head, item, data);
				break;	
			case 5:
				Display(head);
				break;
			default:
				printf("EXIT.\n");
		}
	}
}


