/*
Bit-Field and Typedef Keyword : 
o Create a struct named student_info which stores the following: 
o roll number(4-bit), age(8-bit) marks(3-bit) of 15 students.
o address, name as strings 
(try to apply bit-field concept for them
and comment on the output)
then write a Function that prints all the info 
related to each of the 15 student. 
Explain how the processor will deal with each member of
the struct and print the total size of the struct 
with these modifications.
*/
#include <stdio.h>
#include <string.h>

typedef struct {
    unsigned int roll_number: 4;
    unsigned int age        : 8;
    unsigned int marks      : 3;
    char name[15];
    char address[50];
} student_info;

void print_student_info(student_info *student){
    printf("Roll number: %d\n",student -> roll_number);
    printf("Age        : %d\n",student -> age);
    printf("Marks      : %d\n",student -> marks);
    printf("Name       : %s\n",student -> name);
    printf("Address    : %s\n",student -> address);
    printf("-------------------------------------------------------\n");
}

int main(){
    student_info students[15];
    int i;
    printf("The size of the student_info struct: %lu bytes\n", sizeof(student_info));
    for (i = 0; i < 15; i++){
        students[i].roll_number = i+1;
        students[i].age = 18+i;
        students[i].marks = (i%5) + 1;
        sprintf(students[i].name,"Student %d",i +1);
        sprintf(students[i].address,"Address %d",i +1);
    }
    for (i = 0; i < 15; i++) {
        print_student_info(&students[i]);
    }
    return 0;
}
