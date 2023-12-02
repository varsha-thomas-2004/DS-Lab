/*
Name : Varsha Thomas
Class : CS3B

To implement circular linked list.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nd
{
	int data;
	struct nd *next;
} node;

//Insert() inserts an element to the front of the list
void Insert(node **head, int data)
{
	node *new = (node *)malloc(sizeof(node));
	node *ptr;
	if (new == NULL)
	{
		printf("Memory insufficient.\n");
	}
	else
	{
		ptr = *head;
		while (ptr -> next != *head)
		{
			ptr = ptr -> next;
		}
		new -> data = data;
		new -> next = *head;
		ptr -> next = new;
		*head = new;
	}
}

//Delete() deletes a node from the front of the list
void Delete(node *head)
{
	node *ptr, *temp;
	ptr = head;
	if (ptr == NULL)
	{
		printf("The list is empty. No deletion.\n");
	}
	else
	{
		while (ptr -> next != head)
		{
			ptr = ptr -> next;
		}
		ptr -> next = head -> next;
		temp = head;
		head = ptr -> next;
		printf("Deleted %d.\n", temp -> data);
		free(temp);
	}
}

//Display() prints the linked list
void Display(node *head)
{	
	node *ptr;	
	if (head == NULL)
	{
		printf("List is empty.\n");
	}
	else
	{
		ptr = head;
		printf("Linked List:\n");
		while (ptr != head)
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
	node *head = (node *)malloc(sizeof(node));
	printf("CIRCULAR LIST.\n");
	printf("Enter first element: ");
	scanf("%d", &data);
	head -> data = data;
	printf("1. Insert\n2. Delete\n3. Display\n");
	while (ch < 4)
	{
		printf("Enter your choice: ");
		scanf("%d", &ch);
		switch (ch)
		{
			case 1:
				printf("Enter the element: ");
				scanf("%d", &data);
				Insert(&head, data);
				break;
			case 2:
				Delete(head);
				break;
			case 3:
				Display(head);
				break;
			default:
				printf("EXITTING...\n");
		}		
	}
}
