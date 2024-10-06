/* File: liststatik.c */
/* Tanggal: 30 September 2024 */
/* Oleh: Razi Rachman Widyadhana */
/* NIM: 13523004 */

/* MODUL LIST INTEGER STATIK DENGAN ELEMEN POSITIF */
/* Berisi definisi dan semua primitif pemrosesan list integer statik dengan elemen positif */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori list statik */

#include <stdio.h>
#include "liststatik.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListStatik(ListStatik *l)
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan MARK */
{
   for (int i = IDX_MIN; i < CAPACITY; i++)
   {
      ELMT(*l, i) = MARK;
   }
}


/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListStatik l)
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */  
{
   int nEff = 0;
   while(nEff < CAPACITY && ELMT(l, nEff) != MARK)
   {
      nEff++;
   }
   return nEff;
}

/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListStatik l)
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
{
   return IDX_MIN;
}

IdxType getLastIdx(ListStatik l)
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
{
   return listLength(l) - 1;
}


/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListStatik l, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/
{
   return i >= IDX_MIN && i < CAPACITY;
}

boolean isIdxEff(ListStatik l, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */
{
   return i >= getFirstIdx(l) && i <= getLastIdx(l);
}


/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty(ListStatik l)
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
{
   return ELMT(l, IDX_MIN) == MARK;
}

/* *** Test List penuh *** */
boolean isFull(ListStatik l)
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
{
   return !(ELMT(l, CAPACITY - 1) == MARK);
}


/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readList(ListStatik *l)
/* I.S. l sembarang */
/* F.S. List l terdefinisi */
/* Proses: membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya n */
/*    Pembacaan diulangi sampai didapat n yang benar yaitu 0 <= n <= CAPACITY */
/*    Jika n tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < n <= CAPACITY; Lakukan n kali: 
          Baca elemen mulai dari indeks 0 satu per satu diakhiri enter */
/*    Jika n = 0; hanya terbentuk List kosong */
{
   CreateListStatik(l);
   int len;
   scanf("%d", &len);

   while (len < IDX_MIN || len > CAPACITY)
   {
      scanf("%d", &len);
   }

   for (int i = IDX_MIN; i < len; i++)
   {
      scanf("%d", &ELMT(*l, i));
   }
}

void printList(ListStatik l)
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */
{
   printf("[");
   for (int i = getFirstIdx(l); i <= getLastIdx(l); i++)
   {
      printf("%d", ELMT(l, i));
      if (i != getLastIdx(l))
      {
         printf(",");
      }
   }
   printf("]");
}


/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika List : Penjumlahan, pengurangan, perkalian, ... *** */
ListStatik plusMinusList(ListStatik l1, ListStatik l2, boolean plus)
/* Prekondisi : l1 dan l2 berukuran sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada 
       indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi 
       elemen l2 pada indeks yang sama */
{
   for (int i = getFirstIdx(l1); i <= getLastIdx(l1); i++)
   {
      if (plus)
      {
         ELMT(l1, i) = ELMT(l1, i) + ELMT(l2, i);
      }
      else
      {
         ELMT(l1, i) = ELMT(l1, i) - ELMT(l2, i);
      }
   }
   return l1;
}


/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
boolean isListEqual(ListStatik l1, ListStatik l2)
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2 dan semua 
   elemennya sama */
{
   if (listLength(l1) != listLength(l2))
   {
      return false;
   }
   else
   {
      for (int i = IDX_MIN; i < CAPACITY; i++)
      {
         if (ELMT(l1, i) != ELMT(l2, i))
         {
            return false;
         }
      }
      return true;
   }
}


/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOf(ListStatik l, ElType val)
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */
{
   for (int i = IDX_MIN; i < CAPACITY; i++)
   {
      if (ELMT(l, i) == val)
      {
         return i;
      }
   }
   return IDX_UNDEF;
}

/* ********** NILAI EKSTREM ********** */
void extremeValues(ListStatik l, ElType *max, ElType *min)
/* I.S. List l tidak kosong */
/* F.S. Max berisi nilai terbesar dalam l;
        Min berisi nilai terkecil dalam l */
{
   *max = ELMT(l, getFirstIdx(l));
   *min = ELMT(l, getFirstIdx(l));

   for (int i = getFirstIdx(l) + 1; i <= getLastIdx(l); i++)
   {
      if (*max < ELMT(l, i))
      {
         *max = ELMT(l, i);
      }

      if (*min > ELMT(l, i))
      {
         *min = ELMT(l, i);
      }
   }
}


/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void insertFirst(ListStatik *l, ElType val)
/* Proses: Menambahkan val sebagai elemen pertama List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen pertama l yang baru */
/* *** Menambahkan elemen pada index tertentu *** */
{
   for (int i = listLength(*l); i > IDX_MIN; i--)
   {
      ELMT(*l, i) = ELMT(*l, i - 1);
   }
   ELMT(*l, IDX_MIN) = val;
}

void insertAt(ListStatik *l, ElType val, IdxType idx)
/* Proses: Menambahkan val sebagai elemen pada index idx List */
/* I.S. List l tidak kosong dan tidak penuh, idx merupakan index yang valid di l */
/* F.S. val adalah elemen yang disisipkan pada index idx l */
{
   for (int i = listLength(*l); i > idx; i--)
   {
      ELMT(*l, i) = ELMT(*l, i - 1);
   }
   ELMT(*l, idx) = val;
}

/* *** Menambahkan elemen terakhir *** */
void insertLast(ListStatik *l, ElType val)
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
{
   ELMT(*l, listLength(*l)) = val;
}


/* ********** MENGHAPUS ELEMEN ********** */
/* *** Menghapus elemen pertama *** */
void deleteFirst(ListStatik *l, ElType *val)
/* Proses : Menghapus elemen pertama List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen pertama l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
{
   *val = ELMT(*l, 0);
   for (int i = getFirstIdx(*l); i < getLastIdx(*l); i++) 
   {
      ELMT(*l, i) = ELMT(*l, i + 1);
   }
   ELMT(*l, getLastIdx(*l)) = MARK;
}

/* *** Menghapus elemen pada index tertentu *** */
void deleteAt(ListStatik *l, ElType *val, IdxType idx)
/* Proses : Menghapus elemen pada index idx List */
/* I.S. List tidak kosong, idx adalah index yang valid di l */
/* F.S. val adalah nilai elemen pada index idx l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
{
   *val = ELMT(*l, idx);
   for (int i = idx; i < getLastIdx(*l); i++) 
   {
      ELMT(*l, i) = ELMT(*l, i + 1);
   }
   ELMT(*l, getLastIdx(*l)) = MARK;
}

/* *** Menghapus elemen terakhir *** */
void deleteLast(ListStatik *l, ElType *val)
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
{
   *val = ELMT(*l, getLastIdx(*l));
   ELMT(*l, getLastIdx(*l)) = MARK;
}


/* ********** SORTING ********** */
void sortList(ListStatik *l, boolean asc)
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */
{
    IdxType i, j;
    ElType temp;
    int n = listLength(*l);

    for (i = getFirstIdx(*l); i < getLastIdx(*l); i++) 
    {
        for (j = i + 1; j <= getLastIdx(*l); j++) 
        {
            if (asc) 
            {
                if (ELMT(*l, i) > ELMT(*l, j)) 
                {
                    temp = ELMT(*l, i);
                    ELMT(*l, i) = ELMT(*l, j);
                    ELMT(*l, j) = temp;
                }
            } 

            else 
            {
                if (ELMT(*l, i) < ELMT(*l, j)) 
                {
                    temp = ELMT(*l, i);
                    ELMT(*l, i) = ELMT(*l, j);
                    ELMT(*l, j) = temp;
                }
            }
        }
    }
}