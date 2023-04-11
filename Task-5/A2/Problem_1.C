/*
Create a C program that stores an input time of format [hh:mm:ss] 
into a single integer variable then prints the time again out of that variable. 
Note: you should solve it without any string manipulation.
*/
#include <stdio.h>

int main() {
    int time, hours, minutes, seconds;

    printf("Enter the time [hh:mm:ss]: \n");
    scanf("%d:%d:%d", &hours, &minutes, &seconds);

    time = hours * 3600 + minutes * 60 + seconds;

    printf("Time stored in a single integer variable: %d seconds\n", time);

    hours = time / 3600;
    minutes = (time % 3600) / 60;
    seconds = time % 60;

    printf("Time extracted from the integer variable: %02d:%02d:%02d\n", hours, minutes, seconds);

    return 0;
}
