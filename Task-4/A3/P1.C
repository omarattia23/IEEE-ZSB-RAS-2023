/*
Create two functions that takes integer inputs 
from the user and stores the input values into an array
then returns the array to be printed 
in the main function.
o One function sorts values in Ascending order 
and the other in Descending order.
o The switch decision between the two Functions depend 
on predefined Macros and #ifdef to control the code flow.
*/
#include <stdio.h>
#include <stdlib.h>

#define ASCENDING_SORT

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    #ifdef ASCENDING_SORT
        // Sort in ascending order
        for (int i = 0; i < size-1; i++) {
            for (int j = 0; j < size-i-1; j++) {
                if (arr[j] > arr[j+1]) {
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
    #else
        // Sort in descending order
        for (int i = 0; i < size-1; i++) {
            for (int j = 0; j < size-i-1; j++) {
                if (arr[j] < arr[j+1]) {
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
    #endif

    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
