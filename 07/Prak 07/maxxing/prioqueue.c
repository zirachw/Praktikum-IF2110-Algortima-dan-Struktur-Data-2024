/* File : prioqueue.c */
/* Tanggal: 12 November 2024*/
/* Oleh: Razi Rachman Widyadhana */
/* NIM: 13523004 */
/* Definisi ADT Priority Queue terurut mengecil berdasarkan nilai elemen */

#include "prioqueue.h"

/* *** Kreator *** */
void CreatePrioQueue(PrioQueue *pq)
/* I.S. sembarang */
/* F.S. Sebuah pq kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah pq kosong */
{
    IDX_HEAD(*pq) = IDX_UNDEF;
    IDX_TAIL(*pq) = IDX_UNDEF;
}

/* ********* Prototype ********* */
boolean isEmpty(PrioQueue pq)
/* Mengirim true jika pq kosong: lihat definisi di atas */
{
    return (IDX_HEAD(pq) == IDX_UNDEF && IDX_TAIL(pq) == IDX_UNDEF);
}

boolean isFull(PrioQueue pq)
/* Mengirim true jika tabel penampung elemen pq sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/
{
    return (IDX_HEAD(pq) - 1 == IDX_TAIL(pq) || (IDX_TAIL(pq) == 0 && IDX_HEAD(pq) == CAPACITY - 1) || (IDX_HEAD(pq) == 0 && IDX_TAIL(pq) == CAPACITY - 1));
}

int length(PrioQueue pq)
/* Mengirimkan banyaknya elemen prioqueue. Mengirimkan 0 jika pq kosong. */
{
    if (isEmpty(pq))
    {
        return 0;
    }
    if (IDX_HEAD(pq) == IDX_TAIL(pq))
    {
        return 1;
    }
    if (IDX_HEAD(pq) > IDX_TAIL(pq))
    {
        return IDX_TAIL(pq) - IDX_HEAD(pq) + CAPACITY + 1;
    }
    return IDX_TAIL(pq) - IDX_HEAD(pq) + 1;
}

/* *** Primitif Add/Delete *** */
void enqueue(PrioQueue *pq, ElType val)
/* Proses: Menambahkan val pada pq dengan aturan FIFO */
/* I.S. pq mungkin kosong, tabel penampung elemen pq TIDAK penuh */
/* F.S. val disisipkan pada posisi yang sesuai, IDX_TAIL "mundur" dalam buffer melingkar.,
        pq terurut mengecil */
{
    if (isEmpty(*pq))
    {
        IDX_HEAD(*pq) = 0;
        IDX_TAIL(*pq) = 0;
        TAIL(*pq) = val;
    }
    else
    {
        IDX_TAIL(*pq) = (IDX_TAIL(*pq) + 1) % CAPACITY;
        int i = IDX_TAIL(*pq);
        while (i != IDX_HEAD(*pq) && val > (*pq).buffer[(i - 1 + CAPACITY) % CAPACITY])
        {
            (*pq).buffer[i] = (*pq).buffer[(i - 1 + CAPACITY) % CAPACITY];
            i = (i - 1 + CAPACITY) % CAPACITY;
        }
        (*pq).buffer[i] = val;
    }
}
// 0 , 1, 2, 3, 4
// . , 4, 3, 2, 1,
//

void dequeue(PrioQueue *pq, ElType *val)
/* Proses: Menghapus val pada pq dengan aturan FIFO */
/* I.S. pq tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        pq mungkin kosong */
{
    *val = HEAD(*pq);
    if (length(*pq) == 1)
    {
        IDX_HEAD(*pq) = IDX_UNDEF;
        IDX_TAIL(*pq) = IDX_UNDEF;
    }
    else
    {
        if (IDX_HEAD(*pq) == CAPACITY - 1)
        {
            IDX_HEAD(*pq) = 0;
        }
        else
        {
            IDX_HEAD(*pq)
            ++;
        }
    }
}

/* *** Display Queue *** */
void displayPrioQueue(PrioQueue pq)
/* Proses : Menuliskan isi PrioQueue dengan traversal, PrioQueue ditulis di antara kurung
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. pq boleh kosong */
/* F.S. Jika pq tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 30, 20, 1 akan dicetak: [30,20,1] */
/* Jika Queue kosong : menulis [] */
{
    int val;
    int firstLength = length(pq);
    printf("[");
    for (int i = 0; i < firstLength; i++)
    {
        if (i != firstLength - 1)
        {
            printf("%d,", HEAD(pq));
        }
        else
        {
            printf("%d", HEAD(pq));
        }
        if (IDX_HEAD(pq) == CAPACITY - 1)
        {
            IDX_HEAD(pq) = 0;
        }
        else
        {
            IDX_HEAD(pq)
            ++;
        }
    }
    printf("]\n");
}
