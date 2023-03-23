/*Write a C Program to Add Two Complex Numbers 
by Passing Structure to a Function 
and make use of typedefkeyword in your code
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float real;
    float imag;
} complex;

complex add(complex num1, complex num2);

int main() {
    complex num1, num2, result;

    printf("Enter the real and imaginary parts of the first complex number:\n");
    scanf("%f %f", &num1.real, &num1.imag);

    printf("Enter the real and imaginary parts of the second complex number:\n");
    scanf("%f %f", &num2.real, &num2.imag);

    result = add(num1, num2);

    printf("Sum = %.1f + %.1fi\n", result.real, result.imag);

    return 0;
}

complex add(complex num1, complex num2) {
    complex result;

    result.real = num1.real + num2.real;
    result.imag = num1.imag + num2.imag;

    return result;
}
