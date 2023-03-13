/*
Write a C function to increment int value 
and create a pointer to this function 
then pass an int value to the function using the pointer only.
*/
#include<stdio.h>

// function that increments an integer value
void increment(int* num)
{
    *num += 1;
}

int main()
{
    int n1 = 10;
    void (*ptr)(int*) = &increment;
    printf("value before increment : %d\n", n1);
    (*ptr)(&n1);
    printf("value after increment  : %d\n", n1);
    
    return 0;
}
