/*For the previous problem, 
write a function that accepts the student_info as an input argument 
and prints the info of the 15 student 
and returns number of students with marks 
less than 12 if the full mark is of 20.
*/
#include <stdio.h>
struct student_info{
    int roll_number;
    char name[50];
    int age;
    char address[50];
    int mark;
};
struct student_info students[15];
int get_student_data(){
    printf("-----------------------------------\n");
    for(int i = 0; i < 15; i++){
        students[i].roll_number = i;
        printf("Enter the student name:\n");
        scanf("%s", &students[i].name);
        printf("Enter the student age:\n");
        scanf("%d", &students[i].age);
        printf("Enter the student address:\n");
        scanf("%s",&students[i].address);
        printf("Enter the student mark:\n");
        scanf("%d", &students[i].mark);
        printf("-----------------------------------\n");

    }
    return 0;
}
int print_students(){
    printf("-----------------------------------\n");
    for(int i = 0; i<15; i++)
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
int count_failed_students() {
    int count = 0;
    for (int i = 0; i < 15; i++) { 
        if (students[i].mark < 12) {
            count++;
        }
    }
    return count;
}

int main(){
    get_student_data();
    print_students();
    int failed_count = count_failed_students();
    printf("Number of students with marks less than 12: %d\n", failed_count);
    return 0;
}