/*Create a struct named test that stores the following 
in the same order: 
o Int id 
o String name 
o Char class_id
Now print the size of the struct 
in this case the change the order of definition of the string 
to be the first then print the size again.
Is there any deference? Explain your
answer.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct
struct test {
    int id;
    char name[50];
    char class_id;
};

int main() {
    printf("-----------------------------------------------------------------------------------------\n");
    printf("Size of struct before swapping: %zu bytes\n", sizeof(struct test));
    struct test new_test;
    memset(&new_test, 0, sizeof(new_test));
    printf("Size of struct after swapping : %zu bytes\n", sizeof(new_test));
    printf("-----------------------------------------------------------------------------------------\n");
    printf("Explantation: There's no difference between them because both contain the same three fields.");
    printf("-----------------------------------------------------------------------------------------\n");

    return 0;
}
