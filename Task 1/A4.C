/*
Strings :
o Write a program in C to input a string and print it.
o Write a program in C to separate the individual characters from a string.
o Write a program in C to compare two strings without using string library functions.
o Write a program in C to copy one string to another string.
*/
#include <stdio.h>
    void p1(){
        char str[100];
        printf("Enter a string: ");
        fgets(str,sizeof(str),stdin);
        printf("You entered: %s",str);
    }
    void p2(){
        char str[100],ch;
        int i = 0;
        printf("Enter a string: ");
        scanf("%s",str);
        printf("Individual characters: \n");
        while(str[i] != '\0'){
            ch = str[i];
            printf("%c\n", ch);
            i++;
        }
        
    }
    void p3(){
        char str1[100], str2[100];
        int i = 0;
        printf("Enter first String: ");
        scanf("%s", str1);
        printf("Enter second String: ");
        scanf("%s", str2);
        while(str1[i] == str2[i]){
            if (str1[i] == '\0' || str1[i] == '\0')
                break;
            i++;
        }
        if (str1[i] == '\0' && str1[i] == '\0') 
            printf("Strings are equal.");
        else
            printf("Strings are not equal.");
    }
    void p4(){
        char str1[100], str2[100];
        int i = 0;
        printf("Enter first String: ");
        gets(str1);
        for (i = 0; str1[i] != '\0'; i++)
            str2[i] = str1[i];

        printf("\nFirst String: %s\n", str1);
        printf("Second String: %s\n", str1);
    }

int main() {
    p1();
    p2();
    p3();
    p4();
    return 0;
}