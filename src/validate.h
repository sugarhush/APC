#ifndef VALIDATE_H
#define VALIDATE_H
#include "types.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function Declarations
int validate_args(char arg1[], char *op, char arg2[]);
int list_initialization(List **head1, List **head2, List **tail1, List **tail2, char op1[], char op2[]);
void print_list(List *head1, List *tail1, List *head2, List *tail2);

#endif
