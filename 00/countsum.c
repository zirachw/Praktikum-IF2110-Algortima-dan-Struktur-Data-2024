/* File: countsum.c */
/* Tanggal: 20 September 2024 */
/* Oleh: Razi Rachman Widyadhana */
/* NIM: 13523004 */

#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int sum = 0;
    int num;
    int i = 0;

    while (i < n) 
    {
        scanf("%d", &num);
        if (num % k != 0) 
        {
            sum += num;
        }
        i++;
    }

    printf("%d\n", sum);

    return 0;
}
