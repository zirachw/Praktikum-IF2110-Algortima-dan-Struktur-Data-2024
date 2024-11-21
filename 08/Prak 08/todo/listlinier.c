/* File : listlinier.c */
/* Tanggal: 19 November 2024*/
/* Oleh: Razi Rachman Widyadhana */
/* NIM: 13523004 */

/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* ElType adalah integer */

#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

Address newNode(ElType val)
/* Definisi List : */
/* List kosong : FIRST(l) = NULL */
/* Setiap elemen dengan Address p dapat diacu INFO(p), NEXT(p) */
/* Elemen terakhir list: jika addressnya Last, maka NEXT(Last)=NULL */
{
    Address p = (Address)malloc(sizeof(Node));
    if (p != NULL)
    {
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}


/* PROTOTYPE */


/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
    FIRST(*l) = NULL;
}


/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l)
/* Mengirim true jika list kosong */
{
    return FIRST(l) == NULL;
}


/****************** GETTER SETTER ******************/
ElType getElmt(List l, int idx)
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */
{
    while (idx--)
    {
        l = NEXT(l);
    }
    return INFO(l);
}

void setElmt(List *l, int idx, ElType val)
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */
{
    Address p = *l;
    while (idx--)
    {
        p = NEXT(p);
    }
    INFO(p) = val;
}

int indexOf(List l, ElType val)
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */
{
    int idx = 0;
    while (l != NULL)
    {
        if (INFO(l) == val)
        {
            return idx;
        }
        else
        {
            idx++;
            FIRST(l) = NEXT(l);
        }
    }
    return IDX_UNDEF;
}


/****************** PRIMITIF BERDASARKAN NILAI ******************/


/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val)
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */
{
    Address p = newNode(val);
    if (p != NULL)
    {
        NEXT(p) = *l;
        *l = p;
    }
}

void insertLast(List *l, ElType val)
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    if (isEmpty(*l))
        insertFirst(l, val);
    else
    {
        Address p = newNode(val);
        if (p != NULL)
        {
            Address last = *l;
            while (NEXT(last) != NULL)
            {
                last = NEXT(last);
            }
            NEXT(last) = p;
        }
    }
}

void insertAt(List *l, ElType val, int idx)
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    if (idx == 0)
    {
        insertFirst(l, val);
        return;
    }

    Address p = newNode(val);
    if (p != NULL)
    {
        int ctr = 0;
        Address loc = *l;
        while (ctr < idx - 1)
        {
            ctr++;
            loc = NEXT(loc);
        }
        NEXT(p) = NEXT(loc);
        NEXT(loc) = p;
    }
}


/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val)
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
{
    Address p = *l;
    *val = INFO(p);
    *l = NEXT(p);
    free(p);
}

void deleteLast(List *l, ElType *val)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */
{
    Address p = *l, loc = NULL;
    while (NEXT(p) != NULL)
    {
        loc = p;
        p = NEXT(p);
    }

    if (loc == NULL)
        *l = NULL;
    else
        NEXT(loc) = NULL;

    *val = INFO(p);
    free(p);
}

void deleteAt(List *l, int idx, ElType *val)
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */
{
    if (idx == 0)
        deleteFirst(l, val);
    else
    {
        int ctr = 0;
        Address loc = *l;

        while (ctr < idx - 1)
        {
            ctr++;
            loc = NEXT(loc);
        }

        Address p = NEXT(loc);
        *val = INFO(p);
        NEXT(loc) = NEXT(p);
        free(p);
    }
}


/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    printf("[");

    while (!isEmpty(l))
    {
        printf("%d", INFO(l));

        if (NEXT(l) != NULL)
            printf(",");
        l = NEXT(l);
    }

    printf("]");
}

int length(List l)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
    int cnt = 0;
    while (l != NULL)
    {
        cnt++;
        l = NEXT(l);
    }
    return cnt;
}


/****************** PROSES TERHADAP LIST ******************/
List concat(List l1, List l2)
/* I.S. l1 dan l2 sembarang */
/* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
/* Konkatenasi dua buah list : l1 dan l2    */
/* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
    List l3;
    CreateList(&l3);
    Address p = l1;

    while (p != NULL)
    {
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }

    p = l2;

    while (p != NULL)
    {
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }

    return l3;
}