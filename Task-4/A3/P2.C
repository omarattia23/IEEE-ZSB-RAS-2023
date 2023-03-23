/*
Create two Functions one adds two integer values and the other subtracts them, 
Control the code functionality using same switch concept of previous problem 
and you must implement the two operations with the Macros like functions NOT the regular function
implementation.
*/
#include <stdio.h>

#define ADD(a, b) ((a) + (b))
#define SUBTRACT(a, b) ((a) - (b))

int main() {
    int num1 = 10, num2 = 5;
    int result;
    char operation = '+';

    switch (operation) {
        case '+':
            result = ADD(num1, num2);
            break;
        case '-':
            result = SUBTRACT(num1, num2);
            break;
        default:
            printf("Invalid operation\n");
            return 1;
    }

    printf("Result: %d\n", result);

    return 0;
}
