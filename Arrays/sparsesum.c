/*
Name : Varsha Thomas
Class : CS3B

Input sparse representation of two sparse matrices and find their sum.
*/

#include <stdio.h>

int i, j, k;
typedef struct
{
    int rows;
    int columns;
    int value;
} triplet;

//InputSparse() inputs elements in sparse representation form
void InputSparse(triplet a[], int n, int r, int c)
{
    a[0].rows = r;
    a[0].columns = c;
    a[0].value = n;
    printf("Enter sparse representation:\n");
    for (i = 1; i <= n; i++)
    {
        scanf("%d %d %d",&a[i].rows, &a[i].columns, &a[i].value);
    }
}

//DisplayInput() displays the inputted data
void DisplayInput(triplet a[], int n)
{
    for (i = 0; i <= n; i++)
    {
        printf("%d\t%d\t%d\n", a[i].rows, a[i].columns, a[i].value);
    }
}

//SparseSum() obtains sum of the sparse representation
int SparseSum(triplet a[], triplet b[], triplet c[], int n1, int n2)
{
    i = j = k = 1;
    if (a[0].rows == b[0].rows && a[0].columns == a[0].columns)
    {
        c[0].rows = a[0].rows;
        c[0].columns = a[0].columns;
    }
    while (i <= n1 && j <= n2)
    {
        if (a[i].rows == b[j].rows && a[i].columns == b[j].columns)
        {
            c[k].rows = a[i].rows;
            c[k].columns = a[i].columns;
            c[k].value = a[i].value + b[j].value;
            i++, j++;
        }
        else if (a[i].rows == b[j].rows && a[i].columns > b[j].columns || a[i].rows > b[j].rows)
        {
            c[k].rows = b[j].rows;
            c[k].columns = b[j].columns;
            c[k].value = b[j].value;
            j++;
        } 
        else if (a[i].rows == b[j].rows && a[i].columns < b[j].columns || a[i].rows < b[j].rows)
        {
            c[k].rows = a[i].rows;
            c[k].columns = a[i].columns;
            c[k].value = a[i].value;
            i++;
        }
        k++;
    }
    while (i <= n1)
    {
        c[k].rows = a[i].rows;
        c[k].columns = a[i].columns;
        c[k].value = a[i].value;
        i++, k++;
    }
    while (j <= n2)
    {
        c[k].rows = b[j].rows;
        c[k].columns = b[j].columns;
        c[k].value = b[j].value;
        j++, k++;
    }
    return k;
}

//Main function
void main()
{
    int n1, n2, r1, c1, r2, c2;
    triplet a[10], b[10], c[20];
    printf("SPARSE SUM");
    printf("\nMatrix 1:\n");
    printf("Enter the number of non zero values: ");
    scanf("%d",&n1);
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &r1, &c1);
    printf("\nMatrix 2:\n");
    printf("Enter the number of non zero values: ");
    scanf("%d",&n2);
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &r2, &c2);
    printf("MATRIX 1:\n");
    InputSparse(a, n1, r1, c1);
    printf("MATRIX 2:\n");
    InputSparse(b, n2, r2, c2);
    printf("Matrix 1 inputted sparse representation:\n");
    DisplayInput(a, n1);
    printf("Matrix 2 inputted sparse representation:\n");
    DisplayInput(b, n2);
    k = SparseSum(a, b, c, n1, n2);
    c[0].value = k - 1;
    printf("Resultant sparse representation:\n");
    DisplayInput(c, k - 1);
}