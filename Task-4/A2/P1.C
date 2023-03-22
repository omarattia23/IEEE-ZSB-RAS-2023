/*
Create an enum with members indicating some arithmetic operations like: 
[ +, -, *, /, &, |, ! ] then Implement a calculator 
that takes three inputs from the user: 
{operand1, operand2 ,operation char} and prints the result. 
Note that you have to match the operation value inside the enum
with its corresponding value in ASCI.
*/
#include <stdio.h>
#include <string.h>

enum operations {
    ADD         = '+',
    SUB         = '-',
    MULTIPLY    = '*',
    DEVIDE      = '/',
    LOGICAL_AND = '&',
    LOGICAL_OR  = '|',
    LOGICAL_NOT = '!'
};

int main() {
    int operand1, operand2;
    char operation;
    enum operations op;

    printf("Enter the first operand:\n");
    scanf("%d", &operand1);

    printf("Enter the second operand:\n");
    scanf("%d", &operand2);

    printf("Enter the operation: ( +, -, *, /, &, |, ! )\n");
    scanf(" %c", &operation);

    printf("-----------------------------------\n");

    switch(operation) {
        case '+':
            op = ADD;
            break;
        case '-':
            op = SUB;
            break;
        case '*':
            op = MULTIPLY;
            break;
        case '/':
            op = DEVIDE;
            break;
        case '&':
            op = LOGICAL_AND;
            break;
        case '|':
            op = LOGICAL_OR;
            break;
        case '!':
            op = LOGICAL_NOT;
            break;
        default:
            printf("Invalid operation.\n");
            return 1;
    }

    switch (op) {
        case ADD:
            printf("%d + %d = %d\n", operand1, operand2, operand1 + operand2);
            break;
        case SUB:
            printf("%d - %d = %d\n", operand1, operand2, operand1 - operand2);
            break;
        case MULTIPLY:
            printf("%d * %d = %d\n", operand1, operand2, operand1 * operand2);
            break;
        case DEVIDE:
            if (operand2 == 0) {
                printf("Division by zero is undefined.\n");
                return 1;
            }
            printf("%d / %d = %d\n", operand1, operand2, operand1 / operand2);
            break;
        case LOGICAL_AND:
            printf("%d & %d = %d\n", operand1, operand2, operand1 & operand2);
            break;
        case LOGICAL_OR:
            printf("%d | %d = %d\n", operand1, operand2, operand1 | operand2);
            break;
        case LOGICAL_NOT:
            printf("!%d = %d\n", operand1, !operand1);
            break;
        default:
            printf("Invalid operation.\n");
            return 1;
    }

    return 0;
}
