#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
  int n;
  scanf("%d", &n);
  int size = 2 * n - 1;

  // Complete the code to print the pattern.
  int arr[size][size];
  int start = 0;
  int end = size - 1;
  for (int i = n; i > 0; i--)
  {
    for (int j = start; j <= end; j++)
    {
      for (int k = start; k <= end; k++)
      {
        arr[j][k] = i;
      }
    }
    start++;
    end--;
  }
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
      printf("%d ", arr[i][j]);
    printf("\n");
  }

  return 0;
}
