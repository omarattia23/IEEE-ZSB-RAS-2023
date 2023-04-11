/*
Write a C program to read name input from user 
after asking him the maximum length for it then print the name he entered
and the frequency of the most repeated character on it.
*/
#include <stdio.h>
#include <string.h>

int main() {
    char name[100];
    int maxLength, i, j, count = 0, maxCount = 0;

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter the maximum length of your name: ");
    scanf("%d", &maxLength);

    for (i = 0; i < maxLength; i++) {
        if (name[i] == '\0') {
            break;
        }

        count = 1;

        for (j = i + 1; j < maxLength; j++) {
            if (name[j] == '\0') {
                break;
            }

            if (name[i] == name[j]) {
                count++;
            }
        }

        if (count > maxCount) {
            maxCount = count;
        }
    }

    printf("Your name is: %s\n", name);
    printf("The most repeated character frequency is: %d\n", maxCount);

    return 0;
}
