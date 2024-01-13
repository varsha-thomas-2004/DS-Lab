/*
Name : Varsha Thomas
Class : CS3B

To perform insertion sort.
*/

#include <stdio.h>

int i, size, arr[10];

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
    int v, j;
    i = 1;
    while (i < size)
    {
        v = arr[i];
        j = i;
        while (arr[j -1] > v && j > 0)
        {
            arr[j] = arr[j - 1];
            j = j - 1;
        }
        arr[j] = v;
        i = i + 1;
    }
}

void main()
{
    int size;
    printf("INSERTION SORT\n");
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