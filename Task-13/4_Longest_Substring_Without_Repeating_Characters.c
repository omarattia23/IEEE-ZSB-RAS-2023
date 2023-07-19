#include <string.h>
#include <stdio.h>
int lengthOfLongestSubstring(char *s)
{
    int visited[256] = {0};
    int maxLen = 0;
    int currentLen = 0;
    char *start = s;

    while (*s != '\0')
    {
        if (!visited[*s])
        {
            visited[*s] = 1;
            currentLen++;
        }
        else
        {
            // Repeated character found, update maxLen if needed
            if (currentLen > maxLen)
                maxLen = currentLen;

            // Reset visited array and currentLen for the next substring
            memset(visited, 0, sizeof(visited));
            currentLen = 0;
            s = start;
            start++;
        }
        s++;
    }
    // Check the last substring
    if (currentLen > maxLen)
        maxLen = currentLen;

    return maxLen;
}
int main()
{
    // int x0 = lengthOfLongestSubstring("abcabc");
    // printf("%d\n", x0);
    // int x1 = lengthOfLongestSubstring("bbbbbb");
    // printf("%d\n", x1);
    int x2 = lengthOfLongestSubstring("pwwkew");
    printf("%d\n", x2);
    return 0;
}