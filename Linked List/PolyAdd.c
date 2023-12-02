#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node
{
    int coeff;
    struct node* next;
    int exp;
} nd;

nd* head1, *head2, *head3;
nd *ptr1, *ptr2, *ptr3;


nd* input(nd* head)
{
    char ch;
    printf("Do you wish to add terms y or n\n");
    scanf(" %c", &ch);
    
    while (ch == 'y')
    {
        nd* new_node = (nd*)malloc(sizeof(nd)); 
        printf("Enter coefficient\n");
        scanf("%d", &new_node->coeff);
        printf("Enter exponent\n");
        scanf("%d", &new_node->exp);
        new_node->next = NULL;

        if (head == NULL)
        {
            head = new_node;
        }
        else
        {
            nd* temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = new_node;
        }

        printf("Do you wish to add terms y or n\n");
        scanf(" %c", &ch);
    }
    return head;
}


void display(nd* head)
{
    if (head == NULL)
    {
        printf("No terms\n");
    }
    else
    {
        nd* temp = head;
        printf("%dx^%d ", head->coeff, head->exp);
        temp = temp->next;
        while (temp != NULL)
        {
            printf("+ %dx^%d ", temp->coeff, temp->exp);
            temp = temp->next;
        }
        printf("\n");
    }
}


nd* add_poly(nd* head1, nd* head2)
{
    ptr1 = head1;
    ptr2 = head2;
    ptr3 = head3;

    
    if (head1 == NULL && head2 == NULL)
    {
        printf("Both polynomials have no terms\n");
    }
    else
    {
        while (ptr1 != NULL || ptr2 != NULL) 
        {
            nd* new_node = (nd*)malloc(sizeof(nd));
            new_node->next = NULL;

            if (ptr1 != NULL && ptr2 != NULL) 
            {
                if (ptr1->exp == ptr2->exp)
                {
                    new_node->exp = ptr1->exp;
                    new_node->coeff = ptr1->coeff + ptr2->coeff;
                    ptr1 = ptr1->next;
                    ptr2 = ptr2->next;
                }
                else if (ptr1->exp > ptr2->exp)
                {
                    new_node->exp = ptr1->exp;
                    new_node->coeff = ptr1->coeff;
                    ptr1 = ptr1->next;
                }
                else if (ptr1->exp < ptr2->exp)
                {
                    new_node->exp = ptr2->exp;
                    new_node->coeff = ptr2->coeff;
                    ptr2 = ptr2->next;
                }
            }
            else if (ptr1 != NULL)
            {
                new_node->exp = ptr1->exp;
                new_node->coeff = ptr1->coeff;
                ptr1 = ptr1->next;
            }
            else if (ptr2 != NULL)
            {
                new_node->exp = ptr2->exp;
                new_node->coeff = ptr2->coeff;
                ptr2 = ptr2->next;
            }

            if (head3 == NULL)
            {
                head3 = new_node;
                ptr3 = head3;
            }
            else
            {
                ptr3->next = new_node;
                ptr3 = ptr3->next;
            }
        }
    }

    return head3;
}

// Main function
int main()
{
    printf("Polynomial 1\n");
    head1 = input(head1);
    display(head1);

    printf("Polynomial 2\n");
    head2 = input(head2);
    display(head2);

    head3 = add_poly(head1, head2);
    printf("Result is \n");
    display(head3);

    return 0;
}
