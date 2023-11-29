/*
Name : Varsha Thomas
Class : CS3B

To implement different operations on linked list.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nd
{
	int data; //node value
	struct nd *next; //node pointer
} node;

//Insert_Begin() inserts elements in the front
void Insert_Begin(node **head, int data)
{
    node *new = (node *)malloc(sizeof(node));
    if (new == NULL)
    {
        printf("Memory insufficient.\n");
    }
    new -> data = data;
    new -> next = *head;
    *head = new;
}

//Insert_End() inserts elements in the end
void Insert_End(node *head, int data)
{
	node *new = (node *)malloc(sizeof(node)); //new node memory allocation
	node *ptr; //current pointer
	if (new == NULL) //no value for new node
	{
		printf("Memory insufficient.\n");
	}
	else
	{
		ptr = head; //initial point
		while (ptr -> next != NULL)
		{
			ptr = ptr -> next; //incrementing...
		}
		new -> data = data; //assigning value
		ptr -> next = new; //pointing to new node
	}
}

//Insert_After() inserts an element after the given element
void Insert_After(node *head, int before, int data)
{
	node *new = (node *)malloc(sizeof(node));
	node *ptr;
	if (new == NULL)
	{
		printf("Memory insufficient.\n");
	}
	else
	{
		ptr = head;
		//before = element already present in the list which needs to be present before the given element
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
		new -> next = ptr -> next; //deleting the connection between 'ptr' and 'before'
		ptr -> next = new; //connecting 'ptr' to 'new'
	}
}

//Insert_Before() inserts an element before the given element
void Insert_Before(node *head, int after, int data)
{
	node *new = (node *)malloc(sizeof(node));
	node *ptr, *prev; //prev = previous node
	if (new == NULL)
	{
		printf("Memory insufficient.\n");
	}
	if (head -> data == after)
	{
	   Insert_Begin(&head, data);
    }
	else
	{
		ptr = head;
		//after = element already present in the list which needs to be present after the given element
		while (ptr -> data != after && ptr -> next != NULL)
	    {			
	        prev = ptr; //assigning value of current node to the previous node before ptr getting incremented
		    ptr = ptr -> next;
	    }
		if (ptr -> next == NULL)
		{
		    printf("Item not available.\n");
		    return;
	    }
	    new -> next = ptr; //connecting new node to current node
	    new -> data = data;
	    prev -> next = new; //connecting previous node to new node
	}
}

//Insert_Pos() inserts an element in the given position
void Insert_Pos(node *head, int pos, int data)
{
	int count = 1; //to get the position number via traversal
	node *new = (node *)malloc(sizeof(node));
    node *ptr, *prev;
    if (new == NULL)
	{
		printf("Memory insufficient.\n");
	}
	else 
	{
	    ptr = head;
	    while (count != pos)
		{
			prev = ptr;
			ptr = ptr -> next;
			count++;
		}
		//when count == pos,
		new -> data = data;
		new -> next = ptr;
		prev -> next = new;
	}
}

//Delete_Key() deletes a node with given key value
void Delete_Key(node *head, int item)
{
    node *ptr, *temp; //temp = temporary pointer
    ptr = head;
    while (ptr != NULL)
    {
        if (ptr -> data != item) //as long as the element is not found,
        {
            temp = ptr;
            ptr = ptr -> next;
        }
        else //element is found
        {
            temp -> next = ptr -> next;
            free(ptr);
            break;
        }
    }
    if (ptr == NULL)
        printf("Node with the item does not exist.\n");
}

//Delete_Pos() deletes a node given the position
void Delete_Pos(node *head, int pos)
{
    node *ptr, *temp;
    int count = 1;
    ptr = head;
    while (ptr != NULL)
    {
        if (count != pos)
        {
            temp = ptr;
            ptr = ptr -> next;
            count++;
        }
        else
        {
            temp -> next = ptr -> next;
            free(ptr);
            break;
        }
    }
}

//Minimum() finds the minimum element
void Minimum(node *head)
{
    node *ptr, *prev;
    int min; //minimum element 
    prev = head;
    ptr = prev -> next; //ptr = head + 1
    min = prev -> data; //let min be the previous node
    while (ptr -> next != NULL)
    {
        if (ptr -> data < prev -> data)
        {
            min = ptr -> data; //assign ptr as min, if it is smaller than previous node which was already assigned as min.
        }
        prev = ptr;
        ptr = ptr -> next;
    }
    printf("The minimum element in the linked list is %d\n", min);
}

//Search() searches for an element in the linked list
void Search(node *head, int item)
{
    node *ptr;
    int flag = 0, pos = 1;
    ptr = head;
    while (ptr -> next != NULL)
    {
        if (ptr -> data == item)
        {
            printf("The element is found at position %d\n", pos);
            flag = 1; //Element found, flag is raised
            break;
        }
        ptr = ptr -> next;
        pos++;
    }
    if (flag == 0)
        printf("The element does not exist.\n");
}

//Display() prints the linked list
void Display(node *head)
{	
	node *ptr;	
	printf("Linked List:\n");
	if (head == NULL)
	{
		printf("List is empty.\n");
	}
	else
	{
		ptr = head;
		while (ptr -> next != NULL)
		{			
			printf("%d\n", ptr -> data);
			ptr = ptr -> next;
		}
		printf("%d\n", ptr -> data); //last element
	}	
}

//Main function
void main()
{
	int data, ch = 0, item, pos;
	node *head = (node *)malloc(sizeof(node));
	printf("LINKED LIST\n");
	printf("Enter first element: ");
	scanf("%d", &data);
	head -> data = data;
	printf("1. Insertion at beginning\n2. Insertion at end\n3. Insert an element after a node\n4. Insert an element before anode\n5. Insert a node at a given position\n6. Delete a node with the key data value\n7. Delete a node with the given position\n8. Find minimum element\n9. Search an element\n10. Display\n");
	while (ch < 11)
	{
		printf("Enter your choice: ");
		scanf("%d", &ch);
		switch (ch)
		{
			case 1: 
			    printf("Enter the element: ");
				scanf("%d", &data);
				Insert_Begin(&head, data);
				break;
			case 2:
				printf("Enter the element: ");
				scanf("%d", &data);
				Insert_End(head, data);
				break;
			case 3: 
				printf("Enter the BEFORE element present already in the list: ");
				scanf("%d", &item);
				printf("Enter the element to be inserted: ");
				scanf("%d", &data);
				Insert_After(head, item, data);
				break;	
			case 4:
				printf("Enter the AFTER element present already in the list: ");
				scanf("%d", &item);
				printf("Enter the element to be inserted: ");
				scanf("%d", &data);
		        Insert_Before(head, item, data);
				break;
			case 5:
			    printf("Enter the position: ");
			    scanf("%d",&pos);
				printf("Enter the element: ");
				scanf("%d", &data);
				Insert_Pos(head, pos, data);
				break;
			case 6:
			    printf("Enter the value to be deleted: ");
			    scanf("%d", &item);
			    Delete_Key(head, item);
			    break;
			case 7:
			    printf("Enter the position: ");
			    scanf("%d", &pos);
			    Delete_Pos(head, pos);
			    break;
			case 8:
			    Minimum(head);
			    break;
			case 9:
			    printf("Enter the element to be searched: ");
			    scanf("%d", &item);
			    Search(head, item);
			    break;
			case 10:
				Display(head);
				break;
			default:
				printf("EXIT.\n");
		}
	}
}
