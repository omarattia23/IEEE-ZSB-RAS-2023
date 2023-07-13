#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char c;
    char s[100];
    char sentance[100];
    scanf("%c", &c);
    getchar();
    scanf("%s", &s);
    getchar();
    fgets(sentance, sizeof(sentance), stdin);
    printf("%c\n", c);
    printf("%s\n", s);
    printf("%s\n", sentance);

    return 0;
}
