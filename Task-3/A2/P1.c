/*
Write a program to compare two dates entered by user as strings. 
Make a structure named Date to store the elements day, 
month and year to store the dates. If the dates are equal, 
display "Dates are equal" otherwise display
"Dates are not equal".
*/
#include <stdio.h>
#include <string.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;
// int compareDates(Date date1, Date date2);
int compareDates(Date date1, Date date2) {
    if (date1.year == date2.year && date1.month == date2.month && date1.day == date2.day)
        printf("Dates are equal\n");
    else
        printf("Dates are equal\n");
    printf("--------------------------------------------------------------\n");
    return 0;
}
int main() {
    char dateStr1[11], dateStr2[11];
    Date date1, date2;
    printf("--------------------------------------------------------------\n");
    printf("Enter the first date in the format DD/MM/YYYY : ");
    scanf("%s", dateStr1);
    sscanf(dateStr1, "%d/%d/%d", &date1.day, &date1.month, &date1.year);

    printf("Enter the second date in the format DD/MM/YYYY: ");
    scanf("%s", dateStr2);

    sscanf(dateStr2, "%d/%d/%d", &date2.day, &date2.month, &date2.year);
    printf("--------------------------------------------------------------\n");
    compareDates(date1,date2);
    return 0;
}


