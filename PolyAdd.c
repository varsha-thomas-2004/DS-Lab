/*
Name : Varsha Thomas
Class : CS3B

To implement polynomial addition using linked list.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nd
{
	int coeff, exp;
	struct nd *next;
} node;
node *ptr1, *ptr2, *ptr3;

//Main
void main()
{
	int ch = 0;
	printf("POLYNOMIAL ADDITION USING LINKED LIST\n");
	printf("1. Insert polynomials\n2. Add\n3. Display\n");
	while (ch < 4)
	{
		printf("Enter your choice: ");
		scanf("%d", &ch);
		switch (ch)
		{
			case 1:
				Read();
				break;
			case 2:
				Add();
				break;
			case 3:
				Display();
				break;
			default:
				printf("EXIT.\n");
		}
	}
}
