/*
• Dynamic Memory Allocation:
    o Create a C program that contains 3 different allocated
    memory spaces using (malloc, calloc) and reallocate one of
    them to a different space using(realloc) for each allocation
    indicate if it was allocated successfully or not and then
    comment and print the values that was assigned to these
    memory blocks. ”Don’t forget to free your memory when you
    finish ☺”
*/
/*-----------------------------Notes----------------------------------------
malloc is short name for "Memmory Allocation"

*/
#include <stdio.h>
#include <stdlib.h>
int main(){
    int *ptr1, *ptr2, *ptr3;
    int n1 = 5, n2 =4, n3 =3;

    //allocate memory using malloc 
    ptr1 = (int*)malloc(n1 *sizeof(int));
    if (ptr1 == NULL){
        printf("Memory allocation failed for pointer 1\n");
    }
    else{
        printf("Memory allocation succeeded for pointer 1\n");
    }
    //allocate memory using callouc
    ptr2 = (int*)calloc(n2, sizeof(int));
    if (ptr2 == NULL){
        printf("Memory allocation failed for Pointer 2\n");
    }else{
        printf("Memory allocation succeeded for Pointer 2\n");
    }
    //allocate memory using realloc
    ptr3 = (int*)realloc(ptr1, n3* sizeof(int));
    if (ptr3 == NULL){
        printf("Memory allocation failed for Pointer 3\n");
    }
    else{
        printf("Memory allocation succeeded for Pointer 3\n");
    }
    //--------------------------------------------------------------------
    for (int i = 0; i <n1; i++){
        ptr1[i] = i;
    }
    printf("Values assigned to ptr1:\n");
    for (int i = 0; i <n1; i++)
        printf("%d \t",ptr1[i]);
    printf("\n");
    //--------------------------------------------------------------------
    for (int i = 0; i <n2; i++){
        ptr2[i] = i+5;
    }
    //--------------------------------------------------------------------
    printf("Values assigned to ptr2:\n");
    for (int i = 0; i <n2; i++)
        printf("%d \t",ptr2[i]);
    printf("\n");
    //--------------------------------------------------------------------
    for (int i = 0; i <n3; i++){
        ptr3[i] = i+10;
    }
    printf("Values assigned to ptr3:\n");
    for (int i = 0; i <n3; i++)
        printf("%d \t",ptr3[i]);
    printf("\n");
    //--------------------------------------------------------------------
    //free allocated memory
    free(ptr1);
    free(ptr2);
    free(ptr3);
    return 0;
}
