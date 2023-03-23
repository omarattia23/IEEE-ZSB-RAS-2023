/*Use typedef keyword to rename all primitive datatypes 
and print the size of each one of them 
with their new name(Try to think of a new naming method 
that helps identifying what datatype does this new
name point to…)
*/
#include <stdio.h>

typedef char byte;     // 1 byte
typedef int integer;   // 4 bytes
typedef float real32;  // 4 bytes
typedef double real64; // 8 bytes

int main() {
    printf("byte    : %lu bytes\n", sizeof(byte));
    printf("integer : %lu bytes\n", sizeof(integer));
    printf("real32  : %lu bytes\n", sizeof(real32));
    printf("real64  : %lu bytes\n", sizeof(real64));
    return 0;
}