/*
Write a C code to check the type of the sign representation technique of your compiler
The Code sequence is:
1- Define an unsigned integer variable and assign to it -1
2- print the variable using %u specifier (%u used to print the unsigned values)
3- The printed variable shall be one of the following:
        Ob10000000000000000000000000000001 (Decimal 2147483649)-> Sign Magnitude
        Ob11111111111111111111111111111110 (Decimal 4294967294)-> 1's Complement
        Ob11111111111111111111111111111111 (Decimal 4294967295)-> 2's Complement
*/
#include <stdio.h>


int main() {
    int x = -1;
    printf("%u", x);
    return 0;
}