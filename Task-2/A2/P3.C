/*
Write C program that defines the difference between various C storage classes : 
{ auto, extern, static, register} in terms of : 
Scope, initial value, and lifetime
access.
*/
#include <stdio.h>
int y = 20;
int main() {
    //auto
    int x = 5;
    printf("x=%d\n", x);
    extern int y;  
    printf("The value of y is %d\n", y);  
    
    static int z = 5;  
    z += 1;  
    printf("The value of z is %d\n", z);  
    //register
    int p = 4;  
    int *ptr = &p;  
    printf("The value at address %u is %d\n", ptr, *ptr); 
    return 0;  
}
