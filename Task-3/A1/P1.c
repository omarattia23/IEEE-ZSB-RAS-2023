#include <stdio.h>
/*Create a struct named student_info which stores 
the roll number, name, age, address and 
marks of 15 students then 
write a program that prints all the info
related to each of the 15 student.
*/
struct student_info{
    int roll_number;
    char name[50];
    int age;
    char address[50];
};
int main(){
    struct student_info students[15]={
    {0,"Ahmed",21,"zagazig"},
    {1,"Ali",21,"zagazig"},
    {2,"Islam",21,"zagazig"},
    {3,"Atef",21,"zagazig"},
    {4,"Attia",21,"zagazig"},
    {5,"Abdelallah",21,"zagazig"},
    {6,"Abdelhady",21,"zagazig"},
    {7,"Abdelrahman",21,"zagazig"},
    {8,"Ammar",21,"zagazig"},
    {9,"Amr",21,"zagazig"},
    {10,"Omar",21,"zagazig"},
    {11,"Karim",21,"zagazig"},
    {13,"Mohamed",21,"zagazig"},
    {14,"Mina",21,"zagazig"}
    };

    printf("-----------------------------------\n");
    for(int i = 0; i<14; i++)
    {   
        printf("The roll_number    : %d\n",students[i].roll_number);
        printf("The student name   : %s\n",students[i].name);
        printf("The student age    : %d\n",students[i].age);
        printf("The student address: %s\n",students[i].address);
        printf("-----------------------------------\n");
    }
    return 0;
}