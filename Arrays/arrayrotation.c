/*
Name : Varsha Thomas
Class : CS3B

To perform array rotations.
Logic: New rotated array is stored in a temporary array
    Left rotation (no. of rotations):
        Elements from indices [no. of rotations] to [size - 1] stored in temporary array.
        Elements from indices [0] to [no. of rotations] stored in temporary array.
    Right rotation follows the same logic with slight changes.
*/

#include <stdio.h>

/*
i, j = looping variable
size = size of array
left = no. of rotations to the left
right = no. of rotations to the right
arr[] = original array
*/
int i, j, size, left, right, arr[10]; 

//ArrayScan() scans in the elements
void ArrayScan()
{
    printf("Enter the size of the array: ");
    scanf("%d",&size);
    printf("Enter elements:\n");
    for (i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }
}

//LeftArrayRot() rotates array to the left
void LeftArrayRot()
{
    printf("Enter the number of times to be rotated: ");
    scanf("%d",&left);
    int temp[size]; //temporary array
    j = 0;
    for (i = left; i < size; i++)
    {
        temp[j] = arr[i];
        j++;
    }
    for (i = 0; i < left; i++)
    {
        temp[j] = arr[i];
        j++;
    }

    //printing rotated array
    printf("\nLeft Rotated array:\n");
    for (i = 0; i < size; i++)
    {
        printf("%d\n",temp[i]);
    }
}

//RightArrayRot() rotates array to the right
void RightArrayRot()
{
    printf("Enter the number of times to be rotated: ");
    scanf("%d",&right);
    int temp[size]; //temporary array
    j = 0;
    for (i = right + 1; i < size; i++) //draw the array and you'll know :)
    {
        temp[j] = arr[i];
        j++;
    }
    for (i = 0; i < right + 1; i++)
    {
        temp[j] = arr[i];
        j++;
    }

    //printing rotated array
    printf("\nRight Rotated array:\n");
    for (i = 0; i < size; i++)
    {
        printf("%d\n",temp[i]);
    }
}

//Main function
void main()
{
    int ch;
    printf("ARRAY ROTATIONS\n");
    ArrayScan();
    printf("1. Left rotation\n2. Right rotation\nEnter your choice: ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            LeftArrayRot();
            break;
        case 2:
            RightArrayRot();
            break;
        default:
            printf("INVALID ENTRY.");
            break;
    }
}