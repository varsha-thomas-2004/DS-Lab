/*
Name : Varsha Thomas
Class : CS3B

To check whether the given matrix is sparse symmetric.
*/

#include <stdio.h>

int i, j, k;

typedef struct
{
    int rows;
    int columns;
    int value;
} triplet;

//InputSparse() inputs the sparse representation form
void InputSparse(triplet a[], int n, int r, int c)
{
    printf("Enter sparse representation:\n");
    a[0].rows = r; //first row of the sparse representation
    a[0].columns = c;
    a[0].value = n;
    for (i = 1; i <= n; i++)
    {
        scanf("%d %d %d", &a[i].rows, &a[i].columns, &a[i].value);
    }
}

//DiplayInput() displays the given sparse representation
void DisplayInput(triplet a[], int n)
{
    for (i = 0; i <= n; i++)
    {
        printf("%d\t%d\t%d\n", a[i].rows, a[i].columns, a[i].value);
    }
}

//ArrangeSparse() arranges the column number in ascending order
void ArrangeSparse(triplet a[], triplet t[], int n)
{
    triplet temp[1];
    k = 1;
    t[0].rows = a[0].rows;
    t[0].columns = a[0].columns;
    t[0].value = a[0].value;
    for (i = 1; i <= n; i++)
    {
        for (j = i + 1; j <= n; j++)
        {
            if (a[i].rows > a[j].columns && a[j].columns == a[i].columns || a[i].columns > a[j].columns)
            {
                temp[0] = a[i];
                a[i] = a[j];
                a[j] = temp[0];
            }
        }
        t[k] = a[i];
        k++;
    }
}

//TransSparse() makes transpose
void TransSparse(triplet t[], int n)
{
    triplet temp[1];
    for (i = 0; i <= n; i++)
    {
        temp[0].rows = t[i].rows;
        t[i].rows = t[i].columns;
        t[i].columns = temp[0].rows;
    }
}

//Main function
void main()
{
    triplet a[10], t[10], c[10];
    int nonZero1, r1, c1, flag = 0;
    printf("Enter the number of non zero values: ");
    scanf("%d", &nonZero1);
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &r1, &c1);
    InputSparse(a, nonZero1, r1, c1);
    printf("Inputted sparse representation:\n");
    DisplayInput(a, nonZero1);
    for (i = 0; i <= nonZero1; i++)
    {
        c[i] = a[i];
    }
    ArrangeSparse(a, t, nonZero1);
    printf("Column number arranged in ascending order:\n");
    DisplayInput(t, nonZero1);
    TransSparse(t, nonZero1);
    printf("Transpose of the given sparse representation:\n");
    DisplayInput(t, nonZero1);
    for (i = 0; i <= nonZero1; i++)
    {
        if (t[i].columns != c[i].columns || t[i].rows != c[i].rows || t[i].value != c[i].value)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        printf("Symmetric.");
    else
        printf("Not Symmetric.");
}