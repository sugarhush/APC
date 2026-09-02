#include "types.h"
#include <stdio.h>
#include <string.h>

//Function Declarations
void validate_args(char arg1[], char* op, char arg2[]);

int main(int argc, char** argv)
{
    //Usage: ./a.out <num1> <op> <num2>
    //eg: ./a.out 1593408239 + 9345021885
    if (argc < 4) {
        printf("Usage: ./a.out <num1> <op> <num2>\n");
        return FAILURE;
    }

    validate_args(argv[1], argv[2], argv[3]);
}

void validate_args(char arg1[], char* op, char arg2[]) {
    // printf("%s %s %s", arg1, op, arg2);
    //argument 1 - operand
    int is_valid=1;
    for (int i=0; i<strlen(arg1); i++) {
        int a1=arg1[i]-'0';
        if (
            !((a1>=0 && a1<=9))
        ) {
            is_valid=0;
            break;
        }
    }

    //argument 2 - operator
    if (
        !(strcmp(op, "+") == 0 || strcmp(op, "-") == 0 || strcmp(op, "x") == 0 || strcmp(op, "/") == 0)
    ) {
        is_valid=0;
    }

    //argument 3 - operand
    for (int i=0; i<strlen(arg2); i++) {
        int a2=arg2[i]-'0';
        if (
            !((a2>=0 && a2<=9))
        ) {
            is_valid=0;
            break;
        }
    }

    if (!is_valid) {
        printf("ERROR: The arguments given are invalid for arithmetic operation\n");
    }

}
