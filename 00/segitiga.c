/* File: segitiga.c */
/* Tanggal: 20 September 2024 */
/* Oleh: Razi Rachman Widyadhana */
/* NIM: 13523004 */

#include <stdio.h>

int main() 
{
  int n, i, j, k;
  scanf("%d", &n);

  for (i = n; i >= 1; i--) // row
  {
    for (j = 1; j <= n-i; j++) // whitespace
    {
      printf(" ");
    }

    for (k = 1; k <= 2*i-1; k++) // segitiga
    {
      printf("*");
    }

    printf("\n");
  }
  
  return 0;
}
