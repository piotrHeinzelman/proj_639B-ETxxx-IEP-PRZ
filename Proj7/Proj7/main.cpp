#include <random>
#include <time.h>
#include <cstdlib>
#include <stdlib.h>
using namespace std;

/*
Programowanie zima 2021/2022
Zadanie 7 – z funkcjami cz. 1 (0.75 pkt)
1. Tablicę A[w][k] (w, k - stale) wypelnic liczbami losowymi rzeczywistymi z przedzialu
<-X, X>,

zaś tablicę B[w][k] - z przedzialu <D, G> (X, D, G – stale rzeczywiste).

2. Tablicę A wydrukować wierszami z dokladnoscia 1 miejsca po kropce,
tablice B – z dokladnoscia do 2 miejsc.

3. W tablicy A odwrocic kolejnosc elementow (czyli zamienić pierwszy z ostatnim, drugi z
przedostatnim itd.) w wierszach o ujemnej sredniej elementow,

zaś w tablicy B zrobić to samo w wierszach, w których srednia elementow jest mniejsza od (D+G)/2.

4. Ponownie wydrukować obie tablice.
5. Wydrukowac informacje, w ktorej tablicy odwrocono wiecej wierszy (a moze tyle samo).

W programie wykorzystac:
• funkcje, ktora *jakas* tablice wypelnia liczbami losowymi rzeczywistymi zawartymi miedzy dwiema *jakimis* wartosciami
• funkcje, ktora *jakas* tablice podanego typu drukuje wierszami z *jakąś* precyzją (liczba miejsc po kropce)
• funkcje, która dla *jakiejs* tablicy podanego typu odwraca kolejność elementów w tych wierszach, w których srednia elementów jest mniejsza od jakiejs wartosci i zwraca (przez return) liczbe wierszy, w ktorych dokonano takich odwrocen.
UWAGA: slowo *jakis* oznacza parametr funkcji.
*/


const int w=5;
const int k=4;
const double D=10.2;
const double G=8.31;

const double X=-7.1;



double random( double D, double G ){
    double _d;
    double _g;
    if (D>G) { _d=G; _g=D; } else { _d=D; _g=G; }

    return _d + ( rand()/(double)RAND_MAX )*(_g-_d) ;
}

void fillRow( double W[k], double D, double G ){
    //%[flags][width][.precision][length]specifier
    //printf ( " %4.1f " , (k/3.0) );
    for ( int i=0; i<k; i++ ){
        W[i]=random(D,G);
    }
}

void fillTable( double S[w][k] , double D, double G ){
    for (int j=0;j<w;j++) {
        fillRow( S[j],  D,  G );
    }
}

void showTable( double S[w][k], int precission ){
    char str[255]={' ','%','+','7','.','0'+precission%10,'f',' ',0};

    for ( int j=0;j<w;j++){
        for ( int i=0;i<k;i++) {
           printf( str , S[j][i] );
        }
        printf( "%c%c",0x0a,0x0d );
    }
}

double averageRow( double S[k] ){
    double sum=S[0];
    for ( int i=1; i<k; i++ ){
        sum+=S[i];
    }
    return sum/k;
}

void reverseRow( double S[k] ){
    int lastIndex;
    if ( k%2==1) {
        lastIndex=(k-1)/2;
    } else {
        lastIndex=k/2;
    }

    double tmp;
    for (int i=0;i<lastIndex;i++) {
        tmp=S[i];
        S[i]=S[k-1-i];
        S[k-1-i]=tmp;
    }
}


int main(){

    double A[w][k];
    double B[w][k];

    srand(time(0));rand();rand();

    fillTable( A, -X, X );
    fillTable( B, D, G );

    printf( "%s" , "\n\n\n                   Tablica A:\n\n" );
    showTable( A, 1 );

    printf( "%s" , "\n\n\n                   Tablica B:\n\n" );
    showTable( B, 2 );


    int revInA=0;
    int revInB=0;
    double aveDG=(D+G)/2;

    for ( int i=0;i<w;i++) {
        if ( averageRow(A[i])<0 )     { reverseRow(A[i]); revInA++;}
        if ( averageRow(B[i])<aveDG ) { reverseRow(B[i]); revInB++;}
    }

    // Copypasteur Method.
    printf( "\n\n\n%s %i\n\n" , "        Tablica A: reversed row number: ", revInA );
    showTable( A, 1 );

    printf( "\n\n\n%s %i\n\n" , "        Tablica B: reversed row number: ", revInB );
    showTable( B, 2 );


    return NULL;
}
