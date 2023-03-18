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
    int mark;
};
int main(){
    struct student_info students[15]={
    {0,"Ahmed",21,"zagazig",70},
    {1,"Ali",21,"zagazig",75},
    {2,"Islam",21,"zagazig",72},
    {3,"Atef",21,"zagazig",80},
    {4,"Attia",21,"zagazig",77},
    {5,"Abdelallah",21,"zagazig",89},
    {6,"Abdelhady",21,"zagazig",77},
    {7,"Abdelrahman",21,"zagazig",89},
    {8,"Ammar",21,"zagazig",88},
    {9,"Amr",21,"zagazig",88},
    {10,"Omar",21,"zagazig",88},
    {11,"Karim",21,"zagazig",94},
    {13,"Mohamed",21,"zagazig",94},
    {14,"Mina",21,"zagazig",94}
    };

    printf("-----------------------------------\n");
    for(int i = 0; i<14; i++)
    {   
        printf("The roll_number    : %d\n",students[i].roll_number);
        printf("The student name   : %s\n",students[i].name);
        printf("The student age    : %d\n",students[i].age);
        printf("The student address: %s\n",students[i].address);
        printf("The student mark   : %d\n",students[i].mark);
        printf("-----------------------------------\n");
    }
    return 0;
}