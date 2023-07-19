#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isNumber(char *s)
{
    int num = 0;
    int exp = 0;
    int sign = 0;
    int dec = 0;

    while (*s != '\0')
    {
        if (*s >= '0' && *s <= '9')
        {
            num = 1; // Found at least one digit
        }
        else if (*s == 'e' || *s == 'E')
        {
            if (exp || !num)
                return false; // Invalid position of 'e' or 'E' or no digits before 'e' or 'E'
            exp = 1;          // Found exponent symbol
            sign = 0;         // Reset sign flag
            num = 0;          // Reset num flag for digits after 'e' or 'E'
            dec = 0;          // Reset decimal flag for digits after 'e' or 'E'
        }
        else if (*s == '+' || *s == '-')
        {
            if (sign || num || dec)
                return false; // Invalid sign position or multiple signs or signs after digits
            sign = 1;         // Found sign
        }
        else if (*s == '.')
        {
            if (dec || exp)
                return false; // Invalid decimal position or multiple decimals or decimals after 'e' or 'E'
            dec = 1;          // Found decimal
        }
        else
        {
            return false; // Invalid character found (non-digit, non-'e', non-'E', non-sign, non-decimal)
        }

        s++; // Move to the next character
    }

    return num; // Return true if at least one digit found, otherwise return false
}

int main()
{
    printf("%d", isNumber("+6e-1"));
    return 0;
}