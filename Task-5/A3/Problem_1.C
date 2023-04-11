/*
Implement your own sizeof() function one time with macros 
and the other with inline keyword then mention 
the difference between them and the regular declaration and what is the best use
case for each one of them.
*/
#include <stdio.h>

#define mySizeof(type) (char *)(&type+1)-(char*)(&type)
inline int mySizeofInline(int type) { return (char *)(&type+1)-(char*)(&type); }

int main() {
    int a;
    char b;
    printf("Size of int: %ld\n", mySizeof(a));
    printf("Size of char: %ld\n", mySizeof(b));

    printf("Size of int: %d\n", mySizeofInline(a));
    printf("Size of char: %d\n", mySizeofInline(b));

    return 0;
}
