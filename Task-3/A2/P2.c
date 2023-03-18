/*Create a struct named info that stores name and age of a person 
then create an object and a pointer of type info 
then make the pointer pointing to the object 
after that print the name and age stored in
the object BUT using the pointer.
*/
#include <stdio.h>
#include <stdlib.h>

struct info {
    char name[50];
    int age;
};

int main() {
    struct info person = {"Omar", 21};
    struct info *personPtr = &person;
    printf("Name: %s\n", personPtr->name);
    printf("Age: %d\n", personPtr->age);
    return 0;
}
