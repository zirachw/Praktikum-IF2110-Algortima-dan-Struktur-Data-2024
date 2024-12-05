/* File : listrec.c */
/* Tanggal: 3 Desember 2024*/
/* Oleh: Razi Rachman Widyadhana */
/* NIM: 13523004 */

#include <stdio.h>
#include <stdlib.h>
#include "listrec.h"

/* Manajemen Memori */

Address newNode(ElType x)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak NIL, dan misalnya
   menghasilkan p, maka INFO(p)=x, NEXT(p)=NIL */
/* Jika alokasi gagal, mengirimkan NIL */
{
    Address P = (Address)malloc(sizeof(Node));
    if (P != NULL)
    {
        INFO(P) = x;
        NEXT(P) = NULL;
    }
    return P;
}

/* Pemeriksaan Kondisi List */
boolean isEmpty(List l)
/* Mengirimkan true jika l kosong dan false jika l tidak kosong */
{
    return l == NULL;
}

boolean isOneElmt(List l)
/* Mengirimkan true jika l berisi 1 elemen dan false jika > 1 elemen atau kosong */
{
    return !isEmpty(l) && NEXT(l) == NULL;
}

/* Primitif-Primitif Pemrosesan List */
ElType head(List l)
/* Mengirimkan elemen pertama sebuah list l yang tidak kosong */
{
    return INFO(l);
}

List tail(List l)
/* Mengirimkan list l tanpa elemen pertamanya, mungkin mengirimkan list kosong */
{
    return NEXT(l);
}

List konso(List l, ElType e)
/* Mengirimkan list l dengan tambahan e sebagai elemen pertamanya. e dialokasi terlebih dahulu.
   Jika alokasi gagal, mengirimkan l */
{
    Address P = newNode(e);
    if (P != NULL)
    {
        NEXT(P) = l;
        l = P;
    }
    return l;
}

List konsb(List l, ElType e)
/* Mengirimkan list l dengan tambahan e sebagai elemen terakhirnya */
/* e harus dialokasi terlebih dahulu */
/* Jika alokasi e gagal, mengirimkan l */
{
    if (isEmpty(l))
    {
        return konso(l, e);
    }
    else
    {
        NEXT(l) = konsb(tail(l), e);
        return l;
    }
}

List copy(List l)
/* Mengirimkan salinan list Ll (menjadi list baru) */
/* Jika ada alokasi gagal, mengirimkan l */
{
    if (isEmpty(l))
    {
        return NULL;
    }
    else
    {
        return konso(copy(tail(l)), head(l));
    }
}

List concat(List l1, List l2)
/* Mengirimkan salinan hasil konkatenasi list l1 dan l2 (menjadi list baru) */
/* Jika ada alokasi gagal, menghasilkan NIL */
{
    if (isEmpty(l1))
    {
        return copy(l2);
    }
    else
    {
        return konso(concat(tail(l1), l2), head(l1));
    }
}

/* Fungsi dan Prosedur Lain */
int length(List l)
/* Mengirimkan banyaknya elemen list l, mengembalikan 0 jika l kosong */
{
    if (isEmpty(l))
    {
        return 0;
    }
    else
    {
        return 1 + length(tail(l));
    }
}

boolean isMember(List l, ElType x)
/* Mengirimkan true jika x adalah anggota list l dan false jika tidak */
{
    if (isEmpty(l))
    {
        return false;
    }
    else
    {
        if (head(l) == x)
        {
            return true;
        }
        else
        {
            return isMember(tail(l), x);
        }
    }
}

void displayList(List l)
/* I.S. List l mungkin kosong */
/* F.S. Jika list tidak kosong, nilai list dicetak ke bawah */
/*      Dipisahkan dengan newline (\n) dan diakhiri dengan newline */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak:
  1
  20
  30
 */
/* Jika list kosong, tidak menuliskan apa-apa  */
{
    if (!isEmpty(l))
    {
        printf("%d\n", head(l));
        if (NEXT(l) != NULL)
            displayList(tail(l));
    }
    else
        return;
}

/*** Tambahan primitif pemrosesan list ***/
List insertAt(List l, ElType e, int idx)
/* Fungsi untuk menambahkan e sebagai elemen pada posisi/index idx sebuah list l */
{
    if (idx == 0)
    {
        return konso(l, e);
    }
    else
    {
        return konso(insertAt(tail(l), e, idx - 1), head(l));
    }
}

List deleteFirst(List l)
/* Fungsi untuk menghapus elemen pertama sebuah list l */
{
    return tail(l);
}

List deleteAt(List l, int idx)
/* Fungsi untuk menghapus elemen pada posisi/index idx sebuah list l */
{
    if (idx == 0)
    {
        return deleteFirst(l);
    }
    else
    {
        return konso(deleteAt(tail(l), idx - 1), head(l));
    }
}

List deleteLast(List l)
/* Fungsi untuk menghapus elemen terakhir sebuah list l */
{
    int list_length = length(l);
    return deleteAt(l, list_length - 1);
}

/*** Operasi-Operasi Lain ***/
List reverseList(List l)
/* Mengirimkan list baru, list l yang dibalik dengan menyalin semua elemen list.
Semua elemen list baru harus dialokasi */
/* Jika alokasi gagal, hasilnya list kosong */
{
    if (isOneElmt(l))
        return l;
    return konsb(reverseList(tail(l)), head(l));
}

void splitOddEven(List l, List *l1, List *l2)
/* I.S. l mungkin kosong */
/* F.S. Berdasarkan l, dibentuk dua buah list l1 dan l2 */
/* l1 berisi semua elemen l yang genap, sedangkan l2 berisi
semua elemen l yang ganjil; semua dengan urutan yang sama seperti di l */
/* l tidak berubah: Semua elemen l1 dan l2 harus dialokasi */
/* Jika l kosong, maka l1 dan l2 kosong */
{
    if (isEmpty(l))
        return;

    if (head(l) % 2 == 0)
        *l1 = konsb(*l1, head(l));
    else
        *l2 = konsb(*l2, head(l));

    splitOddEven(tail(l), l1, l2);
}

void splitOnX(List l, int x, List *l1, List *l2)
/* I.S. l dan x terdefinisi, l1 dan l2 sembarang. */
/* F.S. l1 berisi semua elemen l yang sebelum indeks ke-x
      l2 berisi semua elemen l setelah indeks ke-x (termasuk indeks ke-x)
*/
{
    if (x == 0)
    {
        *l2 = l;
        return;
    }
    else
    {
        *l1 = konsb(*l1, head(l));
        splitOnX(tail(l), x - 1, l1, l2);
    }
}

ElType getMiddle(List l)
/* I.S. l terdefinisi, mungkin kosong */
/* F.S. Mengembalikan elemen tengah dari List l */
/* Jika jumlah elemen dalam List l ganjil, elemen tengah adalah elemen yang berada di posisi tengah.
   Jika jumlah elemen dalam List l genap, elemen tengah adalah elemen di posisi tengah kedua. */
/* Contoh:
   l = [1, 2, 3, 4, 5]
   elemen tengah = 3

   l = [1, 6, 3, 10]
   elemen tengah = 3 (6 dan 3 berada di tengah, dikembalikan elemen tengah kedua, yaitu 3) */
{
    int length_list = length(l);
    List left = NIL, right = NIL;

    splitOnX(l, length_list / 2, &left, &right);
    return INFO(right);
}