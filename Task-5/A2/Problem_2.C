/*
Write a C program to continuously ask the user 
for a string input and prints only the unique characters 
from that string and only stops if the user entered a string containing a Stop code
characters predefined earlier for example”!!”.
*/
#include <stdio.h>
#include <string.h>
int main() {
    char input[100], unique[100];
    int i, j, len, isUnique;
    const char* stopCode = "!!";

    while(1) {
        printf("Enter a string: ");
        scanf("%s", input);
        if (strcmp(input, stopCode) == 0) {
            break;
        }
        len = strlen(input);
        j = 0;
        for (i = 0; i < len; i++) {
            isUnique = 1;
            for (int k = 0; k < j; k++) {
                if (input[i] == unique[k]) {
                    isUnique = 0;
                    break;
                }
            }
            if (isUnique) {
                unique[j] = input[i];
                j++;
            }
        }
        unique[j] = '\0';
        printf("Unique characters in the string: %s\n", unique);
    }
    printf("Stop code entered. Exiting program.\n");
    return 0;
}
