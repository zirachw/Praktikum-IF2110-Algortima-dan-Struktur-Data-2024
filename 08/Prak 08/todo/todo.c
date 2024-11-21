/* File : todo.c */
/* Tanggal: 22 November 2024*/
/* Oleh: Razi Rachman Widyadhana */
/* NIM: 13523004 */

#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

int main()
{
    List todo;
    CreateList(&todo);

    char op;
    int target;

    do
    {
        ElType val;
        scanf("%c", &op);

        if (op == 'P')
        {
            scanf(" %d", &val);
            insertFirst(&todo, val);
        }

        else if (op == 'I')
        {
            scanf(" %d", &val);
            insertLast(&todo, val);
        }

        else if (op == 'C')
        {
            if (!isEmpty(todo))
            {
                deleteFirst(&todo, &val);
            }
        }

        else if (op == 'D')
        {
            if (!isEmpty(todo))
            {
                scanf(" %d", &target);

                if (indexOf(todo, target) != IDX_UNDEF)
                {
                    deleteAt(&todo, indexOf(todo, target), &val);
                }
            }
        }
    } while (op != 'X');

    displayList(todo);
    return 0;
}