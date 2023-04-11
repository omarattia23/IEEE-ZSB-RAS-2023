/*Edit the previous program and instead of reallocating one of the memory spaces
just free it and allocate a fourth space with a relatively bigger space 
then comment what this would
do if you had a limited memory space.
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p1, *p2, *p3, *p4;
    int i, n1, n2, n3, n4;

    // Allocate memory using malloc
    n1 = 5;
    p1 = (int*)malloc(n1 * sizeof(int));
    if (p1 == NULL) {
        printf("Error: Could not allocate memory using malloc\n");
        return 1;
    }
    printf("Memory allocated successfully using malloc\n");
    for (i = 0; i < n1; i++) {
        p1[i] = i;
    }
    printf("Values assigned to p1:\n");
    for (i = 0; i < n1; i++) {
        printf("%d ", p1[i]);
    }
    printf("\n");

    // Allocate memory using calloc
    n2 = 7;
    p2 = (int*)calloc(n2, sizeof(int));
    if (p2 == NULL) {
        printf("Error: Could not allocate memory using calloc\n");
        free(p1);
        return 1;
    }
    printf("Memory allocated successfully using calloc\n");
    for (i = 0; i < n2; i++) {
        p2[i] = i*2;
    }
    printf("Values assigned to p2:\n");
    for (i = 0; i < n2; i++) {
        printf("%d ", p2[i]);
    }
    printf("\n");

    // Free memory allocated using malloc
    free(p1);
    printf("Memory freed successfully using free\n");

    // Allocate memory using realloc
    n3 = 3;
    p3 = (int*)realloc(NULL, n3 * sizeof(int));
    if (p3 == NULL) {
        printf("Error: Could not allocate memory using realloc\n");
        free(p2);
        return 1;
    }
    printf("Memory allocated successfully using realloc\n");
    for (i = 0; i < n3; i++) {
        p3[i] = i*3;
    }
    printf("Values assigned to p3:\n");
    for (i = 0; i < n3; i++) {
        printf("%d ", p3[i]);
    }
    printf("\n");

    // Allocate memory with a larger size using calloc
    n4 = 10;
    p4 = (int*)calloc(n4, sizeof(int));
    if (p4 == NULL) {
        printf("Error: Could not allocate memory using calloc\n");
        free(p2);
        free(p3);
        return 1;
    }
    printf("Memory allocated successfully using calloc\n");
    for (i = 0; i < n4; i++) {
        p4[i] = i*4;
    }
    printf("Values assigned to p4:\n");
    for (i = 0; i < n4; i++) {
        printf("%d ", p4[i]);
    }
    printf("\n");

    // Free allocated memory
    free(p2);
    free(p3);
    free(p4);

    return 0;
        

    /*
    what this would do if you had a limited memory space?
    If you have a limited memory space, allocating a relatively larger space 
    can cause the program to fail if there is not enough memory available.
    */
    return 0;
}