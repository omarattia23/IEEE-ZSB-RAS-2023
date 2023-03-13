/*
Write a C code that defines a pointer “ptr” 
that points to an integer variable containing HEX value of 3 bytes 
then perform the following operations: *ptr++, *++ptr, ++*ptr 
and print the reason for each output.
*/
#include <stdio.h>
int main(){
    int num = 0x123456;
    int *ptr= &num;

    printf("Value of num: %#X\n", num);
    printf("Before.......\n");
    printf("*ptr: %#X\n", *ptr);
    
    printf("After........\n");
    *ptr++;   // post-increment pointer after dereferencing
    printf("post-increment pointer after dereferencing: 0x%X\n", (*ptr));
    (*++ptr); // pre-increment pointer before dereferencing
    printf("pre-increment pointer before dereferencing: 0x%X\n", (*ptr));
    ++(*ptr); // increment value pointed to by the pointer
    printf("increment value pointed to by the pointer: 0x%X\n", (*ptr));

    

    return 0;
}