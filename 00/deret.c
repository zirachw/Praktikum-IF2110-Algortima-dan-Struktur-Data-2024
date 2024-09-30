/* File: deret.c */
/* Tanggal: 20 September 2024 */
/* Oleh: Razi Rachman Widyadhana */
/* NIM: 13523004 */

#include <stdio.h>

int main() 
{
  int a, b, next;
  scanf("%d %d", &a, &b);

  while (a <= b) 
  {
    if (a % 2 == 0) // a habis dibagi 2
    {
        next = a * 2;
    }

    else // {(a % 2 != 0)} 
    {
        next = a + 1;
    }
    
    if (next <= b)
    {
        printf("%d ", a);
    }

    else // {(next > b)}
    {
        printf("%d\n", a);
    }

    a = next;
  }

  return 0;
}
