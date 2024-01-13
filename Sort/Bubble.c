/*
Name : Varsha Thomas
Class : CS3B

To perform Bubble sort.
*/

#include <stdio.h>

int i;

void Insert(int size, int arr[size])
{
    printf("Enter elements:\n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    } 
}

void Display(int size, int arr[size])
{
    for (i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void Sort(int size, int arr[size])
{
    int temp, j;
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void main()
{
    int size;
    printf("BUBBLE SORT\n");
    printf("Enter size: ");
    scanf("%d", &size);
    int arr[size];
    Insert(size, arr);
    printf("Given array: ");
    Display(size, arr);
    Sort(size, arr);
    printf("Sorted array: ");
    Display(size, arr);
}