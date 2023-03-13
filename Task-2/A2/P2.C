/*Create an array of int values
and a pointer pointing to this array then print all the
elements of the array using this pointer.
*/
#include <stdio.h>

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int *ptr = arr;
    printf("Array elements:\n");
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
        printf("%d  ", *(ptr + i)); // Print each element using pointer arithmetic.
    return 0;
}
