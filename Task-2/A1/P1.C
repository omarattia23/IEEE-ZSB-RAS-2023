/*
Write a C code that defines a three pointers p1,p2,p3 of types int, 
char and long long then perform the following:
p1++ , p2 ++ ,p3++ on them.
Then print the reason for each output.
*/
#include <stdio.h>

int main(){
    int  *p1;
    char *p2;
    long long *p3;
    
    printf("Before.....\n");
    printf("p1 points to %d\n", p1);
    printf("p2 points to %d\n", p2);
    printf("p3 points to %d\n", p3);

    p1++;
    p2++;
    p3++;
    
    printf("After.....\n");
    printf("p1 points to %d\t----->\tThe size of of int = '4' bits\n",p1);
    printf("p2 points to %d\t----->\tThe size of of character = '1' bits\n",p2);
    printf("p3 points to %d\t----->\tThe size of of long = '8' bits\n",p3);

    return 0;
}