/*
Name: Varsha Thomas
Class: CS3B

Program to perform array operations:
insertion, deletion searching, sorting
*/

#include <stdio.h>
/*
i, j = looping variables
num = number to be inserted
pos = position at which the given number is to be inserted
arr = array
*/
int i, j, size, num, pos, arr[20], temp;

//insertion() inserts new elements to the required position.
int insertion()
{
    printf("Enter the number to be inserted: ");
    scanf("%d",&num);
    printf("Enter the position to be inserted: ");
    scanf("%d",&pos);
    arr[pos] = num;
    for(i = pos - 1; i < size; i++)
    {
        temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp;
    }
    for(i = 0; i < size + 1; i++)
    {
        printf("%d\n",arr[i]);
    }
}

void main()
{
    printf("PROGRAM TO PERFORM ARRAY OPERATIONS.\n");
    printf("Enter size of the array: ");
    scanf("%d",&size);
    printf("Enter the elements of the array:\n");
    for(i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }
    insertion();
}

