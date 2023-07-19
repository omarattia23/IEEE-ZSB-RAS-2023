#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*****************************************************************************************/
int lexicographic_sort(const char *a, const char *b)
{
    return strcmp(a, b);
    /* strcmp() returns ==> 0 : if the string is matched
                        ==> 1 : if the first string is greater than the second string
                        ==> -1: if the first string is less than the second string
    */
}
/*****************************************************************************************/
int lexicographic_sort_reverse(const char *a, const char *b)
{
    return strcmp(b, a);
}
/*****************************************************************************************/
int sort_by_number_of_distinct_characters(const char *a, const char *b)
{
    int len_a = strlen(a);
    int len_b = strlen(b);

    int hash_a[26] = {0};
    int hash_b[26] = {0};

    int c1 = 0;
    int c2 = 0;

    for (int i = 0; i < len_a; i++)
        hash_a[a[i] - 'a'] = 1;

    for (int i = 0; i < len_b; i++)
        hash_b[b[i] - 'a'] = 1;
    for (int i = 0; i < 26; i++)
    {
        if (hash_a[i])
            c1++;
        if (hash_b[i])
            c2++;
    }
    if (c1 != c2)
        return c1 > c2;
    else
        return strcmp(a, b) > 0; // returns true of false
}
/*****************************************************************************************/
int sort_by_length(const char *a, const char *b)
{
    if (strlen(a) != strlen(b))
        return strlen(a) > strlen(b);
    else
        return strcmp(a, b) > 0; // returns true of false
}
/*****************************************************************************************/
void string_sort(char **arr, const int len, int (*cmp_func)(const char *a, const char *b))
{
    for (int i = 1; i < len; i++)
    {
        char *p = arr[i];
        int j = i;
        for (; j > 0; j--)
        {
            if ((*cmp_func)(arr[j - 1], p) > 0)
                arr[j] = arr[j - 1];
            else
                break;
        }
        arr[j] = p;
    }
}
/*****************************************************************************************/
int main()
{
    int n;
    scanf("%d", &n);

    char **arr;
    // using malloc() and stores the address of the allocated memory in the pointer arr
    arr = (char **)malloc(n * sizeof(char *));
    /****************************************************************************/
    for (int i = 0; i < n; i++)
    {
        //  It allocates memory for each string to store up to 1024 characters
        // (including the null terminator)
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        // realloc() to reallocate memory for each string,
        // making sure it's not using more memory than required.
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
    /****************************************************************************/
    string_sort(arr, n, lexicographic_sort);
    for (int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");
    /****************************************************************************/
    string_sort(arr, n, lexicographic_sort_reverse);
    for (int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");
    /****************************************************************************/
    string_sort(arr, n, sort_by_length);
    for (int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");
    /****************************************************************************/
    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for (int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");
}