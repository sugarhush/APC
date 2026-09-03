#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "types.h"

// Function Declarations
int validate_args(char arg1[], char *op, char arg2[]);
int list_initialization(List **head1, List **head2, List **tail1, List **tail2, char op1[], char op2[]);
void print_list(List *head1, List *tail1, List *head2, List *tail2);

int main(int argc, char **argv)
{
    // Usage: ./a.out <num1> <op> <num2>
    // Example: ./a.out 1593408239 + 9345021885
    if (argc != 4)
    {
        printf("Usage: ./a.out <num1> <op> <num2>\n");
        return FAILURE;
    }

    // Validate arguments
    if (validate_args(argv[1], argv[2], argv[3]) == FAILURE)
    {
        return FAILURE;
    }

    List *head1 = NULL;
    List *tail1 = NULL;
    List *head2 = NULL;
    List *tail2 = NULL;

    // Initialize linked lists
    if (list_initialization(&head1, &head2, &tail1, &tail2, argv[1], argv[3]) == FAILURE)
    {
        printf("ERROR: List initialization failed\n");
        return FAILURE;
    }

    print_list(head1, tail1, head2, tail2);
    return SUCCESS;
}


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
