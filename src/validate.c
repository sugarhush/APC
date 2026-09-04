#include "validate.h"

int validate_args(char arg1[], char *op, char arg2[])
{
    // Validate operand 1
    for (int i = 0; arg1[i] != '\0'; i++)
    {
        if (arg1[i] < '0' || arg1[i] > '9')
        {
            printf("ERROR: Invalid first operand\n");
            return FAILURE;
        }
    }

    // Validate operator
    if (strcmp(op, "+") != 0 &&
        strcmp(op, "-") != 0 &&
        strcmp(op, "x") != 0 &&
        strcmp(op, "/") != 0)
    {
        printf("ERROR: Invalid operator\n");
        return FAILURE;
    }

    // Validate operand 2
    for (int i = 0; arg2[i] != '\0'; i++)
    {
        if (arg2[i] < '0' || arg2[i] > '9')
        {
            printf("ERROR: Invalid second operand\n");
            return FAILURE;
        }
    }

    return SUCCESS;
}


int list_initialization(List **head1, List **head2, List **tail1, List **tail2, char op1[], char op2[])
{
    int i = 0;
    // Initialize first operand
    while (op1[i] != '\0')
    {
        List *new_node = malloc(sizeof(List));
        if (new_node == NULL)
        {
            return FAILURE;
        }

        // Store numeric digit instead of ASCII character
        new_node->data = op1[i] - '0';
        new_node->prev = NULL;
        new_node->next = NULL;
        // Empty list
        if (*head1 == NULL)
        {
            *head1 = new_node;
            *tail1 = new_node;
        }
        else
        {
            // Insert at the end
            new_node->prev = *tail1;
            (*tail1)->next = new_node;
            *tail1 = new_node;
        }
        i++;
    }


    int j = 0;
    // Initialize second operand
    while (op2[j] != '\0')
    {
        List *new_node = malloc(sizeof(List));
        if (new_node == NULL)
        {
            return FAILURE;
        }
        // Store numeric digit instead of ASCII character
        new_node->data = op2[j] - '0';
        new_node->prev = NULL;
        new_node->next = NULL;
        // Empty list
        if (*head2 == NULL)
        {
            *head2 = new_node;
            *tail2 = new_node;
        }
        else
        {
            // Insert at the end
            new_node->prev = *tail2;
            (*tail2)->next = new_node;
            *tail2 = new_node;
        }
        j++;
    }

    return SUCCESS;
}


void print_list(List *head1, List *tail1, List *head2, List *tail2)
{
    List *temp;

    // Print first operand
    temp = head1;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    // Print second operand
    temp = head2;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

