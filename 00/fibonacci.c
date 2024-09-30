/* File: fibonacci.c */
/* Tanggal: 20 September 2024 */
/* Oleh: Razi Rachman Widyadhana */
/* NIM: 13523004 */

#include <stdio.h>

int main() 
{
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);

    if (n == 1) 
    {
        printf("%d\n", a);
        return 0;

    } 

    else if (n == 2) 
    {
        printf("%d\n", b);
        return 0;
    }
    
    else // {(n != 1 && n!= 2)}
    {
        int 
        f1 = a, f2 = b, fn, i = 3;

        while (i <= n) 
        {
            fn = f1 + f2; 
            f1 = f2;       
            f2 = fn;
            i++;
        }

        printf("%d\n", fn);
        return 0;
    }
}
