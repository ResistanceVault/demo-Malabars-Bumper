#include "genesis.h"
#include "quicksort.h"

//------------------------------------------------------
void    inline QSwap (struct QSORT_ENTRY *a, struct QSORT_ENTRY *b)
//------------------------------------------------------
{   
    struct QSORT_ENTRY t = *a;
    *a = *b;
    *b = t;
}

//----------------------------------------
// http://rosettacode.org/wiki/Sorting_algorithms/Quicksort#C
void    QuickSort (u16 n, struct QSORT_ENTRY *a)
//----------------------------------------
{
    int i, j, p;
    if (n < 2)
        return;
    p = a[n / 2].value;
    for (i = 0, j = n - 1;; i++, j--) {
        while (a[i].value < p)
            i++;
        while (p < a[j].value)
            j--;
        if (i >= j)
            break;

        QSwap(&a[i], &a[j]);
    }
    QuickSort(i, a);
    QuickSort(n - i, a + i);
}