/*
Write a C code that define 3 int variables x,y and z 
and 5 pointers to integers p,q and r. 
set distinct values to the three variables 
and set the addresses of the variables into the
three pointers then apply the next:
a-Print with labels the values of x, y, z, p, q, r, *p, *
b-Print the message: Swapping pointers.
c-Execute the swap code: r = p; p = q; q = r;
d-Print with labels the values of x, y, z, p, q, r, *p, *
*/
#include <stdio.h>


int main() {
    //variables
    int x = 1;
    int y = 2;
    int z = 3;
    //pointers
    int *a = &x;
    int *b = &y;
    int *c = &z;
    //print
    printf("------------------------------------------");
    printf("\nOriginal Values:\n");
    printf("x = %d, y = %d, z = %d\n", x, y, z);
    printf("a = %p, b = %p, c = %z",(void*)a,(void*)b,(void*)c);
    printf("*a = %d,*b = %d,*c = %d\n",*a,*b,*c);
    printf("------------------------------------------");
    //temperay
    int *temp = c;
    c = a;
    a = b;
    b = temp;
    //Print the new values
    printf("------------------------------------------");
    printf("\nNew values:\n");
    printf("x = %d, y = %d, z = %d\n", x, y, z);
    printf("a = %p, b = %p, c = %z",(void*)a,(void*)b,(void*)c);
    printf("*a = %d,*b = %d,*c = %d\n",*a,*b,*c);
    printf("------------------------------------------");
    return 0;
} 