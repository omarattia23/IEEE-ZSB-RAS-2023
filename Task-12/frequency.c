#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main()
{

    char str[1000];
    fgets(str, sizeof(str), stdin);
    int num[10] = {0};
    int length = strlen(str);

    for (int i = 0; i < length; i++)
    {
        if ((int)str[i] >= '0' && (int)str[i] <= '9')
        {
            num[(int)str[i] - '0'] += 1;
        }
    }

    for (int i = 0; i < 10; i++)
        printf("%d ", num[i]);

    return 0;
}